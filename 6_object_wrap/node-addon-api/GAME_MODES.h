#pragma once
//
// GAME_MODES.h
//
#ifndef GAME_MODES_h
#define GAME_MODES_h

#include "DigiFunctions.h"
#include "GAME_LEDs.h"
#include "GameState.h"
#include "POINT_LEDs.h"
#include "Player.h"
#include "SET_LEDs.h"

#include "MODE_1_FUNCTIONS.h"
#include "MODE_1_TIEBREAKER.h"
#include "MODE_2_FUNCTIONS.h"
#include "SERVE_LEDs.h"
#include "UNDO.h"

class GameModes {
 public:
  GameModes(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~GameModes();
  void gameStart();
  void mode1();
  void mode2();
  void mode4();
  void noCode();
  void setGameMode(int rotaryPosition);

 private:
  Player* _player1;
  Player* _player2;
  DigiFunctions* _digiFunctions;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  Inputs _inputs;
  Undo _undo;
  ServeLeds _serveLeds;
  Mode1TieBreaker _mode1TieBreaker;
  Mode1Functions _mode1Functions;
  Mode2Functions _mode2Functions;
};

#endif
