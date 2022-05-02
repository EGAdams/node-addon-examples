#include "GameObject.h"

GameObject::GameObject() {
  _pinState = new PinState();
  _liquidCrystal_I2C = new LiquidCrystal_I2C();
  _player1 = new Player(1);
  _player2 = new Player(2);
  _pinInterface = new PinInterface(_pinState);
  _gameState = new GameState(_player1, _player2);
  _scoreBoard = new ScoreBoard(_player1, _player2, _liquidCrystal_I2C);
  _gameInputs = new Inputs(_player1, _player2, _pinInterface, _gameState);
  _gameModes = new GameModes(_player1, _player2, _pinInterface, _gameState);
  std::cout << "Done constructing GameObject::GameObject()" << std::endl;
};
GameObject::~GameObject(){};

void GameObject::startGame() {
  std::cout << "starting game inside gameObject..." << std::endl;
  std::cout << "pinState 0: " << _pinState->getPinState("0") << std::endl;
}

PinInterface* GameObject::getPinInterface() {
  return _pinInterface;
}

void GameObject::loop() {
  std::cout << "inside loop, before read reset..." << std::endl;
  _gameInputs->readReset();
  _gameModes->setGameMode(_gameInputs->readRotary());
  // GameTimer::delay(750);
}
