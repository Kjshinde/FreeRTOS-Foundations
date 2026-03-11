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

# Video - 1 

## Setting esp32 baud rate
- there is a default baud rate set on esp32 as 115200. It is used by the bootload to report inital diagnostics data. {see reference 1 - section "verify Serial connection"}



# PLANNING and ROADMAP

# DOCUMENTATION
1. [Establish Serial Connection with ESP32](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/establish-serial-connection.html#establish-serial-connection-with-esp32)
