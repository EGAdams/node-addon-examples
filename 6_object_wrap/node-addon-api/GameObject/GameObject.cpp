#include "GameObject.h"
#include "Arduino.h"

GameObject::GameObject(Player* player1,
                       Player* player2,
                       PinState* pinState,
                       PinInterface* pinInterface,
                       GameState* gameState,
                       GameTimer* gameTimer,
                       Inputs* gameInputs,
                       GameModes* gameModes,
                       ScoreBoard* scoreBoard,
                       WebLiquidCrystal* lcd) {
  _player1 = player1;
  _player2 = player2;
  _pinState = pinState;
  _pinInterface = pinInterface;
  _gameState = gameState;
  _gameTimer = gameTimer;
  _gameInputs = gameInputs;
  _gameModes = gameModes;
  _scoreBoard = scoreBoard;
  _webLiquidCrystal = lcd;
}

GameObject::~GameObject(){};

void GameObject::loopGame() {
  _gameInputs->readReset();
  _gameModes->setGameMode(_gameInputs->readRotary());
  // _gameModes->setGameMode( 1 );
  GameTimer::gameDelay(25);
}

PinInterface* GameObject::getPinInterface() {
  return _pinInterface;
}

void GameObject::start() {
  // std::cout << "inside loop, before read reset..." << std::endl;
  // _gameInputs->readReset();
  // _gameModes->setGameMode(_gameInputs->readRotary());
  // GameTimer::gameDelay(750);
}
