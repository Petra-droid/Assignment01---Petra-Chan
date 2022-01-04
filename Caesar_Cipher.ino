const int KEY = 1;
//const String PLAIN_TEXT = "Hello there!";



void setup() {
  Serial.begin(115200);
//  String PLAIN_TEXT;
//    
//  if(Serial.available()) { //if number of bytes (characters) available for reading
//    PLAIN_TEXT = Serial.readString();
// Not sure how to recieve user input to encrypt and decrypt 

    
  String encryption_result = caesar_cipher_encryption(PLAIN_TEXT, KEY);
  String decryption_result = caesar_cipher_decryption(encryption_result, KEY);
  Serial.print("Plain Text: ");
  Serial.println(PLAIN_TEXT);
  Serial.print("Encryption: ");
  Serial.println(encryption_result);
  Serial.print("Decryption: ");
  Serial.println(decryption_result);
  Serial.println();
}

void loop() {
  
}

String caesar_cipher_encryption(String text, int key) {
  String result = text;
  int transformed_index, char_index, char_ascii;
  for(int i = 0; i < text.length(); i++) {
    char_ascii = (int) text[i];
    char_index = (int) char_ascii % 32;
    
    if(char_ascii != 32) {
      transformed_index = (char_index + key) % 26;
      transformed_index = transformed_index % 26 == 0 ? 26 : transformed_index;
      transformed_index += 96;
      if(char_ascii < 96) transformed_index -= 32;
    } else
      transformed_index = char_ascii;
    result[i] = transformed_index;
  }
  return result;
}

String caesar_cipher_decryption(String text, int key) {
  String result = text;
  int transformed_index, char_index, char_ascii;
  for(int i = 0; i < text.length(); i++) {
    char_ascii = (int) text[i];
    char_index = (int) char_ascii % 32;
    
    if(char_ascii != 32) {
      transformed_index = (char_index - key + 26) % 26;
      transformed_index = transformed_index % 26 == 0 ? 26 : transformed_index;
      transformed_index += 96;
      if(char_ascii < 96) transformed_index -= 32;
    } else
      transformed_index = char_ascii;
    result[i] = transformed_index;
  }
  return result;
}
