
#ifndef LiquidCrystal_I2C_h
#define LiquidCrystal_I2C_h

#pragma once
#include <string>
#include "Player.h"

class LiquidCrystal_I2C {
 public:
  LiquidCrystal_I2C();
  ~LiquidCrystal_I2C();
  void init();
  void backlight();
  void setCursor(int firstPosition, int secondPosition);
  void print(std::string text);

 private:
};

#endif
