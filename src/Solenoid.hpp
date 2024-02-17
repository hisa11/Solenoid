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
    int16_t pwm0[4] = {0, 0, 0, 0}; // モタドラ1
    int16_t pwm1[4] = {0, 0, 0, 0}; // モダドラ2
    int16_t pwm2[4] = {0, 0, 0, 0}; // モダドラ3
    uint8_t solenoid[8] = {1, 1, 1, 1, 1, 1, 1, 1};
};
#endif
