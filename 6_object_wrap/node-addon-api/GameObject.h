#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "DigiFunctions.h"
#include "GAME_MODES.h"
#include "INPUTS.h"
#include "LiquidCrystal_I2C.h"
#include "ScoreBoard.h"
class GameObject {
 public:
  GameObject();
  ~GameObject();
  void startGame();

 private:
  double value_;
  Player* _player1;
  Player* _player2;
  ScoreBoard* _scoreboard;
  DigiFunctions* _digiFunctions;
  Inputs* _inputs;
  GameModes* _gameModes;
  GameState* _gameState;
  PinInterface* _pinInterface;
  LiquidCrystal_I2C* _liquidCrystal_I2C;
};

#endif
