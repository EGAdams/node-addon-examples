#pragma once
//
//  DigiFunctions.h
//
#ifndef DIGIFUNCTIONS_H
#define DIGIFUNCTIONS_H

#include "GameState.h"
#include "GameTimer.h"
#include "PinState.h"
#include "TranslateConstant.h"
class DigiFunctions {
 public:
  DigiFunctions();
  ~DigiFunctions();
  // void pinMode(int pin, int mode);
  // void setup();
  void loop();
  void digitalWrite(int pin, int mode);
  int digitalRead(int pin);
  int analogRead(int pin);
  void gameDelay(int ms);
  unsigned long millis(int hack);
  void clearPinState();
  void setGameState(GameState* gameState);
  GameState* getGameState() { return _gameState; }

 private:
  GameState* _gameState;
  TranslateConstant _translateConstant;
  PinState _pinState;
};

#endif
