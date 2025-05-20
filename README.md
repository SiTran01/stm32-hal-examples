# 📦 stm32-hal-examples

A curated collection of STM32 example projects using the STM32 HAL (Hardware Abstraction Layer) library.  
This repository is intended for learning, testing, and rapid prototyping on STM32 microcontrollers.

## 📚 Contents

The examples are organized by feature/module:

- `ADC/` – Single and multiple channel analog-to-digital conversion
- `BLINK_LED_1/` – Basic LED blinking using GPIO
- `BUTTON_LED/` – Read button input and control an LED
- `BUTTON_EXTI/` – External interrupts with push button
- `DHT_test/` – Interface with DHT11/DHT22 sensors
- `DS_RTC/` – Real-time clock with DS1307/DS3231 (with alarm, EEPROM, temp, etc.)
- `IHC_SR04/` – HC-SR04 ultrasonic distance sensor
- `I2C_LCD/` – I2C 16x2 LCD display
- `LCD_16_2/` – Parallel 16x2 LCD
- `TIMER_PWM/` – Generate PWM using timers
- `TIMER_IC-OC/` – Input capture & output compare
- `TIMER_x/` – General timer examples (Timer2, 3, 4, 5)
- `SYSTEM_TICK/` – Using SysTick for timing
- `STM32_HAL_LIB/` – Custom reusable HAL-based libraries
- `lalalland/` – (Fun test projects or personal experiments)

## 📁 Folder Structure

Each folder contains:
- Source code (`Core/Src`)
- Header files (`Core/Inc`)
- STM32CubeMX `.ioc` project file
- Buildable using STM32CubeIDE

## ⚙️ Requirements

- STM32CubeIDE (recommended)
- STM32 HAL drivers
- STM32 development board (e.g., STM32F1/F4 series)

## 🚀 Getting Started

1. Clone the repository
2. Open the `.ioc` file with STM32CubeIDE
3. Build and flash to your STM32 board
4. Modify and experiment as needed!

## 💡 Notes

- Projects follow STM32CubeMX auto-generated structure
- Code is written in standard C using STM32 HAL API
- Each example is kept simple and focused for learning

## 📜 License

This repository is open-source under the MIT License.

---

Happy hacking! 🚀
