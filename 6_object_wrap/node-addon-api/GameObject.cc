#include "GameObject.h"

GameObject::GameObject(){};
GameObject::~GameObject(){};

void GameObject::startGame() {
  std::cout << "starting game inside gameObject..." << std::endl;
  Player player1 = Player(1);
  Player player2 = Player(2);
  GameState gameState = GameState();
  LiquidCrystal_I2C liquidCrystal_I2C = LiquidCrystal_I2C();
  ScoreBoard scoreBoard = ScoreBoard(&player1, &player2, &liquidCrystal_I2C);
  DigiFunctions digiFunctions =
      DigiFunctions(&player1, &player2, &gameState, &scoreBoard);
}
