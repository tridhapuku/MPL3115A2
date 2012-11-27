#include <inttypes.h>
#include "MPL3115A2.h"
#include "Wire.h"



MPL3115A2Class::MPL3115A2Class()
{
    m_i2c_address = 0x60;
    _p_msb = 0;
    _p_csb = 0;
    _p_lsb = 0;
	_t_msb = 0;
	_t_lsb = 0;

	Wire.begin();
}

void MPL3115A2Class::begin()
{

  SetStatus(STANDBY);
  SetStatus(ACTIVE);
}


void MPL3115A2Class::SetStatus(uint8_t StatMask)
{
  SetStatus(CONTROLREG1, StatMask);
}

void MPL3115A2Class::SetStatus(uint8_t ctrl_register, uint8_t StatMask)
{
  Wire.beginTransmission(m_i2c_address); 
  Wire.send(ctrl_register); 
  Wire.send(StatMask);
  Wire.endTransmission();
}

uint8_t MPL3115A2Class::GetStatus(void)
{
  return(GetStatus(CONTROLREG1));
}

uint8_t MPL3115A2Class::GetStatus(uint8_t ctrl_register)
{
  uint8_t CurrStatus;
  
  Wire.beginTransmission(m_i2c_address); 
  Wire.send(ctrl_register); 
  Wire.endTransmission();

  Wire.requestFrom(m_i2c_address, 1);
  if (Wire.available()) {
	CurrStatus = Wire.receive();
  }
  
  return(CurrStatus); 
}

float MPL3115A2Class::getPressure()
{
    
  
  Wire.beginTransmission(m_i2c_address); 
  Wire.send(0x01);        // Data_PMSB_reg address
  Wire.endTransmission();    //Stop transmission
  
  Wire.requestFrom(m_i2c_address, 3); // "please send me the contents of your first three registers"
   while(Wire.available()==0);
  _p_msb = Wire.receive(); // first received byte stored here
  _p_csb = Wire.receive(); // second received byte stored here
  _p_lsb = Wire.receive(); // third received byte stored here
  
  
  
} 


float MPL3115A2Class::getAlt()
{

}

float MPL3115A2Class::getTemp()
{
  Wire.beginTransmission(m_i2c_address); 
  Wire.send(0x04);        // Data_PMSB_reg address
  Wire.endTransmission();    //Stop transmission
  
  Wire.requestFrom(m_i2c_address, 5); // "please send me the contents of your first three registers"
   while(Wire.available()==0);
   Wire.receive();
   Wire.receive();
   Wire.receive();
  _t_msb = Wire.receive(); // first received byte stored here
  _t_lsb = Wire.receive(); // second received byte stored here
}

void MPL3115A2Class::shutdown()
{
  ;
}

MPL3115A2Class MPL3115A2;