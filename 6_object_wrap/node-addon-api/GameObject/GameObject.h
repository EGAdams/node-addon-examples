#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "GAME_MODES.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "WebLiquidCrystal.h"
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
  WebLiquidCrystal* _liquidCrystal;
  ScoreBoard* _scoreBoard;
  Inputs* _gameInputs;
  GameModes* _gameModes;
};

#endif
