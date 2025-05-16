# PWM2motor_BNL

A library for Arduino/MCU to control dual DC motors using 6 GPIO pins (4 digital + 2 PWM)

This Arduino library provides a simple and efficient interface for controlling two DC motors using a typical dual H-bridge motor driver (such as L298N or similar).  
It uses **6 control pins**:
- **4 digital output pins** for motor direction (IN1, IN2, IN3, IN4)
- **2 PWM output pins** for speed control (PWM A and PWM B)

Designed for small microcontrollers like **Arduino Nano**, this library minimizes complexity while offering full motor control functionality.

---

## 🛠️ Features

- ✅ Independent control of two motors (direction & speed)
- ✅ Simple initialization via `begin()`
- ✅ Accepts positive and negative values for forward/reverse motion
- ✅ `allStop()` function for immediate halt
- ✅ Optimized for compact robot and mobility projects

---

## 🧰 Pin Configuration

| Pin Type      | Description                        | Quantity |
|---------------|------------------------------------|----------|
| Digital OUT   | Motor direction (A1, A2, B1, B2)   | 4        |
| PWM OUT       | Motor speed control (PWM A, PWM B) | 2        |
| **Total**     |                                    | **6**    |

---

## 📦 Installation

1. Download or clone this repository.
2. Copy the `PWM2motor_BNL` folder into your Arduino `libraries` directory.
3. Restart the Arduino IDE.

---

## 🚀 Example Usage

```cpp
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
```

## 🧾 API Reference

### `PWM2motor_BNL(int A1, int A2, int pwmA, int B1, int B2, int pwmB)`
**Constructor**  
Initializes the motor controller with pin assignments:
- `A1`, `A2`: Direction control pins for Motor A  
- `pwmA`: PWM speed control pin for Motor A  
- `B1`, `B2`: Direction control pins for Motor B  
- `pwmB`: PWM speed control pin for Motor B  

```cpp
PWM2motor_BNL motors(2, 3, 10, 4, 5, 11);
```
---

### `void begin()`
Initializes all specified pins as `OUTPUT` and stops both motors.

#### Example
```cpp
motors.begin();
```

---

### `void setMotorA(int value)/setMotorB`
Controls Motor A's speed and direction.

- `value > 0`: Move forward  
- `value < 0`: Move backward  
- `value == 0`: Stop motor  

#### Example
```cpp
motors.setMotorA(150);   // Forward
motors.setMotorA(-100);  // Reverse
motors.setMotorA(0);     // Stop
```

---

### `void setMotor(int valueA, int valueB)`
Controls both Motor A and Motor B simultaneously.

#### Example
```cpp
motors.setMotor(150, -100); // A forward, B reverse
```

---

### `void allStop()`
Stops both motors by setting direction pins to LOW and PWM to 0.

#### Example
```cpp
motors.allStop();
```