#pragma once
#ifndef GAME_LEDs_HEADER_H
#define GAME_LEDs_HEADER_H

#include "DIGI_V6_15.h"
#include "PinInterface.h"
#include "Player.h"
class GameLeds {
 public:
  GameLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~GameLeds();
  void updateGames();

 private:
  PinInterface* _pinInterface;
  Player* _player1;
  Player* _player2;
};

#endif
