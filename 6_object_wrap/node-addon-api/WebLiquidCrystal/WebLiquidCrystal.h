
#ifndef WebLiquidCrystal_h
#define WebLiquidCrystal_h

#pragma once
// #include <WebLiquidCrystal.h>
#include "Arduino.h"
#include "Player.h"
class WebLiquidCrystal {
 public:
  WebLiquidCrystal();
  ~WebLiquidCrystal();
  void init();
  void backlight();
  void setCursor(int firstPosition, int secondPosition);
  void print(std::string text);

 private:
  // WebLiquidCrystal _lcd = WebLiquidCrystal( 0x27,20,4 );  // set the LCD
  // address to 0x27 for a 16 chars and 2 line display
};

#endif
