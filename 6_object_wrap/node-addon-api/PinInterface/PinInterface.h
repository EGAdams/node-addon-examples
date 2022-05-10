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
  void pinAnalogWrite(int pin, int value);
  void pinDigitalWrite(int pin, int value);
  int pinAnalogRead(int pin);
  int pinDigitalRead(int pin);
  std::map<std::string, int> getPinStateMap();

 private:
  PinState* _pinState;
};

#endif
