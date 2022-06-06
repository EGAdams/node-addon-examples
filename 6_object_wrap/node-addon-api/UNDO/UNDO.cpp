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
  _gameState->setP1PointsMem(
      /* p1PointsMem */ _player1->getPoints());  // = p1Points;
  _gameState->setP2PointsMem(
      /* p2PointsMem */ _player2->getPoints());  // = p2Points;
  _gameState->setP1GamesMem(
      /* p1GamesMem  */ _player1->getGames());  // = p1Games;
  _gameState->setP2GamesMem(
      /* p2GamesMem  */ _player2->getGames());  // = p2Games;
  _gameState->setP1SetsMem(/* p1SetsMem   */ _player1->getSets());  // = p1Sets;
  _gameState->setP2SetsMem(/* p2SetsMem   */ _player2->getSets());  // = p2Sets;
  _gameState->setTieBreakMem(
      _gameState->getTieBreak());  // tieBreakMem    = tieBreak;
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

  //   _gameState->setPrev3PointFlash(
  //       _gameState->getPrev2PointFlash());  // prev3PointFlash =
  //       prev2PointFlash;
  //   _gameState->setPrev3P1Points(
  //       _gameState->getPrev2P1Points());  // prev3P1Points = prev2P1Points;
  //   _gameState->setPrev3P2Points(
  //       _gameState->getPrev2P2Points());  // prev3P2Points = prev2P2Points;
  //   _gameState->setPrev3P1Games(
  //       _gameState->getPrev2P1Games());  // prev3P1Games = prev2P1Games;
  //   _gameState->setPrev3P2Games(
  //       _gameState->getPrev2P2Games());  // prev3P2Games = prev2P2Games;
  //   _gameState->setPrev3P1Sets(
  //       _gameState->getPrev2P1Sets());  // prev3P1Sets = prev2P1Sets;
  //   _gameState->setPrev3P2Sets(
  //       _gameState->getPrev2P2Sets());  // prev3P2Sets = prev2P2Sets;
  //   _gameState->setPrev3P1Matches(
  //       _gameState->getPrev2P1Matches());  // prev3P1Matches =
  //       prev2P1Matches;
  //   _gameState->setPrev3P2Matches(
  //       _gameState->getPrev2P2Matches());  // prev3P2Matches =
  //       prev2P2Matches;
  //   _gameState->setPrev3Serve(
  //       _gameState->getPrev2Serve());  // prev3Serve = prev2Serve;
  //   _gameState->setPrev3TieBreak(
  //       _gameState->getPrev2TieBreak());  // prev3TieBreak = prev2TieBreak;
  //   _gameState->setPrev3SetTieBreak(
  //       _gameState
  //           ->getPrev2SetTieBreak());  // rev3SetTieBreak = prev2SetTieBreak;
  //   _gameState->setPrev3TieLEDsOn(
  //       _gameState->getPrev2TieLEDsOn());  // prev3TieLEDsOn =
  //       prev2TieLEDsOn;

  //   _gameState->setPrev2PointFlash(
  //       _gameState
  //           ->getPrev1PointFlash());  //  prev2PointFlash  = prev1PointFlash;
  //   _gameState->setPrev2P1Points(
  //       _gameState->getPrev1P1Points());  //  prev2P1Points    =
  //       prev1P1Points;
  //   _gameState->setPrev2P2Points(
  //       _gameState->getPrev1P2Points());  //  prev2P2Points    =
  //       prev1P2Points;
  //   _gameState->setPrev2P1Games(
  //       _gameState->getPrev1P1Games());  //  prev2P1Games     = prev1P1Games;
  //   _gameState->setPrev2P2Games(
  //       _gameState->getPrev1P2Games());  //  prev2P2Games     = prev1P2Games;
  //   _gameState->setPrev2P1Sets(
  //       _gameState->getPrev1P1Sets());  //  prev2P1Sets      = prev1P1Sets;
  //   _gameState->setPrev2P2Sets(
  //       _gameState->getPrev1P2Sets());  //  prev2P2Sets      = prev1P2Sets;
  //   _gameState->setPrev2P1Matches(
  //       _gameState->getPrev1P1Matches());  //  prev2P1Matches   =
  //       prev1P1Matches;
  //   _gameState->setPrev2P2Matches(
  //       _gameState->getPrev1P2Matches());  //  prev2P2Matches   =
  //       prev1P2Matches;
  //   _gameState->setPrev2Serve(
  //       _gameState->getPrev1Serve());  //  prev2Serve       = prev1Serve;
  //   _gameState->setPrev2TieBreak(
  //       _gameState->getPrev1TieBreak());  //  prev2TieBreak    =
  //       prev1TieBreak;
  //   _gameState->setPrev2SetTieBreak(
  //       _gameState
  //           ->getPrev1SetTieBreak());  //  prev2SetTieBreak =
  //           prev1SetTieBreak;
  //   _gameState->setPrev2TieLEDsOn(
  //       _gameState->getPrev1TieLEDsOn());  //  prev2TieLEDsOn   =
  //       prev1TieLEDsOn;

  //   _gameState->setPrev1PointFlash(
  //       _gameState->getPrevPointFlash());  // prev1PointFlash =
  //       prevPointFlash;
  //   _gameState->setPrev1P1Points(
  //       _gameState->getPrevP1Points());  // prev1P1Points   = prevP1Points;
  //   _gameState->setPrev1P2Points(
  //       _gameState->getPrevP2Points());  // prev1P2Points   = prevP2Points;
  //   _gameState->setPrev1P1Games(
  //       _gameState->getPrevP1Games());  // prev1P1Games = prevP1Games;
  //   _gameState->setPrev1P2Games(
  //       _gameState->getPrevP2Games());  // prev1P2Games = prevP2Games;
  //   _gameState->setPrev1P1Sets(
  //       _gameState->getPrevP1Sets());  // prev1P1Sets = prevP1Sets;
  //   _gameState->setPrev1P2Sets(
  //       _gameState->getPrevP2Sets());  // prev1P2Sets = prevP2Sets;
  //   _gameState->setPrev1P1Matches(
  //       _gameState->getPrevP1Matches());  // prev1P1Matches = prevP1Matches;
  //   _gameState->setPrev1P2Matches(
  //       _gameState->getPrevP2Matches());  // prev1P2Matches = prevP2Matches;
  //   _gameState->setPrev1Serve(
  //       _gameState->getPrevServe());  // prev1Serve = prevServe;
  //   _gameState->setPrev1TieBreak(
  //       _gameState->getPrevTieBreak());  // prev1TieBreak = prevTieBreak;
  //   _gameState->setPrev1SetTieBreak(
  //       _gameState->getPrevSetTieBreak());  // prev1SetTieBreak =
  //       prevSetTieBreak;
  //   _gameState->setPrev1TieLEDsOn(
  //       _gameState->getPrevTieLEDsOn());  // prev1TieLEDsOn = prevTieLEDsOn;

  //   _gameState->setPrevPointFlash(
  //       _gameState->getPointFlash());  // prevPointFlash  = pointFlash;
  //   _gameState->setPrevP1Points(
  //       _player1->getPoints());  // prevP1Points    = p1Points;
  //   _gameState->setPrevP2Points(
  //       _player2->getPoints());  // prevP2Points    = p2Points;
  //   _gameState->setPrevP1Games(
  //       _player1->getGames());  // prevP1Games     = p1Games;
  //   _gameState->setPrevP2Games(
  //       _player2->getGames());                       // prevP2Games     =
  //       p2Games;
  //   _gameState->setPrevP1Sets(_player1->getSets());  // prevP1Sets      =
  //   p1Sets; _gameState->setPrevP2Sets(_player2->getSets());  // prevP2Sets =
  //   p2Sets; _gameState->setPrevP1Matches(
  //       _player1->getMatches());  // prevP1Matches   = p1Matches;
  //   _gameState->setPrevP2Matches(
  //       _player2->getMatches());  // prevP2Matches   = p2Matches;
  //   _gameState->setPrevServe(_gameState->getServe());  // prevServe       =
  //   serve; _gameState->setPrevTieBreak(
  //       _gameState->getTieBreak());  // prevTieBreak    = tieBreak;
  //   _gameState->setPrevSetTieBreak(
  //       _gameState->getSetTieBreak());  // prevSetTieBreak = setTieBreak;
  //   _gameState->setPrevTieLEDsOn(
  //       _gameState->getTieLEDsOn());  // prevTieLEDsOn   = tieLEDsOn;
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
  //   _gameState->setPointFlash(
  //       /* pointFlash = */ _gameState->getPrevPointFlash() /* prevPointFlash
  //       */);
  //   _player1->setPoints(
  //       /* p1Points   = */ _gameState->getPrevP1Points() /* prevP1Points */);
  //   _player2->setPoints(
  //       /* p2Points   = */ _gameState->getPrevP2Points() /* prevP2Points */);
  //   _player1->setGames(
  //       /* p1Games    = */ _gameState->getPrevP1Games() /* prevP1Games */);
  //   _player2->setGames(
  //       /* p2Games    = */ _gameState->getPrevP2Games() /* prevP2Games */);
  //   _player1->setSets(
  //       /* p1Sets     = */ _gameState->getPrevP1Sets() /*  prevP1Sets    */);
  //   _player2->setSets(
  //       /* p2Sets     = */ _gameState->getPrevP2Sets() /* prevP2Sets     */);
  //   _player1->setMatches(
  //       /* p1Matches  = */ _gameState->getPrevP1Matches() /* prevP1Matches
  //       */);
  //   _player2->setMatches(
  //       /* p2Matches  = */ _gameState->getPrevP2Matches() /* prevP2Matches
  //       */);
  //   _gameState->setServe(
  //       /* serve      = */ _gameState->getPrevServe() /* prevServe      */);
  //   _gameState->setTieBreak(
  //       /* tieBreak   = */ _gameState->getPrevTieBreak() /* prevTieBreak */);
  //   _gameState->setSetTieBreak(
  //       /*setTieBreak = */ _gameState->getPrevSetTieBreak() /*
  //       prevSetTieBreak*/);
  //   _gameState->setTieLEDsOn(
  //       /*tieLEDsOn   = */ _gameState->getPrevTieLEDsOn() /* prevTieLEDsOn
  //       */);

  //   std::cout << "checking point flash..." << std::endl;
  //   _gameState->setPrevPointFlash(
  //       _gameState->getPrev1PointFlash());  // prevPointFlash =
  //       prev1PointFlash;
  //   _gameState->setPrevP1Points(
  //       _gameState->getPrev1P1Points());  // prevP1Points = prev1P1Points;
  //   _gameState->setPrevP2Points(
  //       _gameState->getPrev1P2Points());  // prevP2Points = prev1P2Points;
  //   _gameState->setPrevP1Games(
  //       _gameState->getPrev1P1Games());  // prevP1Games = prev1P1Games;
  //   _gameState->setPrevP2Games(
  //       _gameState->getPrev1P2Games());  // prevP2Games = prev1P2Games;
  //   _gameState->setPrevP1Sets(
  //       _gameState->getPrev1P1Sets());  // prevP1Sets = prev1P1Sets;
  //   _gameState->setPrevP2Sets(
  //       _gameState->getPrev1P2Sets());  // prevP2Sets = prev1P2Sets;
  //   _gameState->setPrevP1Matches(
  //       _gameState->getPrev1P1Matches());  // prevP1Matches = prev1P1Matches;
  //   _gameState->setPrevP2Matches(
  //       _gameState->getPrev1P2Matches());  // prevP2Matches = prev1P2Matches;
  //   _gameState->setPrevServe(
  //       _gameState->getPrev1Serve());  // prevServe = prev1Serve;
  //   _gameState->setPrevTieBreak(
  //       _gameState->getPrev1TieBreak());  // prevTieBreak = prev1TieBreak;
  //   _gameState->setPrevSetTieBreak(
  //       _gameState
  //           ->getPrev1SetTieBreak());  // prevSetTieBreak = prev1SetTieBreak;
  //   _gameState->setPrevTieLEDsOn(
  //       _gameState->getPrev1TieLEDsOn());  // prevTieLEDsOn = prev1TieLEDsOn;
  //   std::cout << "done checking point flash." << std::endl;
  //   _gameState->setPrev1PointFlash(
  //       _gameState->getPrev2PointFlash());  // prev1PointFlash =
  //       prev2PointFlash;
  //   _gameState->setPrev1P1Points(
  //       _gameState->getPrev2P1Points());  // prev1P1Points = prev2P1Points;
  //   _gameState->setPrev1P2Points(
  //       _gameState->getPrev2P2Points());  // prev1P2Points = prev2P2Points;
  //   _gameState->setPrev1P1Games(
  //       _gameState->getPrev2P1Games());  // prev1P1Games = prev2P1Games;
  //   _gameState->setPrev1P2Games(
  //       _gameState->getPrev2P2Games());  // prev1P2Games = prev2P2Games;
  //   _gameState->setPrev1P1Sets(
  //       _gameState->getPrev2P1Sets());  // prev1P1Sets = prev2P1Sets;
  //   _gameState->setPrev1P2Sets(
  //       _gameState->getPrev2P2Sets());  // prev1P2Sets = prev2P2Sets;
  //   _gameState->setPrev1P1Matches(
  //       _gameState->getPrev2P1Matches());  // prev1P1Matches =
  //       prev2P1Matches;
  //   _gameState->setPrev1P2Matches(
  //       _gameState->getPrev2P2Matches());  // prev1P2Matches =
  //       prev2P2Matches;
  //   _gameState->setPrev1Serve(
  //       _gameState->getPrev2Serve());  // prev1Serve = prev2Serve;
  //   std::cout << "done checking point flash." << std::endl;
  //   _gameState->setPrev1TieBreak(
  //       _gameState->getPrev2TieBreak());  // prev1TieBreak = prev2TieBreak;
  //   _gameState->setPrev1SetTieBreak(
  //       _gameState
  //           ->getPrev2SetTieBreak());  // prev1SetTieBreak =
  //           prev2SetTieBreak;
  //   _gameState->setPrev1TieLEDsOn(
  //       _gameState->getPrev2TieLEDsOn());  // prev1TieLEDsOn =
  //       prev2TieLEDsOn;

  //   _gameState->setPrev2PointFlash(
  //       _gameState->getPrev3PointFlash());  // prev2PointFlash =
  //       prev3PointFlash;
  //   _gameState->setPrev2P1Points(
  //       _gameState->getPrev3P1Points());  // prev2P1Points = prev3P1Points;
  //   _gameState->setPrev2P2Points(
  //       _gameState->getPrev3P2Points());  // prev2P2Points = prev3P2Points;
  //   _gameState->setPrev2P1Games(
  //       _gameState->getPrev3P1Games());  // prev2P1Games = prev3P1Games;
  //   _gameState->setPrev2P2Games(
  //       _gameState->getPrev3P2Games());  // prev2P2Games = prev3P2Games;
  //   std::cout << "done checking point flash 4." << std::endl;
  //   _gameState->setPrev2P1Sets(
  //       _gameState->getPrev3P1Sets());  // prev2P1Sets = prev3P1Sets;
  //   _gameState->setPrev2P2Sets(
  //       _gameState->getPrev3P2Sets());  // prev2P2Sets = prev3P2Sets;
  //   std::cout << "done checking point flash 5." << std::endl;
  //   _gameState->setPrev2P1Matches(
  //       _gameState->getPrev3P1Matches());  // prev2P1Matches =
  //       prev3P1Matches;
  //   _gameState->setPrev2P2Matches(
  //       _gameState->getPrev3P2Matches());  // prev2P2Matches =
  //       prev3P2Matches;
  //   std::cout << "done checking point flash 6." << std::endl;
  //   _gameState->setPrev2Serve(
  //       _gameState->getPrev3Serve());  // prev2Serve = prev3Serve;
  //   _gameState->setPrev2TieBreak(
  //       _gameState->getPrev3TieBreak());  // prev2TieBreak = prev3TieBreak;
  //   _gameState->setPrev2SetTieBreak(
  //       _gameState
  //           ->getPrev3SetTieBreak());  // prev2SetTieBreak =
  //           prev3SetTieBreak;
  //   std::cout << "done checking point flash 7." << std::endl;
  //   _gameState->setPrev2TieLEDsOn(
  //       _gameState->getPrev3TieLEDsOn());  // prev2TieLEDsOn =
  //       prev3TieLEDsOn;

  if (_gameState->getTieLEDsOn() == 1 /* tieLEDsOn == true */) {
    // _mode1TieBreaker.tieLEDsOn();  // TieLEDsOn();
    _gameState->setTieLEDsOn(1);  // tieLEDsOn = true;
    _tieLeds.turnOn();
  }
  if (_gameState->getTieLEDsOn() == 0 /* tieLEDsOn == false */) {
    // _mode1TieBreaker.tieLEDsOff(); // TieLEDsOff();
    _tieLeds.turnOff();
    _gameState->setTieLEDsOn(0);  // tieLEDsOn = false;
  }
  _logger->logUpdate("updating leds...", __FUNCTION__);
  _pointLeds.updatePoints();    // UpdatePoints();
  _gameLeds.updateGames();      // UpdateGames();
  _setLeds.updateSets();        // UpdateSets();
  _serveLeds.updateServeLED();  // UpdateServeLED();
}
