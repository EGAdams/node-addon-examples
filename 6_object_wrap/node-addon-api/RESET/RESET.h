#ifndef RESET_h
#define RESET_h

#include "Arduino.h"
#include "GameState.h"
#include "GameTimer.h"
#include "PinInterface.h"

class Reset {
 public:
  Reset(Player* player1,
        Player* player2,
        PinInterface* pinInterface,
        GameState* gameState);
  ~Reset();
  void resetScoreboard();
  void resetPreviousValues();
  void refresh();
  void tieLEDsOn();
  void tieLEDsOff();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
};

#endif
