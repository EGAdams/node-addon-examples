#ifndef PINSTATE_H
#define PINSTATE_H

#pragma once
#include <map>
#include <string>
typedef struct {
  int key;
  std::string value;
} constantDictionary;

class PinState {
 public:
  PinState();
  ~PinState();
  void setPinState(std::string pin, int state);
  int getPinState(std::string pin);
  void clear();
  std::map<std::string, int> getMap();

 private:
  std::map<std::string, int> _pin_map;
};

#endif
