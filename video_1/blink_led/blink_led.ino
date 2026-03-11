// Set which core to use 
#if CONFIG_FREERTOS_UNICORE // not defined for our esp32 feather huzza, as we have two cores
static const BaseType_t app_cpu = 0;
#else 
static const BaseType_t app_cpu = 1;  // we will be using core 1.
#endif 

//Define Pins
static const int led_pin = LED_BUILTIN;


// write routine for toogle LED
void toggleLED_H(void* parameters) {
  while(1){
  // turn on the LED 
  digitalWrite(led_pin,HIGH);
  // Put this task to sleep for 1000ms
  vTaskDelay(1000/portTICK_PERIOD_MS);

  //after comming back make the pin low
  digitalWrite(led_pin,LOW);
  //Put it to sleep for 1000 again
  vTaskDelay(10000/portTICK_PERIOD_MS);
  }
}


// write routine for toogle LED
void toggleLED_L(void* parameters) {
  while(1){
    // turn on the LED 
  digitalWrite(led_pin,HIGH);
  // Put this task to sleep for 1000ms
  vTaskDelay(200/portTICK_PERIOD_MS);

  //after comming back make the pin low
  digitalWrite(led_pin,LOW);
  //Put it to sleep for 1000 again
  vTaskDelay(200/portTICK_PERIOD_MS);
  }

}

void setup() {
  // set up the basud rate
  Serial.begin(115200);
  // print all the setup variables

  Serial.println("--------------- Start user variable pritns -------------------"); // this won't work as its not defined for our esp32 (keep for reference)


  Serial.println("The unicore is configured to :- "); // this won't work as its not defined for our esp32 (keep for reference)
  // Serial.println(CONFIG_FREERTOS_UNICORE);
  Serial.println("LED BUILTIN is defined as :- ");
  Serial.println(LED_BUILTIN);
  Serial.println("cpu core used is :-");
  Serial.println(app_cpu);

  // put your setup code here, to run once:
  pinMode (led_pin, OUTPUT);

  xTaskCreatePinnedToCore(
    toggleLED_H,
    "Toggle LED HIGH",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );

  xTaskCreatePinnedToCore(
  toggleLED_L,
  "Toggle LED LOW",
  1024,
  NULL,
  1,
  NULL,
  app_cpu
  );
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
