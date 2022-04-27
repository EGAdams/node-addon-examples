#pragma once
//
//
//
#ifndef INPUTS_h
#define INPUTS_h

#include "GameState.h"
#include "RESET.h"
// #include "Serial.h"
class DigiFunctions;
class Inputs {
 public:
  Inputs(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~Inputs();
  void readReset();
  void readUndoButton();
  int readRotary();
  void readPlayerButtons();

 private:
  GameState* _gameState;
  DigiFunctions* _digiFunctions;
  Reset _reset;
};

#endif
