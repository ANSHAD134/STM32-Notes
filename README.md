<div align="center">

# ⚡ STM32-Notes

### Bare-Metal & HAL-based STM32 Development, Driver Analysis, RTOS Experiments & AVR Fundamentals

![STM32](https://img.shields.io/badge/MCU-STM32F446RE-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![AVR](https://img.shields.io/badge/MCU-AVR-orange?style=for-the-badge)
![FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-informational?style=for-the-badge)
![C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

</div>

---

## 📌 About

This repository is a personal **learning log and project archive** for STM32 (and AVR) embedded systems development — covering everything from **bare-metal register-level driver development** to **HAL-based peripheral programming**, **FreeRTOS**, and core **C programming practice**.

Most STM32 work targets the **STM32F446RE (Nucleo-F446RE)** board, developed using **STM32CubeIDE**.

---

## 📂 Repository Structure

| Folder | Description |
|---|---|
| 🔩 **STM32 codes** | Bare-metal & HAL driver-development programs — LED blink, GPIO, interrupts, PWM, ADC, UART, OLED display, temperature sensing (LM35), and custom register-level drivers |
| 📘 **STM32 Assignment** | Peripheral driver **analysis documents** (GPIO, I2C, SPI, USART) with matching implementation + working demo videos |
| 🧠 **RTOS_Workspace** | **FreeRTOS** based projects — task scheduling & traffic-light simulation |
| 🧪 **Assignment** | Bare-metal driver dev & two-LED control practice projects |
| 🔧 **AVR Assignment** | 15 AVR-based mini projects — LED patterns, servo/DC motor control, PWM, LCD, UART, sensor (BMP280) interfacing, with working demo videos |
| 💡 **Project** | Mini-project: **Power-Aware Embedded System Using Interrupt-Based Wake-Up** (with report PPT, screenshot & working video) |
| 📝 **C Assignment** | 27 core C programming exercises with compiled outputs & screenshots |
| 📄 **Data Sheet** | STM32F446xx microcontroller datasheet |
| 📄 **Reference manual** | RM0390 — STM32F446xx reference manual |

---

## 🛠️ Tech Stack

- **MCUs**: STM32F446RE (Nucleo-64), AVR (ATmega series)
- **Languages**: C, Embedded C
- **IDEs**: STM32CubeIDE, Microchip Studio / Atmel Studio
- **RTOS**: FreeRTOS
- **Peripherals covered**: GPIO, EXTI (Interrupts), UART/USART, I2C, SPI, ADC, PWM (Timers), OLED (SSD1306), LM35 temperature sensor, BMP280

---

## 🎯 Highlights

- ✅ Register-level **bare-metal drivers** built from scratch (no HAL) for GPIO, I2C, SPI, USART
- ✅ Detailed **driver analysis write-ups** explaining peripheral internals
- ✅ **FreeRTOS** task scheduling examples
- ✅ Real hardware **working-video proof** for almost every assignment
- ✅ Parallel **AVR track** covering the same core concepts on 8-bit microcontrollers
- ✅ Mini project combining **low-power design + interrupt-based wake-up**

---

## ⚙️ Getting Started

1. Install **[STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)** (for STM32 projects) and/or **Microchip Studio** (for AVR projects).
2. Clone the repository:
   ```bash
   git clone https://github.com/ANSHAD134/STM32-Notes.git
   ```
3. Open the desired project:
   - STM32: import the folder from **STM32 codes / STM32 Assignment / RTOS_Workspace** as an existing STM32CubeIDE project.
   - AVR: open the `.atsln` file inside any **AVR Assignment** folder in Microchip/Atmel Studio.
4. Build, flash to your Nucleo/AVR board, and check the included **working video** in each folder to compare expected behavior.

---

## 📄 License

Open for personal and educational use. Feel free to fork and learn from these examples. Add a `LICENSE` file (e.g. MIT) if you'd like to make the terms official.

---

<div align="center">

### 🙋 Author
**ANSHAD134** — [GitHub Profile](https://github.com/ANSHAD134)

</div>
