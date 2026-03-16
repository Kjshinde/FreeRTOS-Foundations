/*date :- March 15 2025
author :- krutyanjay shinde
purpose :- this is just a practice code to blink led */ 

// -------------- macros/global variables --------------------
// techincally we check if the mcu is single core by using #if CONFIG_FREERTOS_UNICORE
// but we know for our mcu  its not true so will just set the cpu core to 1 naually

app_cpu = 0;

// ------------------- function defines -----------------

/* Blink led*/

void blink_led(){

}



void setup() {
  // set baud rate for serial communication
  //default for esp is 115200
  Serial.begin(unsigned long 115200)

  //setup pins 
  pinMode(ledPin)

}

void loop() {
  // put your main code here, to run repeatedly:

}
