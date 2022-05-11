#include "PinState.h"
#include <iostream>

PinState::PinState(std::map<std::string, int>* cpp_interface_pin_map)
    : _pin_map(*cpp_interface_pin_map) {
  std::cout << "Constructing PinState..." << std::endl;
  std::string pin = "38";
  int state = 1;
  _pin_map[pin] = state;
  std::cout << "inside PinState::PinState constructor: pin " << pin
            << " is now set to " << _pin_map[pin] << std::endl;
}
PinState::~PinState() {}

int PinState::getPinState(std::string pin) {
  std::cout << "getPinState() returning: " << pin << std::endl;
  return _pin_map[pin];
}

void PinState::setPinState(std::string pin, int state) {
  std::cout << "inside PinState::setPinState: setting pin " << pin << " to "
            << state << std::endl;
  _pin_map[pin] = state;
  std::cout << "inside PinState::setPinState: pin " << pin << " is now set to "
            << _pin_map[pin] << std::endl;
}

void PinState::clear() {
  _pin_map.clear();
}

std::map<std::string, int> PinState::getMap() {
  return _pin_map;
}
