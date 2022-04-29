#pragma once
//
//
//
#ifndef MODE_1_SCORE_H
#define MODE_1_SCORE_H

#include "GAME_LEDs.h"
#include "GameState.h"
#include "GameTimer.h"
#include "MODE_1_TIEBREAKER.h"
#include "MODE_1_WIN_SEQUENCES.h"
#include "POINT_LEDs.h"
#include "PinInterface.h"
#include "Player.h"
#include "SET_LEDs.h"
#include "UNDO.h"

class Mode1Score {
 public:
  Mode1Score(Player* player1,
             Player* player2,
             PinInterface* pinInterface,
             GameState* gameState);
  ~Mode1Score();
  void mode1P1Score();
  void mode1P1Games();
  void mode1TBP1Games();
  void mode1SetTBP1Games();
  void mode1P2Score();
  void mode1P2Games();
  void mode1TBP2Games();
  void mode1SetTBP2Games();

 private:
  Undo _undo;
  PinInterface* _pinInterface;
  Player* _player1;
  Player* _player2;
  Mode1TieBreaker _mode1TieBreaker;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  Mode1WinSequences _mode1WinSequences;
  GameState* _gameState;
};

#endif