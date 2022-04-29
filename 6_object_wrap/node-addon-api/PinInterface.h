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
  int analogRead(int pin);
  int digitalRead(int pin);
  void digitalWrite(int pin, int value);
  void analogWrite(int pin, int value);

 private:
  PinState* _pinState;
};

#endif
