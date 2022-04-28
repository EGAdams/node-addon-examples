#pragma once
#ifndef INPUTS_h
#define INPUTS_h

#include "GameState.h"
#include "PinInterface.h"
#include "RESET.h"
class Inputs {
 public:
  Inputs(Player* player1,
         Player* player2,
         PinInterface* pinInterface,
         GameState* gameState);
  ~Inputs();
  void readReset();
  void readUndoButton();
  int readRotary();
  void readPlayerButtons();

 private:
  PinInterface* _pinInterface;
  GameState* _gameState;
  Reset _reset;
};

#endif
