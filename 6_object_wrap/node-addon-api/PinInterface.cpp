#include "PinInterface.h"

PinInterface::PinInterface(PinState pinState) : _pinState(pinState) {}
PinInterface::~PinInterface() {}

int PinInterface::analogRead(int pin) {
  int value = 0;
  return value;
}

int PinInterface::digitalRead(int pin) {
  int value = 0;
  return value;
}

void PinInterface::analogWrite(int pin, int value) {}
void PinInterface::digitalWrite(int pin, int value) {}
