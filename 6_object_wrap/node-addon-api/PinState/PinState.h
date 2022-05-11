#ifndef PINSTATE_H
#define PINSTATE_H

#pragma once
#include <map>
#include <string>
#include "TranslateConstant.h"

class PinState {
 public:
  PinState(std::map<std::string, int>* cpp_interface_pin_map);
  ~PinState();
  void setPinState(std::string pin, int state);
  int getPinState(std::string pin);
  void clear();
  std::map<std::string, int> getMap();

 private:
  std::map<std::string, int> _pin_map;
  TranslateConstant _translateConstant;
};

#endif
