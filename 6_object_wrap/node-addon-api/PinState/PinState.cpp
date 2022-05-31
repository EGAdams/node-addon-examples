#include "PinState.h"
#include <fstream>
#include <iostream>

PinState::PinState(std::map<std::string, int>* cpp_interface_pin_map)
    : _pin_map(*cpp_interface_pin_map) {
  std::cout << "Constructing PinState..." << std::endl;
  std::string pin = "38";
  int state = 1;
  _pin_map[pin] = state;
}
PinState::~PinState() {}

int PinState::getPinState(std::string pin) {
  return _pin_map[pin];
}

void PinState::setPinState(std::string pin, int state) {
  _pin_map[pin] = state;
  std::string pin_file_path =
      "C:\\Users\\EG\\Desktop\\2022\\april\\5th_week\\node-addon-examples\\6_"
      "object_wrap\\node-addon-api\\pin_data\\";
  std::ofstream pin_file(
      pin_file_path +
      _translateConstant.get_translated_constant(std::stoi(pin)) + ".txt");
  pin_file << state;
  pin_file.close();
}

void PinState::clear() {
  _pin_map.clear();
}

std::map<std::string, int> PinState::getMap() {
  return _pin_map;
}
