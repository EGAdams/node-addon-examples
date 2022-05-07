#pragma once
#ifndef UNDO_h
#define UNDO_h
#include "../DIGI_V6_15.h"
#include "../GAME_LEDs.h"
#include "../GameState.h"
#include "../POINT_LEDs.h"
#include "../PinInterface.h"
#include "../SERVE_LEDs.h"
#include "../SET_LEDs.h"

class Undo {
 public:
  Undo(Player* player1,
       Player* player2,
       PinInterface* pinInterface,
       GameState* gameState);
  ~Undo();
  void setMode1Undo();
  void memory();
  void mode1Undo();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  ServeLeds _serveLeds;
};

#endif
