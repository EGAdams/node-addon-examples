#pragma once
//
// UNDO.h
//
#ifndef UNDO_h
#define UNDO_h
#include "DigiFunctions.h"
#include "GAME_LEDs.h"
#include "POINT_LEDs.h"
#include "SERVE_LEDs.h"
#include "SET_LEDs.h"

class Undo {
 public:
  Undo(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~Undo();
  void setMode1Undo();
  void memory();
  void mode1Undo();

 private:
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  ServeLeds _serveLeds;
  DigiFunctions _digiFunctions;  // just for the digi writes.
};

#endif
