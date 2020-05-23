# Simple-IoT-Application
This simple IoT application is used to aid the user in controlling the I/O operations of the STM32 module. This is done by the help of the ESP8266 module which will run a simple HTTP server as well as a WiFi access point. The real date and time will also be retrieved through it. STM32 then requests the date and time from the RTC module.

Technology Used
  - STM32 Module:
    - STM32L432KC
    - Estimated cost: EGP 125
    - Programmed using MDK-ARM
    - Main function: runs code that receives commands from the ESP8266 module to control the LEDs and retrieve date/time
    - Datasheet: https://datasheetspdf.com/pdf-file/1349053/STMicroelectronics/STM32L432KC/1
  
  - ESP8266 Module:
    - Estimated cost: EGP 135
    - Programmed using Arduino IDE o Main function:
      - will be programed to act as a WiFi Access Point and run a simple HTTP server
      - communicates with the STM32 module using Asynchronous Serial link (using UART)
      - Datasheet: https://www.openimpulse.com/blog/wp-content/uploads/wpsc/downloadables/0A-ESP8266__Datasheet__EN_v4.3.pdf
  
  - RTC Module:
    - DS3231
    - Estimated cost: EGP 50
    - Main Function: works as a clock and sends the STM32 the date/time when requested
    - Datasheet: https://datasheetspdf.com/pdf-file/1081920/MaximIntegrated/DS3231/1
    
System Architecture
  This project follows the client-server architecture. The ESP8266 module is known to run the HTTP server and the web page that the user will be using will act as the client. Client requests may be as follows:
  - Turn on LED on STM32 module 
  - Turn off LED on STM32 module 
  - Send real date from RTC module to STM32 module and then to ESP8266 module
  - Send real time from RTC module to STM32 module and then to ESP8266 module
  
