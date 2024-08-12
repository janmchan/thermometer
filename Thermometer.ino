

#include <Arduino.h>
#include "oleddisplay.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

OledDisplay *oledDisplay;

void setup(void) {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, 0);
  digitalWrite(9, 0);		
  
  oledDisplay = new OledDisplay();
  
  oledDisplay->loadOled();
  
}


#include <math.h>
double Thermister(int rawADC) {
double temp;
temp = log(((10240000/rawADC) - 10000));
temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
return temp - 273.15; //Kelvin to Celcius;
}

void loop(void) {
  double temp = Thermister(analogRead(0));
  Serial.println(temp);
  String message = String(temp) + " Degree C";
  oledDisplay->show(message);
  delay(1000);
}

