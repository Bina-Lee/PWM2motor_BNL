#ifndef PWM2MOTOR_BNL_H
#define PWM2MOTOR_BNL_H

#include <Arduino.h>

class PWM2motor_BNL{
    public:
        PWM2motor_BNL(int A1, int A2,
                    int pwmA,
                    int B1, int B2,
                    int pwmB);
        void begin();
        void setMotorA(int value);
        void setMotorB(int value);
        void setMotor(int valueA, int valueB);
    private:
        const int _A1;
        const int _A2
        const int _pwmA;
        const int _B1;
        const int _B2
        const int _pwmB;
        int _pwmA_value = 0;
        int _pwmB_value = 0;
};

#endif