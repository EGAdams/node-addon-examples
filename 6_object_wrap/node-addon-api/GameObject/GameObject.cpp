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

GameObject::GameObject() {
  std::cout << "GameObject::GameObject()" << std::endl;
  _pin_map = new std::map<std::string, int>();
  _webLiquidCrystal = new WebLiquidCrystal();
  _gameTimer = new GameTimer();
  _player1 = new Player(1);
  _player2 = new Player(1);
  _pinState = new PinState(_pin_map);
  _pinInterface = new PinInterface(_pinState);
  _gameState = new GameState(_player1, _player2);
  _gameInputs = new Inputs(_player1, _player2, _pinInterface, _gameState);
  _gameModes = new GameModes(_player1, _player2, _pinInterface, _gameState);
  _scoreBoard = new ScoreBoard(_player1, _player2, _webLiquidCrystal);
  std::cout << "GameObject::GameObject() done" << std::endl;
}

GameObject::~GameObject(){};

void GameObject::loopGame() {
  std::cout << "GameObject::loopGame() calling readReset()..." << std::endl;
  _gameInputs->readReset();
  std::cout << "GameObject::loopGame() calling setGameMode()..." << std::endl;
  _gameModes->setGameMode(_gameInputs->readRotary());
  std::cout << "GameObject::loopGame() calling gameDelay()..." << std::endl;
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