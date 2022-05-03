#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "DigiFunctions.h"
#include "GAME_MODES.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "LiquidCrystal.h"
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
  void beginLoop();

 private:
  double value_;
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  PinState* _pinState;
  PinInterface* _pinInterface;
  LiquidCrystal* _liquidCrystal;
  ScoreBoard* _scoreBoard;
  DigiFunctions* _digiFunctions;
  Inputs* _gameInputs;
  GameModes* _gameModes;
};

#endif
