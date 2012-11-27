#ifndef MPL3115A2_h
#define MPL3115A2_h

#include <inttypes.h>
#include <Wire.h>

#define CONTROLREG1 0x26
#define CONTROLREG2 0x27
#define CONTROLREG3 0x28
#define CONTROLREG4 0x29
#define CONTROLREG5 0x2A
#define PT_DATA_CFG 0x13
#define DR_STATUS 0x00
#define F_SETUP 0x0F
#define F_STATUS 0x00
#define F_DATA 0x0E

#define STANDBY	0x00
#define ACTIVE 0x01
#define ALTMODE 0x80
#define BARMODE 0x7F

class MPL3115A2Class{
public:
  MPL3115A2Class(); 
  void begin();
  float getPressure();
  float getAlt();
  float getTemp();
  void shutdown();
  uint8_t GetStatus(void);
  uint8_t GetStatus(uint8_t ctrl_register);
  void SetStatus(uint8_t StatusMask);
  void SetStatus(uint8_t ctrl_register, uint8_t StatusMask);
  uint8_t _p_msb, _p_csb, _p_lsb, _t_msb, _t_lsb;
private:
  int m_i2c_address;
  
};

extern MPL3115A2Class MPL3115A2;

#endif 
