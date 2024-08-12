#include <U8g2lib.h>
#include <string.h>
class OledDisplay
{
  private:
      U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI *oled = nullptr;
  public: 
      OledDisplay();
      ~OledDisplay();

      void loadOled();
      void show(const String &value);
      void unloadOled();
      void draw(int x, int y, const String &s);
};