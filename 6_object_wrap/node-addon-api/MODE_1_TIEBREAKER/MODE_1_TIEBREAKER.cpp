#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include "Arduino.h"
#include "GameTimer.h"
#include "MODE_1_TIEBREAKER.h"

Mode1TieBreaker::Mode1TieBreaker(Player* player1,
                                 Player* player2,
                                 PinInterface* pinInterface,
                                 GameState* gameState,
                                 History* history)
    : _player1(player1),
      _player2(player2),
      _pinInterface(pinInterface),
      _gameState(gameState),
      _history(history),
      _pointLeds(player1, player2, pinInterface),
      _gameLeds(player1, player2, pinInterface),
      _serveLeds(pinInterface, gameState),
      _setLeds(player1, player2, pinInterface),
      _mode1WinSequences(player1, player2, pinInterface, gameState),
      _undo(player1, player2, pinInterface, gameState) {}

Mode1TieBreaker::~Mode1TieBreaker() {}

void Mode1TieBreaker::tieLEDsOn() {
  _gameState->setTieLEDsOn(1);  // tieLEDsOn = true;
  _pinInterface->pinDigitalWrite(P1_TIEBREAKER, HIGH);
  _pinInterface->pinDigitalWrite(P2_TIEBREAKER, HIGH);
}

void Mode1TieBreaker::tieLEDsOff() {
  _gameState->setTieLEDsOn(0);  // tieLEDsOn = false;
  _pinInterface->pinDigitalWrite(P1_TIEBREAKER, LOW);
  _pinInterface->pinDigitalWrite(P2_TIEBREAKER, LOW);
}

//------------------------------------------------------------------------------------------------------------------------
void Mode1TieBreaker::mode1TBButtonFunction() {
  // SerialObject Serial;
  switch (_gameState->getPlayerButton()) {
    case 0:
      break;

    case 1:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.setMode1Undo(_history);                  // SetMode1Undo();
      _player1->setGames(_player1->getGames() + 1);  // p1Games++;
      mode1TBP1Games();                              // Mode1TBP1Games();
      break;

    case 2:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;

    case 3:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.setMode1Undo(_history);                  // SetMode1Undo();
      _player2->setGames(_player2->getGames() + 1);  // p2Games++;
      mode1TBP2Games();                              //  Mode1TBP2Games();
      break;

    case 4:
      GameTimer::gameDelay(_gameState->getButtonDelay() /* buttonDelay */);
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;
  }
  _gameState->setPlayerButton(0); /* PlayerButton */ /* playerButton */  // = 0;
}

void Mode1TieBreaker::tieBreaker() {
  _undo.memory();  // Memory();  // remember player stats, tiebreakMem, and
                   // setTieBreakMem variables
  mode1TBButtonFunction();
}

//-------------------------------------------------------------------------------------------------------------------------

void Mode1TieBreaker::mode1SetTBButtonFunction() {
  switch (_gameState->getPlayerButton() /* playerButton */) {
    case 0:
      break;

    case 1:
      GameTimer::gameDelay(
          _gameState
              ->getButtonDelay() /* buttonDelay */);  // delay(
                                                      // _gameState->getButtonDelay()
                                                      // /* buttonDelay */  );
      _undo.setMode1Undo(_history);                  // SetMode1Undo();
      _player1->setGames(_player1->getGames() + 1);  // p1Games++;
      mode1SetTBP1Games();
      break;

    case 2:
      GameTimer::gameDelay(
          _gameState
              ->getButtonDelay() /* buttonDelay */);  // delay(
                                                      // _gameState->getButtonDelay()
                                                      // /* buttonDelay */  );
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;

    case 3:
      GameTimer::gameDelay(
          _gameState
              ->getButtonDelay() /* buttonDelay */);  // delay(
                                                      // _gameState->getButtonDelay()
                                                      // /* buttonDelay */  );
      _undo.setMode1Undo(_history);                  // SetMode1Undo();
      _player2->setGames(_player2->getGames() + 1);  // p2Games++;
      mode1SetTBP2Games();
      break;

    case 4:
      GameTimer::gameDelay(
          _gameState
              ->getButtonDelay() /* buttonDelay */);  // delay(
                                                      // _gameState->getButtonDelay()
                                                      // /* buttonDelay */  );;
      _undo.mode1Undo(_history);  // Mode1Undo();
      break;
  }
  _gameState->setPlayerButton(0); /* playerButton */  // = 0;
}

