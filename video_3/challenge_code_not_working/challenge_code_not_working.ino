/**
 * FreeRTOS challenge fro video 3
 * 
 * Take user input as blink time 
 * 
 * Date: March 15, 2026
 * Author: Shawn Hymel
 * License: 0BSD
 */

// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif


// ----global vairables -----
 int user_inp_time = 1000; 
static const int led_pin = LED_BUILTIN;

// -- creating tasks -------

//take user inpu
void take_user_input(void* parameters){
  Serial.println("#1");
  while(1){
    Serial.println("#2");
    // Serial.println("Running task 1");

    if(Serial.available()>0){
      // Serial.print("Provide sleep time for mcu led :");
     Serial.println("#3");
      user_inp_time = Serial.parseInt();
      Serial.println(user_inp_time);
      vTaskDelay(100/portTICK_PERIOD_MS);
      
      // Serial.println();
    } else {
      Serial.println("#4else");
      vTaskDelay(1000/portTICK_PERIOD_MS);
    }

    // vTaskDelay(5000/portTICK_PERIOD_MS);
  }
}

// blink the led
void blink_led (void* parameters){
  while(1){
    // Serial.println("Running task 2");
    // Serial.print("Task 2 sees delay of");
    // check if the variable is therestatic
    // Serial.print(user_inp_time);
    digitalWrite(led_pin, HIGH);
    vTaskDelay(user_inp_time/portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(user_inp_time/portTICK_PERIOD_MS);
  }

}

void setup(){

  //setup serial communication
  Serial.begin(300);

  //set led pin as output
  pinMode(led_pin,OUTPUT);

  //creating the taksks

  //higher piroprty task of userinput
  xTaskCreatePinnedToCore(take_user_input, //function name 
                           "Take dealy time from user", //function description
                            1024, //stack size
                            NULL,
                            2, //Priority of task 
                            NULL, //handle of the task
                            app_cpu // which cpu to run on
                            );

//lower priority task
  xTaskCreatePinnedToCore(blink_led, //username
                           "Blink the builtin led", //function description
                            1024, //stack size
                            NULL,
                            1, //Priority of task 
                            NULL, //handle of the task
                            app_cpu // which cpu to run on
                            );
}

void loop(){

  // if I don't use loop then 

  // // check if serial data is available 
  // if(Serial.available()>0){
  //   //accept the user input
  //   user_inp_time = Serial.read()
  //   // resume 
  // }
  // vTaskSuspend(taks2);


}