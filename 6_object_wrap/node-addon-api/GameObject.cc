#include "GameObject.h"

GameObject::GameObject() {
  _liquidCrystal_I2C = new LiquidCrystal_I2C();
  _pinState = new PinState();
  _pinInterface = new PinInterface(*_pinState);
  _player1 = new Player(1);
  _player2 = new Player(2);
  _gameState = new GameState(_player1, _player2);
  _scoreBoard = new ScoreBoard(_player1, _player2, _liquidCrystal_I2C);
  _digiFunctions =
      new DigiFunctions(_player1, _player2, _pinInterface, _gameState);
};
GameObject::~GameObject(){};

void GameObject::startGame() {
  std::cout << "starting game inside gameObject..." << std::endl;
  std::cout << "player1 points: " << _player1->getPoints() << std::endl;
}
