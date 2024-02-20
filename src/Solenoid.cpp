#include "Solenoid.hpp"

void SolenoidController::run() {
    while (1)
    {
        if (serial.readable())
        {
            char buf;
            serial.read(&buf, sizeof(buf));

            if (buf == 'x') // 左動作
            {
                solenoid[2] = 1 ;
                solenoid[1] = 1 ;
            }
            else if (buf == 'v') // 右停止
            {
                solenoid[2] = 2;
                solenoid[1] = 2;
            }
            else if (buf == 'e') // 右停止
            {
                solenoid[0] = 1;
                // solenoid[1] = 2;
            }
            else if (buf == 'd') // 右停止
            {
                solenoid[0] = 2;
                // solenoid[1] = 2;
            }
            else if(buf == 'z'){
                solenoid[1] = 0;
                solenoid[2] = 0;

            }
        }

        // メッセージの作成
        CANMessage msg3(0xf2, (const uint8_t *)&solenoid[0], 8); // solenoidの先頭から8バイトを送信

        // CANMessage msg10(2, (const uint8_t *)pwm0, 8);
        // CANMessage msg11(3, (const uint8_t *)pwm1, 8);
        // CANMessage msg12(1, (const uint8_t *)pwm2, 8);

        // メッセージの送信
        can.write(msg3);
        // can.write(msg11);
        // can.write(msg12);

        ThisThread::sleep_for(20ms);
    }
}
