#pragma once
//
//
//
#include "DigiFunctions.h"
#include "Player.h"

class SetLeds {
 public:
  SetLeds(Player* player1, Player* player2, DigiFunctions* digiFunctions);
  ~SetLeds();
  void updateSets();
  void setPlayers(Player* player1, Player* player2);

 private:
  Player* _player1;
  Player* _player2;
  DigiFunctions* _digiFunctions;
};
