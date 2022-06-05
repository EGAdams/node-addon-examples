#include "GAME_MODES.h"
#include "Arduino.h"
GameModes::~GameModes() {}
GameModes::GameModes(Player* player1,
                     Player* player2,
                     PinInterface* pinInterface,
                     GameState* gameState,
                     History* history)
    : _history(history),
      _player1(player1),
      _player2(player2),
      _pinInterface(pinInterface),
      _gameState(gameState),
      _pointLeds(player1, player2, pinInterface),
      _gameLeds(player1, player2, pinInterface),
      _setLeds(player1, player2, pinInterface),
      _inputs(player1, player2, pinInterface, gameState),
      _undo(player1, player2, pinInterface, gameState),
      _serveLeds(pinInterface, gameState),
      _mode1TieBreaker(player1, player2, pinInterface, gameState, history),
      _mode1Functions(player1, player2, pinInterface, gameState, history),
      _mode2Functions(player1, player2, pinInterface, gameState) {
  _logger = new Logger(
      "C:\\Users\\EG\\Desktop\\2022\\may\\4th_week\\log_viewer_sand\\test.txt");
}

void GameModes::gameStart() {
  if (_gameState->getStarted() == 0) {  // if not started...
    // std::cout << "resetting points, games and set counters to zero..." <<
    // std::endl;
    _player1->setPoints(0);  // p1Points = 0;
    _player2->setPoints(0);  // p2Points = 0;
    _player1->setGames(0);   // p1Games = 0;
    _player2->setGames(0);   // p2Games = 0;
    _player1->setSets(0);    // p1Sets = 0;
    _player2->setSets(0);    // p2Sets = 0;
    // std::cout << "updating points, games and set LEDs..." << std::endl;
    _pointLeds.updatePoints();       // UpdatePoints();
    _gameLeds.updateGames();         // UpdateGames();
    _setLeds.updateSets();           // UpdateSets();
    _gameState->setTieBreakOnly(0);  // tieBreakOnly = false;
    // std::cout << "setting game started flag..." << std::endl;
    _gameState->setStarted(1);  // gameStart = false; // set to started.
  }
}

void GameModes::mode1() {
  std::cout << "mode 1.  PLAYER_BUTTON: "
            << _pinInterface->pinDigitalRead(PLAYER_BUTTONS) << std::endl;
  _gameState->setNow(GameTimer::gameMillis());          // now =
  _inputs.readUndoButton();                             // ReadUndoButton();
  if (_gameState->getUndo() == 1 /* undo == true */) {  // undo button pressed
    _gameState->setUndo(0);                             // undo = false;
    _undo.mode1Undo(_history);
  }  // Mode1Undo();

  std::cout << "reading player buttons..." << std::endl;
  _inputs.readPlayerButtons();  // digital read on player buttons.  sets
                                // playerButton if tripped.
  std::cout << "calling serveSwitch()..." << std::endl;
  _serveLeds.serveSwitch();  // ServeSwitch(); // if serveSwitch >= 2,
                             // serveSwitch = 0; and toggle serve variable

  if (_gameState->getTieBreak() == 1 /* tieBreak == true */) {
    _mode1TieBreaker.tieBreaker();
  }  // TieBreaker();

  if (_gameState->getSetTieBreak() /* setTieBreak == true */ == 1) {
    _mode1TieBreaker.setTieBreaker();  // SetTieBreaker();
  } else {
    _mode1Functions.mode1ButtonFunction();  // Mode1ButtonFunction();
    _mode1Functions.pointFlash();           // PointFlash();
  }
  std::cout << "done mode1." << std::endl;
}

