void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //set up serial library baud rate to 115200
  delay(1000);
  
  int i = 3, c;

  Serial.print("Here are the first 30 prime numbers:\n");

  for (int count = 2; count <=30;)
  {
    for (c = 2; c <= i - 1; c++)
    {
      if (i%c == 0)
      break;
    }
    if (c == i)
    {
      Serial.print(i);
      Serial.print("\n");
      count++;
    }
    
    i++;
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:



}
