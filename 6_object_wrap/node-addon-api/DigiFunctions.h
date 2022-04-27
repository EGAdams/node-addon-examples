#pragma once
//
//  DigiFunctions.h
//
#ifndef DIGIFUNCTIONS_H
#define DIGIFUNCTIONS_H

#include "GameState.h"
#include "GameTimer.h"
#include "PinState.h"
#include "TranslateConstant.h"
// #include "INPUTS.h"
#include "LiquidCrystal_I2C.h"
#include "Player.h"
#include "ScoreBoard.h"
// #include "GameModes.h"
class GameModes;
class Inputs;
class DigiFunctions {
 public:
  DigiFunctions(Player* player1,
                Player* player2,
                GameState* state,
                ScoreBoard* scoreBoard);
  ~DigiFunctions();
  // void pinMode(int pin, int mode);
  // void setup();
  void loop();
  void digitalWrite(int pin, int mode);
  int digitalRead(int pin);
  int analogRead(int pin);
  void gameDelay(int ms);
  unsigned long millis(int hack);
  void clearPinState();
  GameState* getGameState() { return _gameState; }

 private:
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  Inputs* _gameInputs;
  ScoreBoard* _scoreBoard;
  GameModes* _gameModes;
  TranslateConstant _translateConstant;
  PinState _pinState;
};

#endif