void GameModes::mode2() {
  // SerialObject Serial;
  // Serial.println(" Starting Mode2.");
  // _inputs.readUndoButton();     // ReadUndoButton();    // sets undo to true
  // if
  //                               // button is pressed.
  // _inputs.readPlayerButtons();  // ReadPlayerButtons();
  //                               // if one of the player buttons is pressed,
  //                               // the playerButton variable is set to the
  //                               // player number.

  // _mode2Functions.m2PlayerButtons(
  // _gameState->getPlayerButton() /* playerButton */);
  // _mode2Functions.m2Loop();  // May want this on, may not.
  _gameState->setNow(GameTimer::gameMillis());  // now =
  if (_gameState->getTieBreakOnly() == 0) {
    _gameState->setTieBreak(1);  // tieBreak = true;
    _mode1TieBreaker.tieBreakEnable();
    _gameState->setTieBreakOnly(1);  // tieBreakOnly = true;
  }
  mode1();
}

void GameModes::mode4() {
  _gameState->setNow(GameTimer::gameMillis());  // now =
  if (_gameState->getTieBreakOnly() == 0) {
    _gameState->setTieBreak(1);  // tieBreak = true;
    _mode1TieBreaker.tieBreakEnable();
    _gameState->setTieBreakOnly(1);  // tieBreakOnly = true;
  }
  mode1();
}

void GameModes::testStart() {
  if (_gameState->getStarted() == 0) {  // if not started...
    _iniReader.OpenFile("C:\\Users\\EG\\Desktop\\2022\\may\\4th_week\\log_"
                        "viewer_sand\\test.ini");
    _player1->setPoints(
        std::stoi(_iniReader.GetString("TieBreak", "player1_points")));
    _player2->setPoints(
        std::stoi(_iniReader.GetString("TieBreak", "player1_points")));
    _player1->setGames(
        std::stoi(_iniReader.GetString("TieBreak", "player1_games")));
    _player2->setGames(
        std::stoi(_iniReader.GetString("TieBreak", "player2_games")));
    _player1->setSets(
        std::stoi(_iniReader.GetString("TieBreak", "player1_sets")));
    _player2->setSets(
        std::stoi(_iniReader.GetString("TieBreak", "player2_sets")));
    _logger->logUpdate("updating points, games and set LEDs...", __FUNCTION__);
    _pointLeds.updatePoints();
    _gameLeds.updateGames();
    _setLeds.updateSets();
    _gameState->setTieBreakOnly(0);
    _gameState->setStarted(1);
  }
}

void GameModes::noCode() {
  // SerialObject Serial;
  // Serial.println("No Code");
  _player1->setPoints(_player1->getPoints() + 1);  // p1Points++;
  _pointLeds.updatePoints();                       // UpdatePoints();
  GameTimer::gameDelay(1000);
  _player1->setPoints(_player1->getPoints() - 1);  // p1Points--;
  _pointLeds.updatePoints();                       // UpdatePoints();
  GameTimer::gameDelay(1000);
}

void GameModes::setGameMode(int rotaryPosition) {
  // SerialObject Serial;
  // std::cout << "switching to rotaryPosition: " << rotaryPosition <<
  // std::endl;
  switch (rotaryPosition) {
    case 0:
      break;

    case 1:
      // Serial.println("Game Mode 1");
      std::cout << "calling gameStart()..." << std::endl;
      gameStart();  // sets gameStart to true. resets player and score board.
      std::cout << "Game Mode 1" << std::endl;
      mode1();
      break;

    case 2:  // Game mode 2 (test mode)
             // std::cout << "Game Mode 2" << std::endl;
      gameStart();
      mode2();
      // Serial.println("Game Mode 2");
      break;

    case 3:  // Game mode 3 (Not yet written)
             // Serial.println("Game Mode 3 redirecting to Mode1...");
      gameStart();
      mode1();
      // Mode2();
      // noCode();
      break;

    case 4:  // Game mode 4 (Not yet written)
             // Serial.println("Game Mode 4");
             //   gameStart();
             //   mode4();
             // Mode2();
             // noCode();
      testStart();
      mode1();
      break;

    case 5:  // Game mode 5 (Not yet written)
             // Serial.println("Game Mode 5");
             // Mode2();
      noCode();
      break;
  }
}