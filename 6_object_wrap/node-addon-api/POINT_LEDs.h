#pragma once
//
//
//
#ifndef POINT_LEDS_h
#define POINT_LEDS_h

#include "DigiFunctions.h"
#include "Player.h"

class PointLeds {
 public:
  PointLeds(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~PointLeds();
  void updatePoints();
  void updateTBPoints();

 private:
  DigiFunctions* _digiFunctions;
  Player* _player1;
  Player* _player2;
};

#endif
