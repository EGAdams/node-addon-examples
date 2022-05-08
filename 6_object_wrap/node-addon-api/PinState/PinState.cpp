#include "PinState.h"

PinState::PinState() {}
PinState::~PinState() {}

int PinState::getPinState(std::string pin) {
  return _pin_map[pin];
}

void PinState::setPinState(std::string pin, int state) {
  _pin_map[pin] = state;
}

void PinState::clear() {
  _pin_map.clear();
}

std::map<std::string, int> PinState::getMap() {
  return _pin_map;
}