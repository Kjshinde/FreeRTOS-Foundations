

// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif

// Some string to print
volatile int delay_time = 1000;

// Task handles
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;

//*****************************************************************************
// Tasks

// Task: print to Serial Terminal with lower priority
void startTask1(void *parameter) {
  static int caller_count = 0;
  while (1) {
      caller_count++;
      Serial.print("call counter");
      Serial.print(caller_count);
      Serial.println();
      delay_time = Serial.parseInt();
      Serial.println(delay_time);
      vTaskDelay(100 / portTICK_PERIOD_MS);

  }
}

// Task: print to Serial Terminal with higher priority
void startTask2(void *parameter) {
  while (1) {
    digitalWrite(LED_BUILTIN,HIGH);
    vTaskDelay(delay_time / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN,LOW);
    vTaskDelay(delay_time / portTICK_PERIOD_MS);
    Serial.println("T2");
  }
}

//*****************************************************************************
// Main (runs as its own task with priority 1 on core 1)
 
void setup() {

  // Configure Serial (go slow so we can watch the preemption)
  Serial.begin(300);
  pinMode(LED_BUILTIN,OUTPUT);


 // Task to run forever
  xTaskCreatePinnedToCore(startTask1,
                          "Task 1",
                          1024,
                          NULL,
                          1,
                          &task_1,
                          app_cpu);

  // Task to run once with higher priority
  xTaskCreatePinnedToCore(startTask2,
                          "Task 2",
                          1024,
                          NULL,
                          1,
                          &task_2,
                          app_cpu);
}

void loop() {
  if (Serial.available()){
    vTaskResume(task_1);
  } else {
    vTaskSuspend(task_1);
    
  }

}