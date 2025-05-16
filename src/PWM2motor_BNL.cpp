#include "PWM2motor_BNL.h"

PWM2motor_BNL::PWM2motor_BNL(int A1, int A2,
                            int pwmA,
                            int B1, int B2,
                            int pwmB)
    : _A1(A1), _A2(A2), _pwmA(pwmA),
      _B1(B1), _B2(B2), _pwmB(pwmB) {}

void PWM2motor_BNL::begin() {
    pinMode(_A1, OUTPUT);
    pinMode(_A2, OUTPUT);
    pinMode(_pwmA, OUTPUT);
    pinMode(_B1, OUTPUT);
    pinMode(_B2, OUTPUT);
    pinMode(_pwmB, OUTPUT);
    allStop();
}

void PWM2motor_BNL::allStop() {
    digitalWrite(_A1, LOW);
    digitalWrite(_A2, LOW);
    digitalWrite(_B1, LOW);
    digitalWrite(_B2, LOW);
    analogWrite(_pwmA, 0);
    analogWrite(_pwmB, 0);
}

void PWM2motor_BNL::setMotorA(int value) {
    if (value > 0) {
        digitalWrite(_A1, HIGH);
        digitalWrite(_A2, LOW);
        _pwmA_value = value;
    } else if (value < 0) {
        digitalWrite(_A1, LOW);
        digitalWrite(_A2, HIGH);
        _pwmA_value = -value;
    } else {
        digitalWrite(_A1, LOW);
        digitalWrite(_A2, LOW);
        _pwmA_value = 0;
    }
    analogWrite(_pwmA, _pwmA_value);
}

void PWM2motor_BNL::setMotorB(int value) {
    if (value > 0) {
        digitalWrite(_B1, HIGH);
        digitalWrite(_B2, LOW);
        _pwmB_value = value;
    } else if (value < 0) {
        digitalWrite(_B1, LOW);
        digitalWrite(_B2, HIGH);
        _pwmB_value = -value;
    } else {
        digitalWrite(_B1, LOW);
        digitalWrite(_B2, LOW);
        _pwmB_value = 0;
    }
    analogWrite(_pwmB, _pwmB_value);
}

void PWM2motor_BNL::setMotor(int valueA, int valueB) {
    setMotorA(valueA);
    setMotorB(valueB);
}