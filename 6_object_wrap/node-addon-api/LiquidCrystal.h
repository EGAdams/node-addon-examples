
#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#pragma once
// #include <LiquidCrystal.h>
#include "Arduino.h"
#include "Player.h"
class LiquidCrystal {
 public:
  LiquidCrystal();
  ~LiquidCrystal();
  void init();
  void backlight();
  void setCursor(int firstPosition, int secondPosition);
  void print(std::string text);

 private:
  // LiquidCrystal _lcd = LiquidCrystal( 0x27,20,4 );  // set the LCD address to
  // 0x27 for a 16 chars and 2 line display
};

#endif
