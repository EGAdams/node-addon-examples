#pragma once
//
//
//
#ifndef SERVE_LEDS_h
#define SERVE_LEDS_h

#include "GameState.h"
#include "PinInterface.h"

class ServeLeds {
 public:
  ServeLeds(PinInterface* pinInterface, GameState* gameState);
  ~ServeLeds();
  void updateServeLED();
  void serveSwitch();
  void setGameState(GameState* gameState);

 private:
  GameState* _gameState;
  PinInterface* _pinInterface;
};

#endif
