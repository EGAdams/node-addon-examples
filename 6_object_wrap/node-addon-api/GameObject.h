#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <iostream>
#include "DigiFunctions.h"
#include "GAME_MODES.h"
#include "GameState.h"
#include "INPUTS.h"
#include "LiquidCrystal_I2C.h"
#include "PinInterface.h"
#include "Player.h"
#include "ScoreBoard.h"
class GameObject {
 public:
  GameObject();
  ~GameObject();
  void startGame();

 private:
  double value_;
};

#endif
