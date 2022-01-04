/* 
 *  Task 01 
 *  Checking USER'S BMI
 *  The code is working properly as I wasn't sure how to take 2 inputs 
 * 
 */

 
 int height, weight, BMI; 

 void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.print("Welcome! Let's check your BMI!\n");
    Serial.println("What is your height?\n");
  }

  void loop(){
    if(Serial.available()){
      Serial.print("Your height is: ");
      height = Serial.read();
      Serial.println(height);
    

      Serial.println("What is your weight?\n ");


      Serial.print("Your Weight is: ");
      weight = Serial.read();
      Serial.println(weight);

      BMI = ((weight*703) / (height * height));

      if (BMI < 16 ){
        Serial.println("Severely Underweight");
        }

      if (16 <= BMI <= 18.4){
        Serial.println("Underweight");
        }

      if (18.5 <= BMI <= 24.9){
        Serial.println("Normal");
        }

      if (25.0 <= BMI <= 29.9){
        Serial.println("Overweight");
        }

      if (30 <= BMI <= 34.9){
        Serial.println("Moderately Obese");
        }

      if (35.0 <= BMI <= 39.9){
        Serial.println("Severely Obese");
        }

      if (BMI >= 40 ){
        Serial.println("Morbidly Obese");
        }




        
        }
    
    
    }
