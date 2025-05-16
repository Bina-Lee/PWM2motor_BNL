#include <PWM2motor_BNL.h>

// Initialize with direction pins and PWM pins
PWM2motor_BNL motors(2, 3, 10, 4, 5, 11); // A1, A2, pwmA, B1, B2, pwmB

void setup() {
  motors.begin();
}

void loop() {
  motors.setMotorA(150);   // Motor A forward
  motors.setMotorB(-120);  // Motor B backward
  delay(2000);

  motors.allStop();        // Stop both motors
  delay(1000);
}