My code and challenge solutions for the [Digi-Key Introduction to RTOS](https://www.youtube.com/watch?v=F321087yYy4&list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz) tutorial series by Shawn Hymel.

## Course Structure
* Part 2: Getting Started with FreeRTOS
* Part 3: Task Scheduling
* Part 4: Memory Management
*(More to be added as I progress)*
EOF

# SETUP

- Install Arduino IDE and set it up to be used with ESP32 feather Huzzah.
- Follow video 2 in the series to setupt the IDE.
- Try upload a blink code

> NOTE :- if you are on linux you would need to give permission to access the USB port for the IDE. 
> To do this add your user to a group which has access to the devices by using 
> `sudo usermod -a -G uucp $USER` {see reference 1}

# Video - 2

## Setting esp32 baud rate
- there is a default baud rate set on esp32 as 115200. It is used by the bootload to report inital diagnostics data. {see reference 1 - section "verify Serial connection"}

# Video - 3
## Challenge code
- Taking user input - Make sure to select `No Line Ending` in serial monitor. Other wise it will read the escape characters like `New Line` and `carriage Return` as `0`.  And the logic will break down. {see reference 2 }
- Extra reading {see reference 3 }

# PLANNING and ROADMAP

# DOCUMENTATION
1. [Establish Serial Connection with ESP32](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/establish-serial-connection.html#establish-serial-connection-with-esp32)
2. [Arduino form question on Serial.parseInt](https://forum.arduino.cc/t/serial-parseint-set-0-error/1145174)
3. [How to read and interprete the value from arduino serial monitor](https://forum.arduino.cc/t/reading-and-using-a-value-from-the-serial-monitor/1080158)