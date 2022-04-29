#include "PinInterface.h"

PinInterface::PinInterface(PinState* pinState) : _pinState(pinState) {}
PinInterface::~PinInterface() {}

int PinInterface::analogRead(int pin) {
  return _pinState->getPinState(std::to_string(pin));
}

int PinInterface::digitalRead(int pin) {
  return _pinState->getPinState(std::to_string(pin));
}

void PinInterface::analogWrite(int pin, int value) {
  _pinState->setPinState(std::to_string(pin), value);
}

void PinInterface::digitalWrite(int pin, int value) {
  _pinState->setPinState(std::to_string(pin), value);
}
