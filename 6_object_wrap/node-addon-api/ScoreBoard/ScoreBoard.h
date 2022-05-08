#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#pragma once
// #include <WebLiquidCrystal.h>
#include "Player.h"
#include "ScoreBoard.h"
#include "WebLiquidCrystal.h"

class ScoreBoard {
 public:
  ScoreBoard(Player* player1, Player* player2, WebLiquidCrystal* lcdDisplay);
  void update();
  ~ScoreBoard();

 private:
  Player* _player1;
  Player* _player2;
  WebLiquidCrystal* _lcd;
  ScoreBoard* _scoreBoard;
};

#endif
