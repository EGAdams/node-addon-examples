#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <iostream>
#include "DigiFunctions.h"
#include "GAME_MODES.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "LiquidCrystal_I2C.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
class GameObject {
 public:
  GameObject();
  ~GameObject();
  void startGame();
  PinInterface* getPinInterface();
  void loop();

 private:
  double value_;
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  PinState* _pinState;
  PinInterface* _pinInterface;
  LiquidCrystal_I2C* _liquidCrystal_I2C;
  ScoreBoard* _scoreBoard;
  DigiFunctions* _digiFunctions;
  Inputs* _gameInputs;
  GameModes* _gameModes;
};

#endif
