#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#pragma once
// #include <LiquidCrystal_I2C.h>
#include "LiquidCrystal_I2C.h"
#include "Player.h"
#include "ScoreBoard.h"

class ScoreBoard {
 public:
  ScoreBoard(Player* player1, Player* player2, LiquidCrystal_I2C* lcdDisplay);
  void update();
  ~ScoreBoard();

 private:
  Player* _player1;
  Player* _player2;
  LiquidCrystal_I2C* _lcd;
  ScoreBoard* _scoreBoard;
};

#endif
