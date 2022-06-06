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
  _webLiquidCrystal = new WebLiquidCrystal();
  _gameTimer = new GameTimer();
  _player1 = new Player(1);
  _player2 = new Player(1);
#if defined _WIN32 || defined _WIN64
  _pin_map = new std::map<std::string, int>();
  _pinState = new PinState(_pin_map);
  _pinInterface = new PinInterface(_pinState);
#else
  _pinState = new PinState();
  _pinInterface = new PinInterface(_pinState);
#endif
  _history = new History();
  _gameState = new GameState();
  _gameInputs = new Inputs(_player1, _player2, _pinInterface, _gameState);
  _gameModes =
      new GameModes(_player1, _player2, _pinInterface, _gameState, _history);
  _scoreBoard = new ScoreBoard(_player1, _player2, _webLiquidCrystal);
  _subjectManager = new SubjectManager();
  _logger = new Logger(
      "C:\\Users\\EG\\Desktop\\2022\\may\\4th_week\\log_viewer_sand\\test.txt");
}

GameObject::~GameObject(){};

void GameObject::loopGame() {
  _logger->logUpdate("starting loop game...", __FUNCTION__);
  _gameInputs->readReset();
  _gameModes->setGameMode(_gameInputs->readRotary());
  GameTimer::gameDelay(25);
  _subjectManager->gameStateUpdate(_gameState);
}

PinInterface* GameObject::getPinInterface() {
  return _pinInterface;
}

void GameObject::start() {}
