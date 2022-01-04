/* 
 *  Ex_08 - Arduino Libraries
 *  Printing text to OLED Display
 *  Random color display on Neopixels
 *  
 *  PortExpander
 *  -- Bit 4 - 0 
 *  -- Line sensor Module
 *  -- Bit 7 - 5
 *  -- End Stop switch Module
 *  
 *  NeoPixel
 *  -- IO5
 */
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_SDA 19
#define I2C_SCL 18

#define PEXP_I2CADDR 0x23
#define OLED_I2CAADR 0x3C

#define NEO_PIXEL 5
#define LED_COUNT 3

Adafruit_NeoPixel strip(LED_COUNT, NEO_PIXEL, NEO_GRB + NEO_KHZ800);

uint8_t expanderData;

void I0expanderWrite(byte address, byte _data){
  Wire.beginTransmission(address);
  Wire.write(_data);
  Wire.endTransmission();
  }


uint8_t I0expanderRead(int address){
  uint8_t _data;
  Wire.requestFrom(address, 1);
  if(Wire.available()){
      _data = Wire.read();
    }
    return _data;
  }

void setup() {
    Wire.begin(I2C_SDA, I2C_SCL);    
    Serial.begin(115200); //set up serial library baud rate to 115200
    I0expanderWrite(PEXP_I2CADDR, 0xff);
    
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
    
}

void loop() {
    expanderData = I0expanderRead(PEXP_I2CADDR);
  
    strip.setPixelColor(0, strip.Color( (bitRead(expanderData, 5) == 0)? 255 : 0   ,0,0));
    strip.setPixelColor(1, strip.Color(0, (bitRead(expanderData, 6) == 0)? 255 : 0   ,0));
    strip.setPixelColor(2, strip.Color(0,0, (bitRead(expanderData, 7)== 0)? 255 : 0   ));
    strip.show(); // This sends the updated pixel color to the hardware.
  
    delay(5);
}
                    
                
