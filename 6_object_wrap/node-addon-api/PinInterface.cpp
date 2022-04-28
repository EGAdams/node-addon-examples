#include "PinInterface.h"

PinInterface::PinInterface(PinState pinState) : _pinState(pinState) {
  std::cout << "PinInterface constructed." << std::endl;
}

int PinInterface::analogRead(int pin) {
  int value = 0;
  return value;
}

int PinInterface::digitalRead(int pin) {
  int value = 0;
  return value;
}

void PinInterface::analogWrite(int pin, int value) {}

PinInterface::~PinInterface() {
  std::cout << "PinInterface destructor called..." << std::endl;
}
