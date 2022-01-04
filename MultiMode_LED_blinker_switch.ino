/* 
 *  
 *  LED 
 *  -- IO2
 *  Switch
 *  -- IO9
 *  
 */

#define ONBOARD_LED 2    // LED IO2
#define ONBOARD_SW  9    // Switch IO9

int current_LED = LOW;

byte current_mode = 0;
long lastLED_Activity = 0;
byte current_ButtonState = HIGH;
byte previous_ButtonState = HIGH;

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT);

   digitalWrite(ONBOARD_LED, current_LED);    // turn the LED off by making the voltage LOW  
}

void loop() {
    
    
    // Example 2 - Blink LED every second (1000 ms)
    /*
    digitalWrite(ONBOARD_LED, ((millis() / 1000) % 2 == 0)? LOW: HIGH);
    
    */

        
    // Button Reading portion
    current_ButtonState = digitalRead(ONBOARD_SW);
    
    // Transition from High to Low, Button press instance
    if ((current_ButtonState == LOW) && (previous_ButtonState == HIGH)){
        current_mode = (current_mode >= 3)? 0 : current_mode + 1;

        // Percy: We still want the LED to blink despite not having any button presses, 
        //        so we close the parenthesis (We call block of code) here.
        
    }
        
    if (current_mode == 1) {
      digitalWrite(ONBOARD_LED, ((millis() / 1000) % 2 == 0)? LOW: HIGH);
      Serial.print(current_mode);
      previous_ButtonState = current_ButtonState;
      
      }


    if (current_mode == 2) {
      digitalWrite(ONBOARD_LED, ((millis() / 500) % 2 == 0)? LOW: HIGH); 
      Serial.print(current_mode);
      previous_ButtonState = current_ButtonState;
      }


    if (current_mode == 3) {
      digitalWrite(ONBOARD_LED, ((millis() / 100) % 2 == 0)? LOW: HIGH); 
      Serial.print(current_mode);
      previous_ButtonState = current_ButtonState;
      }


    if (current_mode == 0) {
      // Percy: We need to switch off the LED, so we force current_LED to 0
      //        So either leave it as is (Since no one is changing the variable)
      //        or just set it to low.

      current_LED = 0;
      digitalWrite(ONBOARD_LED, current_LED);
      Serial.print(current_mode);
      previous_ButtonState = current_ButtonState;
      }

} // Percy: Make sure all the paranthesis matches
