#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#pragma once
// #include <LiquidCrystal.h>
#include "LiquidCrystal.h"
#include "Player.h"
#include "ScoreBoard.h"

class ScoreBoard {
 public:
  ScoreBoard(Player* player1, Player* player2, LiquidCrystal* lcdDisplay);
  void update();
  ~ScoreBoard();

 private:
  Player* _player1;
  Player* _player2;
  LiquidCrystal* _lcd;
  ScoreBoard* _scoreBoard;
};

#endif
