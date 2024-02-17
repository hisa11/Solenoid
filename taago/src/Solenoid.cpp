#include "Solenoid.hpp"

void SolenoidController::run() {
    while (1)
    {
        CANMessage msg0{0xf2, (const uint8_t *)2, 1};            // 左動作
        CANMessage msg3{0xf2, (const uint8_t *)&solenoid[1], 1}; // 右動作

        if (serial.readable())
        {
            char buf;
            serial.read(&buf, sizeof(buf));

            if (buf == 'x') // 左動作
            {
                can.write(msg0);
                printf("Message sent: %d\n", msg0.data[0]);
            }
            if (buf == 'v') // 右停止
            {
                can.write(msg3);
                printf("Message sent: %d\n", msg3.data[0]);
            }

            else if (buf == 'z' || buf == 'Q' || buf == 'A')
            { // 停止
                pwm0[0] = 0;
                pwm0[1] = 0;
                pwm0[2] = 0;
                pwm0[3] = 0;

                pwm1[0] = 0;
                pwm1[1] = 0;
                pwm1[2] = 0;
                pwm1[3] = 0;

                pwm2[3] = 0;
            }
        }

        CANMessage msg10(2, (const uint8_t *)pwm0, 8);
        CANMessage msg11(3, (const uint8_t *)pwm1, 8);
        CANMessage msg12(1, (const uint8_t *)pwm2, 8);

        can.write(msg10);
        can.write(msg11);
        can.write(msg12);

        ThisThread::sleep_for(20ms);
    }
}
