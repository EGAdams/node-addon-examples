#pragma once
#ifndef POINT_LEDS_h
#define POINT_LEDS_h

#include "GameState.h"
#include "PinInterface.h"
#include "Player.h"
class PointLeds {
 public:
  PointLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~PointLeds();
  void updatePoints();
  void updateTBPoints();

 private:
  PinInterface* _pinInterface;
  Player* _player1;
  Player* _player2;
};

#endif
