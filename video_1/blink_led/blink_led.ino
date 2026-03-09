// Use only core 1 for demo purposes 
#if CONFIG_FREERTOS_UNIOCRE
static const BaseType_t app_cpu = 0;
#else 
static const BaseType_t app_cpu = 1;
#endif 

//Define Pins
static const int led_pin = LED_BUILTIN;

// also lets see what is LED_BUILTIN pin


// write routine for toogle LED
void toggleLED_H(void* parameters) {
  while(1){
    Serial.println(" toggleLED_H");
    digitalWrite(led_pin, HIGH);
    // delay(5000);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    // digitalWrite(led_pin, LOW);
    // vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

// write routine for toogle LED
void toggleLED_L(void* parameters) {
  while(1){
        Serial.println(" toggleLED_L");
    // digitalWrite(led_pin, HIGH);
    // vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    // vTaskDelay(1000/portTICK_PERIOD_MS);
    vTaskDelay(500/portTICK_PERIOD_MS);

  }
}

void setup() {
  Serial.begin(9600);
  Serial.println(LED_BUILTIN);
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
