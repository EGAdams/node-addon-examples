#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
// #include "DigiFunctions.h"
#include "Arduino.h"
#include "GAME_MODES.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "SubjectManager.h"
#include "WebLiquidCrystal.h"

class GameObject {
 public:
  GameObject(Player* player1,
             Player* player2,
             PinState* pinState,
             PinInterface* pinInterface,
             GameState* gameState,
             GameTimer* gameTimer,
             Inputs* gameInputs,
             GameModes* gameModes,
             ScoreBoard* scoreBoard,
             WebLiquidCrystal* lcd);
  GameObject();
  ~GameObject();
  void start();
  PinInterface* getPinInterface();
  void loopGame();

 private:
  Player* _player1;
  Player* _player2;
  PinState* _pinState;
  PinInterface* _pinInterface;
  GameState* _gameState;
  GameTimer* _gameTimer;
  Inputs* _gameInputs;
  GameModes* _gameModes;
  ScoreBoard* _scoreBoard;
  WebLiquidCrystal* _webLiquidCrystal;
  std::map<std::string, int>* _pin_map;
  SubjectManager* _subjectManager;
};

#endif
