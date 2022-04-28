#include "GameObject.h"
#include <iostream>
#include "DigiFunctions.h"
#include "GameState.h"
#include "PinInterface.h"
#include "PinState.h"

GameObject::GameObject() {
  std::cout << "GameObject::GameObject()" << std::endl;
  _player1 = new Player(1);
  _player2 = new Player(2);
  _liquidCrystal_I2C = new LiquidCrystal_I2C();
  _scoreboard = new ScoreBoard(_player1, _player2, _liquidCrystal_I2C);
  _gameState = new GameState();
  _pinInterface = new PinInterface(PinState());
  _inputs = new Inputs(_player1, _player2, _pinInterface, _gameState);
  _gameModes = new GameModes(_player1, _player2, _pinInterface, _gameState);
};

GameObject::~GameObject(){};
void GameObject::startGame() {
  std::cout << "starting game inside gameObject..." << std::endl;
  DigiFunctions digiFunctions(_player1, _player2, _gameState, _scoreboard);
}
