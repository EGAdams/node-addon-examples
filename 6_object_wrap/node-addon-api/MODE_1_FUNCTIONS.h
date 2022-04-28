#pragma once
#ifndef MODE_1_FUNCTIONS_h
#define MODE_1_FUNCTIONS_h
#include "GameState.h"
#include "GameTimer.h"
#include "MODE_1_SCORE.h"
#include "POINT_LEDs.h"
#include "PinInterface.h"
#include "UNDO.h"
class Mode1Functions {
 public:
  Mode1Functions(Player* player1,
                 Player* player2,
                 PinInterface* pinInterface,
                 GameState* gameState);
  ~Mode1Functions();
  void mode1ButtonFunction();
  void mode1ServeFunction();
  void pointFlash();

 private:
  Undo _undo;
  PointLeds _pointLeds;
  bool* _pointFlash;
  PinInterface* _pinInterface;
  Mode1Score _mode1Score;
  GameState* _gameState;
  Player* _player1;
  Player* _player2;
};

#endif
