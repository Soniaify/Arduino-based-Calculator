# Arduino Calculator with 4×4 Keypad and I²C LCD

This project is a simple calculator built with Arduino, a **4×4 matrix keypad**, and a **16×2 I²C LCD display**.  
It performs basic arithmetic operations: addition, subtraction, multiplication, and supports decimal inputs.

---

## Features
- **User Input** via 4×4 matrix keypad
- **LCD Output** with I²C interface for reduced wiring
- **Supported Operations**: `+`, `-`, `*`, decimal `.`
- **Clear Function** (`C` button) to reset
- **Real-time Key Display** on the LCD
- **Simple & Educational** — great for learning Arduino basics

---

## Hardware Requirements
- Arduino Uno / Nano / Mega
- 4×4 Matrix Keypad
- 16×2 LCD Display with I²C Backpack
- Jumper wires
- Breadboard

---

##  Wiring
| Keypad Pin | Arduino Pin |
|------------|-------------|
| R1         | 9           |
| R2         | 8           |
| R3         | 7           |
| R4         | 6           |
| C1         | 5           |
| C2         | 4           |
| C3         | 3           |
| C4         | 2           |

| I²C LCD Pin | Arduino Pin |
|-------------|-------------|
| GND         | GND         |
| VCC         | 5V          |
| SDA         | A4 (Uno/Nano) |
| SCL         | A5 (Uno/Nano) |

*(On Mega: SDA = pin 20, SCL = pin 21)*

---

##  How It Works
1. **User presses keys** on the 4×4 keypad.
2. Arduino reads the key press using the `Keypad` library.
3. Numbers and operators are displayed in real-time on the LCD.
4. Pressing `=` calculates and displays the result.
5. Pressing `C` clears the screen and resets the calculation.

---

## Project Structure
Arduino-calculator/
│── Arduino_calculator.ino

---

##  Setup & Upload
1. Install Arduino IDE and required libraries:
   - **Keypad** by Mark Stanley & Alexander Brevig
   - **LiquidCrystal_I2C** by Frank de Brabander
2. Connect components according to the wiring table above.
3. Open `ArduinoCalculator.ino` in Arduino IDE.
4. Select your board and COM port, then upload.
5. Start pressing keys to use the calculator.

## 📂 Project Structure