void Mode1TieBreaker::setTieBreaker() {
  _undo.memory();  // Memory();
  mode1SetTBButtonFunction();
}

//------------------------------------------------------------------------------------------------------------------------
void Mode1TieBreaker::tieBreakEnable() {
  _player1->setPoints(99);        // p1Points = 99;
  _player2->setPoints(99);        // p2Points = 99;
  _pointLeds.updatePoints();      // UpdatePoints();
  _gameState->setServeSwitch(1);  // serveSwitch = 1;
  _gameState->setServe(0);        // serve = 0;
  _serveLeds.serveSwitch();       // ServeSwitch();

  if (_gameState->getTieLEDsOn() == 0 /* tieLEDsOn == false */) {
    tieLEDsOn();
  }

  for (int currentPulseCount = 0;
       currentPulseCount < _gameState->getTiePulseCount();
       currentPulseCount++) {
    // _player1->setGames( 6 );  // p1Games = 6;
    // _player2->setGames( 6 );  // p2Games = 6;
    tieLEDsOff();
    // _gameLeds.updateGames();  // UpdateGames();
    GameTimer::gameDelay(_gameState->getFlashDelay() /* flashDelay */);
    // _player1->setGames( 6 );  // p1Games = 6;
    // _player2->setGames( 6 );  // p2Games = 6;
    tieLEDsOn();
    // _gameLeds.updateGames();  //    UpdateGames();
    GameTimer::gameDelay(_gameState->getFlashDelay() /* flashDelay */);
  }
  _player1->setGames(0);    // p1Games = 0;
  _player2->setGames(0);    // p2Games = 0;
  _gameLeds.updateGames();  // UpdateGames();
  GameTimer::gameDelay(
      _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);
}

void Mode1TieBreaker::setTieBreakEnable() {
  _player1->setPoints(99);        // p1Points = 99;
  _player2->setPoints(99);        // p2Points = 99;
  _pointLeds.updatePoints();      // UpdatePoints();
  _gameState->setServeSwitch(1);  // serveSwitch = 1;
  _gameState->setServe(0);        // serve = 0;
  _serveLeds.serveSwitch();       // ServeSwitch(); // if serveSwitch >= 2, then
                                  // serveSwitch = 0; and toggle serve

  if (_gameState->getTieLEDsOn() == 0 /* tieLEDsOn == false */) {
    tieLEDsOn();
  }
  // for (int currentPulseCount = 0; currentPulseCount <
  // _gameState->getTiePulseCount(); // tiePulseCount;
  //       currentPulseCount++) {
  //     tieLEDsOff();
  //     GameTimer::gameDelay( _gameState->getFlashDelay() /* flashDelay */ );
  //     tieLEDsOn();
  //     GameTimer::gameDelay( _gameState->getFlashDelay() /* flashDelay */ );
  // }
  _player1->setGames(0);    // p1Games = 0;
  _player2->setGames(0);    // p2Games = 0;
  _gameLeds.updateGames();  // UpdateGames();
  GameTimer::gameDelay(
      _gameState
          ->getUpdateDisplayDelay() /* updateDisplayDelay */);  // delay(
                                                                // _gameState->getUpdateDisplayDelay()
                                                                // /*
                                                                // updateDisplayDelay
                                                                // */ );
}

//--------------------------------------------------------------------------------------------------------------------------
void Mode1TieBreaker::endTieBreak() {
  tieLEDsOff();
  _player1->setPoints(0);         // p1Points = 0;
  _player2->setPoints(0);         // p2Points = 0;
  _player1->setGames(0);          // p1Games = 0;
  _player2->setGames(0);          // p2Games = 0;
  _pointLeds.updatePoints();      // UpdatePoints();
  _gameLeds.updateGames();        // UpdateGames();
  _gameState->setTieBreak(0);     // tieBreak = false;
  _gameState->setSetTieBreak(0);  // setTieBreak = false;
}

