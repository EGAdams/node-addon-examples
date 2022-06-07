#include "UNDO.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

Undo::Undo(Player* player1,
           Player* player2,
           PinInterface* pinInterface,
           GameState* gameState)
    : _player1(player1),
      _player2(player2),
      _gameState(gameState),
      _pointLeds(player1, player2, pinInterface),
      _gameLeds(player1, player2, pinInterface),
      _setLeds(player1, player2, pinInterface),
      _serveLeds(pinInterface, gameState),
      _tieLeds(pinInterface) {
  _logger = new Logger(LOG_FILE_PATH);
};

Undo::~Undo(){};

void Undo::memory() {
  _gameState->setP1PointsMem(_player1->getPoints());
  _gameState->setP2PointsMem(_player2->getPoints());
  _gameState->setP1GamesMem(_player1->getGames());
  _gameState->setP2GamesMem(_player2->getGames());
  _gameState->setP1SetsMem(_player1->getSets());
  _gameState->setP2SetsMem(_player2->getSets());
  _gameState->setTieBreakMem(_gameState->getTieBreak());
  _gameState->setSetTieBreakMem(
      _gameState->getSetTieBreak());  // setTieBreakMem = setTieBreak;
}

void Undo::setMode1Undo(History* history) {
  GameState gameState;
  gameState.setPlayer1Points(_player1->getPoints());
  gameState.setPlayer2Points(_player2->getPoints());
  gameState.setPlayer1Games(_player1->getGames());
  gameState.setPlayer2Games(_player2->getGames());
  gameState.setPlayer1Sets(_player1->getSets());
  gameState.setPlayer2Sets(_player2->getSets());
  gameState.setPlayer1Matches(_player1->getMatches());
  gameState.setPlayer2Matches(_player2->getMatches());

  gameState.setServe(_gameState->getServe());
  gameState.setTieBreak(_gameState->getTieBreak());
  gameState.setSetTieBreak(_gameState->getSetTieBreak());
  gameState.setServeSwitch(_gameState->getServeSwitch());
  gameState.setUndo(_gameState->getUndo());
  gameState.setStarted(_gameState->getStarted());
  gameState.setRotaryChange(_gameState->getRotaryChange());
  gameState.setToggle(_gameState->getToggle());
  gameState.setTieBreakOnly(_gameState->getTieBreakOnly());
  gameState.setTieBreakMem(_gameState->getTieBreakMem());
  history->push(gameState);
}

void Undo::mode1Undo(History* history) {
  GameTimer::gameDelay(250);
  if (history->size() == 0) {
    return;
  }
  GameState gameState = (history->pop());
  _player1->setPoints(gameState.getPlayer1Points());
  _player2->setPoints(gameState.getPlayer2Points());
  _player1->setGames(gameState.getPlayer1Games());
  _player2->setGames(gameState.getPlayer2Games());
  _player1->setSets(gameState.getPlayer1Sets());
  _player2->setSets(gameState.getPlayer2Sets());
  _player1->setMatches(gameState.getPlayer1Matches());
  _player2->setMatches(gameState.getPlayer2Matches());
  _gameState->setServe(gameState.getServe());
  _gameState->setTieBreak(gameState.getTieBreak());
  _gameState->setSetTieBreak(gameState.getSetTieBreak());
  _gameState->setServeSwitch(gameState.getServeSwitch());
  _gameState->setUndo(gameState.getUndo());
  _gameState->setStarted(gameState.getStarted());
  _gameState->setRotaryChange(gameState.getRotaryChange());
  _gameState->setToggle(gameState.getToggle());
  _gameState->setTieBreakOnly(gameState.getTieBreakOnly());
  _gameState->setTieBreakMem(gameState.getTieBreakMem());

  if (_gameState->getTieLEDsOn() == 1 /* tieLEDsOn == true */) {
    // _mode1TieBreaker.tieLEDsOn();  // TieLEDsOn();
    _gameState->setTieLEDsOn(1);  // tieLEDsOn = true;
    _tieLeds.turnOn();
  }
  if (_gameState->getTieLEDsOn() == 0) {
    _tieLeds.turnOff();
    _gameState->setTieLEDsOn(0);
  }
  _logger->logUpdate("updating leds...", __FUNCTION__);
  _pointLeds.updatePoints();    // UpdatePoints();
  _gameLeds.updateGames();      // UpdateGames();
  _setLeds.updateSets();        // UpdateSets();
  _serveLeds.updateServeLED();  // UpdateServeLED();
}
