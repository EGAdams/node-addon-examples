#include "PinInterface.h"

PinInterface::PinInterface(PinState* pinState) : _pinState(pinState) {}
PinInterface::~PinInterface() {}

int PinInterface::analogRead(int pin) {
  int pin_value = _pinState->getPinState(std::to_string(pin));
  std::cout << "analog read pin_value: " << pin_value << std::endl;
  return pin_value;
}

int PinInterface::digitalRead(int pin) {
  int pin_value = _pinState->getPinState(std::to_string(pin));
  std::cout << "digital read pin_value: " << pin_value << std::endl;
  return pin_value;
}

void PinInterface::analogWrite(int pin, int value) {
  _pinState->setPinState(std::to_string(pin), value);
}

void PinInterface::digitalWrite(int pin, int value) {
  // std::cout << "setting pin " << pin << " to " << value << std::endl;
  _pinState->setPinState(std::to_string(pin), value);
}
