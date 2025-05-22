# UART LED Control via USB and Bluetooth
This project demonstrates UART communication on the STM32L4 Nucleo board. It allows users to control an onboard LED by sending character commands over USB (via terminal) or wirelessly through a Bluetooth connection (HC-05 module).

# Features
- UART communication over USB using USART2
- Bluetooth-based UART using HC-05 and USART1
- Control of green LED based on user input
- Command feedback printed back to terminal
- Supports both Termite (PC) and Android Bluetooth Terminal

# Usage
### USB UART
1. Connect STM32 board to your PC via USB.
2. Open Termite terminal at 9600 baud.
3. Send:
   - `'Y'` or `'y'`: Turns ON the green LED.
   - `'N'` or `'n'`: Turns OFF the green LED.
4. Receive status messages confirming action.

### Bluetooth UART
1. Connect HC-05 to STM32:
   - TX → PB6
   - RX → PB7
   - VCC → 3.3V
   - GND → GND
2. Pair HC-05 with your phone or PC (PIN: `1234`).
3. Use a Bluetooth terminal app to send `'Y'` or `'N'`.
4. LED responds accordingly with status messages returned.

