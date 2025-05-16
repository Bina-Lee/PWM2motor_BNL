#include "PWM2motor_BNL.h"

PWM2motor_BNL::PWM2motor_BNL(int motorA1, int motorA2,
                             int motorApwm,
                             int motorB1, int motorB2,
                             int motorBpwm)
    : _A1(motorA1), _A2(motorA2), _pwmA(motorApwm),
      _B1(motorB1), _B2(motorB2), _pwmB(motorBpwm) {}

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