#pragma once
#ifndef PININTERFACE_H
#define PININTERFACE_H

#include <iostream>
#include <string>
#include "PinState.h"

class PinInterface {
 public:
  PinInterface(PinState* pinState);
  ~PinInterface();
  void analogWrite(int pin, int value);
  void digitalWrite(int pin, int value);
  int analogRead(int pin);
  int digitalRead(int pin);
  std::map<std::string, int> getPinStateMap();

 private:
  PinState* _pinState;
};

#endif
