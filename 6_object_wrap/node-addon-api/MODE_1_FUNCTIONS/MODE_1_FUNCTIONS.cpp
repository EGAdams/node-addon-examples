#include "MODE_1_FUNCTIONS.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

Mode1Functions::Mode1Functions(Player* player1,
                               Player* player2,
                               PinInterface* pinInterface,
                               GameState* gameState,
                               History* history)
    : _player1(player1),
      _player2(player2),
      _gameState(gameState),
      _history(history),
      _undo(player1, player2, pinInterface, gameState),
      _pointLeds(player1, player2, pinInterface),
      _mode1Score(player1, player2, pinInterface, gameState, history),
      _serveLeds(pinInterface, gameState) {}

Mode1Functions::~Mode1Functions() {}

void Mode1Functions::mode1ButtonFunction() {
  switch (_gameState->getPlayerButton() /* playerButton */) {
    case 0:
      break;

    case 1:
      _undo.setMode1Undo(_history);
      if (_gameState->getPointFlash() == 1 /* *_pointFlash == true */) {
        _gameState->setPointFlash(0);  // *_pointFlash = false;
        _player1->setPoints(
            _gameState->getP1PointsMem() /* p1PointsMem */);  // p1Points =
                                                              // p1PointsMem;
        _player2->setPoints(
            _gameState->getP2PointsMem() /* p2PointsMem */);  // p2Points =
                                                              // p2PointsMem;
        _pointLeds.updatePoints();
      }
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _player1->setPoints(_player1->getPoints() + 1);  // p1Points++;
      _undo.memory();
      _mode1Score.mode1P1Score();
      break;

    case 2:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;

    case 3:
      _undo.setMode1Undo(_history);  // SetMode1Undo();
      if (_gameState->getPointFlash() == 1 /* pointFlash == true */) {
        _gameState->setPointFlash(0);  // pointFlash = false;
        _player1->setPoints(
            _gameState->getP1PointsMem() /* p1PointsMem */);  // p1Points =
                                                              // p1PointsMem;
        _player2->setPoints(
            _gameState->getP2PointsMem() /* p2PointsMem */);  // p2Points =
                                                              // p2PointsMem;
        _pointLeds.updatePoints();                            // UpdatePoints();
      }

      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _player2->setPoints(_player2->getPoints() + 1);  // p2Points++;
      _undo.memory();                                  // Memory();
      _mode1Score.mode1P2Score();                      // Mode1P2Score();
      break;

    case 4:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;
  }
  _gameState->setPlayerButton(0);  // playerButton = 0;
}

void Mode1Functions::mode1ServeFunction() {
  _undo.setMode1Undo(_history);  // SetMode1Undo();
  _serveLeds.serveSwitch();      // ServeSwitch();
}

void Mode1Functions::pointFlash() {
  if (_gameState->getPointFlash() == 1 /* pointFlash == true */) {
    if (_player1->getPoints() /* p1Points */ > 3) {
      // if ( now - previous_time > _gameState->getFlashDelay() /* flashDelay */
      // ) {
      if (_gameState->getNow() /* now */ - _gameState->getPreviousTime() >
          _gameState->getFlashDelay() /* flashDelay */) {
        if (_gameState->getToggle() /* toggle */ == 0) {
          _player1->setPoints(99);    // p1Points = 99;
          _pointLeds.updatePoints();  // UpdatePoints();
          _gameState->setToggle(1);   // toggle = 1;
        } else {
          _player1->setPoints(
              _gameState->getP1PointsMem() /* p1PointsMem */);  // p1Points =
          _pointLeds.updatePoints();  //  UpdatePoints();
          _gameState->setToggle(0);   // toggle = 0;
        }
        _gameState->setPreviousTime(
            _gameState->getNow() /* now */);  // previous_time = now;
      }
    }

    if (_player2->getPoints() /* p2Points */ > 3) {
      // if ( now - previous_time > _gameState->getFlashDelay() /* flashDelay */
      // ) {
      if (_gameState->getNow() /* now */ - _gameState->getPreviousTime() >
          _gameState->getFlashDelay() /* flashDelay */) {
        if (_gameState->getToggle() /* toggle */ == 0) {
          _player2->setPoints(99);    // p2Points = 99;
          _pointLeds.updatePoints();  // UpdatePoints();
          _gameState->setToggle(1);   // toggle = 1;
        } else {
          _player2->setPoints(
              _gameState->getP2PointsMem() /* p2PointsMem */);  // p2Points =
          _pointLeds.updatePoints();  //  UpdatePoints();
          _gameState->setToggle(0);   // toggle = 0;
        }
        _gameState->setPreviousTime(
            _gameState->getNow() /* now */);  // previous_time = now;
      }
    }
  }
}
