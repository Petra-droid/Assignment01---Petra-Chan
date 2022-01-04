
// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 9; // the number of the pushbutton pin
const int LONG_PRESS_TIME  = 1000; // 1000 milliseconds
#define ONBOARD_LED 2  


// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;
int current_LED = LOW;


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, current_LED);
  Serial.print("If long press detected, LED will light up\n");
  

}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == HIGH && currentState == LOW){        // button is pressed
    pressedTime = millis();
  }
  
  else if(lastState == LOW && currentState == HIGH) { // button is released
    releasedTime = millis();

    long pressDuration = releasedTime - pressedTime;

    if( pressDuration > LONG_PRESS_TIME )
      Serial.println("A long press is detected");
      digitalWrite(ONBOARD_LED, HIGH); //LED light up if long press
      delay(1000);
      digitalWrite(ONBOARD_LED, current_LED); // LED is turned off after 1 second
  }

  // save the the last state
  lastState = currentState;
}
