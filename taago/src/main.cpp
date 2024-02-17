#include "mbed.h"
#include "Solenoid.hpp"

BufferedSerial pc(USBTX, USBRX, 250000); // パソコンとのシリアル通信
CAN can1(PA_11, PA_12, (int)1e6);

int main()
{
    SolenoidController solenoidController(can1, pc);
    solenoidController.run();
}
