#pragma once
#ifndef SERVE_LEDS_h
#define SERVE_LEDS_h

#include "Arduino.h"
#include "GameState.h"
#include "PinInterface.h"
class ServeLeds {
 public:
  ServeLeds(PinInterface* pinInterface, GameState* gameState);
  ~ServeLeds();
  void updateServeLED();
  void serveSwitch();

 private:
  PinInterface* _pinInterface;
  GameState* _gameState;
};

#endif
