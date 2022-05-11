#ifndef DIGIFUNCTIONS_H
#define DIGIFUNCTIONS_H

#include "Arduino.h"
#include "GAME_MODES.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "TranslateConstant.h"
#include "WebLiquidCrystal.h"
class DigiFunctions {
 public:
  DigiFunctions(Player* player1,
                Player* player2,
                PinInterface* pinInterface,
                GameState* gameState);
  ~DigiFunctions();
  // void pinMode(int pin, int mode);
  // void setup();
  // void loop();
  // void pinDigitalWrite(int pin, int mode);
  // int pinDigitalRead(int pin);
  // int pinAnalogRead(int pin);
  void gameDelay(int ms);
  unsigned long millis();
  GameState* getGameState() { return _gameState; }

 private:
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  Inputs _gameInputs;
  ScoreBoard* _scoreBoard;
  GameModes _gameModes;
  TranslateConstant _translateConstant;
  PinState _pinState;
};

#endif
