#pragma once
#ifndef RESET_h
#define RESET_h

#include "GameState.h"
#include "PinInterface.h"
#include "Serial.h"
class Reset {
 public:
  Reset(Player* player1,
        Player* player2,
        PinInterface* pinInterface,
        GameState* gameState);
  ~Reset();
  void resetScoreboard();
  void resetPreviousValues();
  void refresh();
  void tieLEDsOn();
  void tieLEDsOff();

 private:
  PinInterface* _pinInterface;
  GameState* _gameState;
  Player* _player1;
  Player* _player2;
};

#endif