void Mode1TieBreaker::mode1TBP1Games() {
  _gameLeds.updateGames();  // UpdateGames();
  _gameState->setServeSwitch(_gameState->getServeSwitch() +
                             1);  // serveSwitch++;
  GameTimer::gameDelay(
      _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);

  if (_player1->getGames() == 15 /* p1Games == 15 */) {
    _player1->setSets(_player1->getSets() + 1);  // p1Sets++;

    if (_player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */) {
      endTieBreak();                            // EndTieBreak();
      _mode1WinSequences.p1TBSetWinSequence();  // P1TBSetWinSequence();
      _gameState->setSetTieBreak(1);            // setTieBreak = true;
      setTieBreakEnable();                      // SetTieBreakEnable();
    } else {
      _mode1WinSequences.p1SetWinSequence();  // P1SetWinSequence();
      endTieBreak();                          // EndTieBreak();
    }
  }

  // if ( p1Games >= 10 && ( p1Games - p2Games) > 1) {
  if (_player1->getGames() >= 10 &&
      (_player1->getGames() - _player2->getGames()) > 1) {
    _player1->setSets(_player1->getSets() + 1);  // p1Sets++;
    if (_player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */) {
      endTieBreak();                            // EndTieBreak();
      _mode1WinSequences.p1TBSetWinSequence();  // P1TBSetWinSequence();
      _gameState->setSetTieBreak(1);            // setTieBreak = true;
      setTieBreakEnable();                      // SetTieBreakEnable();
    } else {
      _mode1WinSequences.p1SetWinSequence();  // P1SetWinSequence();
      endTieBreak();                          // EndTieBreak();
    }
  }
}

void Mode1TieBreaker::mode1TBP2Games() {
  _gameLeds.updateGames();  // UpdateGames();
  _gameState->setServeSwitch(_gameState->getServeSwitch() +
                             1);  // serveSwitch++;
  GameTimer::gameDelay(
      _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);

  if (_player2->getGames() /* p2Games */ == 15) {
    _player2->setSets(_player2->getSets() + 1);  // p2Sets++;

    if (_player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */) {
      endTieBreak();                            // EndTieBreak();
      _mode1WinSequences.p2TBSetWinSequence();  // P2TBSetWinSequence();
      _gameState->setSetTieBreak(1);            // setTieBreak = true;
      setTieBreakEnable();                      // SetTieBreakEnable();
    } else {
      _mode1WinSequences.p2SetWinSequence();  // P2SetWinSequence();
      endTieBreak();                          // EndTieBreak();
    }
  }

  if (_player2->getGames() /* p2Games */ >= 10 &&
      (_player2->getGames() /* p2Games */ -
       _player1->getGames() /* p1Games */) > 1) {
    _player2->setSets(_player2->getSets() + 1);  // p2Sets++;

    if (_player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */) {
      endTieBreak();                            // EndTieBreak();
      _mode1WinSequences.p2TBSetWinSequence();  // P2TBSetWinSequence();
      _gameState->setSetTieBreak(1);            // setTieBreak = true;
      setTieBreakEnable();                      // SetTieBreakEnable();
    } else {
      _mode1WinSequences.p2SetWinSequence();  // P2SetWinSequence();
      endTieBreak();                          // EndTieBreak();
    }
  }
}

void Mode1TieBreaker::mode1SetTBP2Games() {
  _gameLeds.updateGames();  // UpdateGames();
  GameTimer::gameDelay(
      _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);

  if (_player2->getGames() /* p2Games */ == 7) {
    _player2->setSets(_player2->getSets() + 1);  // p2Sets++;
    _setLeds.updateSets();                       // UpdateSets();
    GameTimer::gameDelay(
        _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);
    _mode1WinSequences.p2SetTBWinSequence();  // P2SetTBWinSequence();
    tieLEDsOff();                             // TieLEDsOff();
    _mode1WinSequences.p2MatchWinSequence();  // P2MatchWinSequence();
  }
  _gameState->setServeSwitch(_gameState->getServeSwitch() +
                             1);  // serveSwitch++;
}

void Mode1TieBreaker::mode1SetTBP1Games() {
  _gameLeds.updateGames();  // UpdateGames();
  GameTimer::gameDelay(
      _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);

  if (_player1->getGames() /* p1Games */ == 7) {
    _player1->setSets(_player1->getSets() + 1);  // p1Sets++;
    _setLeds.updateSets();                       // UpdateSets();
    GameTimer::gameDelay(
        _gameState->getUpdateDisplayDelay() /* updateDisplayDelay */);
    _mode1WinSequences.p1SetTBWinSequence();  // P1SetTBWinSequence();
    tieLEDsOff();                             // TieLEDsOff();
    _mode1WinSequences.p1MatchWinSequence();  // P1MatchWinSequence();
  }
  _gameState->setServeSwitch(_gameState->getServeSwitch() +
                             1);  // serveSwitch++;
}
