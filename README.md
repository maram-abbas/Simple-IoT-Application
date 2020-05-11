# Simple-IoT-Application
This project's aim is to utilize the ESP8266 module to create a small IoT application that can enable the user to perform I/O operations with the STM32 module through a web interface.

Technology Used
  - STM32 Module:
    - STM32L432KC
    - Estimated cost: EGP 125
    - Programmed using MDK-ARM
    - Main function: runs code that receives commands from the ESP8266 module to control the LEDs
    - Datasheet: https://datasheetspdf.com/pdf-file/1349053/STMicroelectronics/STM32L432KC/1
  
ESP8266 Module:
  - Estimated cost: EGP 135
  - Programmed using Arduino IDE o Main function:
    - will be programed to act as a WiFi Access Point and run a simple HTTP server
    - communicates with the STM32 module using Asynchronous Serial link (using UART)
    - Datasheet: https://www.openimpulse.com/blog/wp-content/uploads/wpsc/downloadables/0A-ESP8266__Datasheet__EN_v4.3.pdf
