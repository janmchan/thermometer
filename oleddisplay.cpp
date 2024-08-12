#include "oleddisplay.h"
#include "title.h"
OledDisplay::OledDisplay()
{

}

OledDisplay::~OledDisplay()
{
  delete oled;
  oled = 0;
}

void OledDisplay::loadOled()
{
  if(oled == nullptr)
  {
      oled = new U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI(U8G2_R2, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
  }
  oled->begin();
}

void OledDisplay::unloadOled()
{
  delete oled;
}
int xaxis = 0;
void OledDisplay::show(const String &value)
{
  int yaxis = 24;
  if(xaxis > 128)
  {
    xaxis = 0;
  }
  oled->firstPage();
  do
  {
    //oled->drawXBMP(0, 0, 128, 64, title_bits);
    draw(xaxis, yaxis, value);
    //xaxis++;
    
  } while(oled->nextPage());
  delay(200);
}

void OledDisplay::draw(int x, int y, const String &s)
{
    
      oled->clearBuffer();
      oled->setFont(u8g2_font_adventurer_tf);
      oled->setCursor(x,y);
      oled->print(s);
      oled->sendBuffer();
      
  
}