#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else 
static const BaseType_t app_cpu = 1;
#endif

static const int led_pin = LED_BUILTIN;

void toggleLED_HIGH(void *parameter) {
    while(1) {
        Serial.println("HIGH frequency task running - 100ms");
        digitalWrite(led_pin, HIGH);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        digitalWrite(led_pin, LOW);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void toggleLED_LOW(void *parameter) {
    while(1) {
        Serial.println("LOW frequency task running - 1000ms");
        digitalWrite(led_pin, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        digitalWrite(led_pin, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(led_pin, OUTPUT);
    
    xTaskCreatePinnedToCore(
        toggleLED_HIGH,
        "Toggle LED HIGH",
        1024,
        NULL,
        1,          // ← same priority
        NULL,
        app_cpu
    );

    xTaskCreatePinnedToCore(
        toggleLED_LOW,
        "Toggle LED LOW",
        1024,
        NULL,
        1,          // ← same priority = round robin!
        NULL,
        app_cpu
    );
}

void loop() {}
