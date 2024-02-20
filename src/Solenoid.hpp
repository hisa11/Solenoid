#ifndef SOLENOID_HPP
#define SOLENOID_HPP

#include "mbed.h"

class SolenoidController {
public:
    SolenoidController(CAN& can, BufferedSerial& serial) : can(can), serial(serial) {}

    void run();

private:
    CAN& can;
    BufferedSerial& serial;
    
    uint8_t solenoid[8] = {0,0,0,0,0,0,0,0};
};
#endif
