#pragma once
//
//
//
#ifndef RESET_h
#define RESET_h

#include "DigiFunctions.h"
#include "GameState.h"
// #include "Serial.h"
#include "Player.h"

class Reset {
 public:
  Reset(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~Reset();
  void resetScoreboard();
  void resetPreviousValues();
  void refresh();
  void tieLEDsOn();
  void tieLEDsOff();

 private:
  GameState* _gameState;
  DigiFunctions* _digiFunctions;
  Player* _player1;
  Player* _player2;
};

#endif
