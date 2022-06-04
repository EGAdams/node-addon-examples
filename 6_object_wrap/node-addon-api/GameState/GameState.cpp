#include "GameState.h"
#include "Arduino.h"

GameState::~GameState() {}
GameState::GameState(Player* player1, Player* player2)
    : _player1(player1), _player2(player2) {
  _player1 = player1;
  _player2 = player2;
  _pointFlash = 0;
  _serve = 0;
  _tieBreak = 0;
  _setTieBreak = 0;
  _tieLEDsOn = 0;
  _started = 0;
  _serveSwitch = 1;
  _playerButton = 0;
  _undo = 0;
  _freezePlayerButton = 0;
  _prev3TieLEDsOn = 0;  // = false;
  _prev2TieLEDsOn = 0;  // = false;
  _prev1TieLEDsOn = 0;  // = false;
  _prevTieLEDsOn = 0;   // = false;
  _prevSetTieBreak = 0;
  _prev1SetTieBreak = 0;
  _prev2SetTieBreak = 0;
  _prev3SetTieBreak = 0;
  _prev3TieBreak = 0;
  _prev2TieBreak = 0;
  _prev1TieBreak = 0;
  _prevTieBreak = 0;

  _prevPointFlash = 0;
  _prevP1Points = 0;
  _prevP2Points = 0;
  _prevP1Games = 0;
  _prevP2Games = 0;
  _prevP1Sets = 0;
  _prevP2Sets = 0;
  _prevP1Matches = 0;
  _prevP2Matches = 0;
  _prevServe = 0;

  _winDelay = 1000;
  _updateDisplayDelay = 700;
  _buttonDelay = 300;
  _flashDelay = 1000;
  _gameFlashDelay = 250;
  _tiePulseCount = 3;
  _gameWinPulseCount = 3;
  _setWinPulseCount = 3;
  _matchWinPulseCount = 5;

  _prev1PointFlash = 0;
  _prev1P1Points = 0;
  _prev1P2Points = 0;
  _prev1P1Games = 0;
  _prev1P2Games = 0;
  _prev1P1Sets = 0;
  _prev1P2Sets = 0;
  _prev1P1Matches = 0;
  _prev1P2Matches = 0;
  _prev1Serve = 0;

  _tieBreakMem = 0;
  _setTieBreakMem = 0;
  _p1PointsMem = 0;
  _p2PointsMem = 0;
  _p1GamesMem = 0;
  _p2GamesMem = 0;
  _p1SetsMem = 0;
  _p2SetsMem = 0;

  _prev3PointFlash = 0;  //  = prev2PointFlash;
  _prev3P1Points = 0;    // = prev2P1Points;
  _prev3P2Points = 0;    // = prev2P2Points;
  _prev3P1Games = 0;     // = prev2P1Games;
  _prev3P2Games = 0;     //  = prev2P2Games;
  _prev3P1Sets = 0;      // = prev2P1Sets;
  _prev3P2Sets = 0;      // = prev2P2Sets;
  _prev3P1Matches = 0;   // = prev2P1Matches;
  _prev3P2Matches = 0;   // = prev2P2Matches;
  _prev3Serve = 0;       // = prev2Serve;
}

void GameState::setGameWinPulseCount(int gameWinPulseCount) {
  _gameWinPulseCount = gameWinPulseCount;
}

int GameState::getGameWinPulseCount() {
  return _gameWinPulseCount;
}

void GameState::setSetWinPulseCount(int setWinPulseCount) {
  _setWinPulseCount = setWinPulseCount;
}

int GameState::getSetWinPulseCount() {
  return _setWinPulseCount;
}

void GameState::setMatchWinPulseCount(int matchWinPulseCount) {
  _matchWinPulseCount = matchWinPulseCount;
}

int GameState::getMatchWinPulseCount() {
  return _matchWinPulseCount;
}

void GameState::setTiePulseCount(int tiePulseCount) {
  _tiePulseCount = tiePulseCount;
}
int GameState::getTiePulseCount() {
  return _tiePulseCount;
}

void GameState::setButtonDelay(int buttonDelay) {
  _buttonDelay = buttonDelay;
}
int GameState::getButtonDelay() {
  return _buttonDelay;
}

void GameState::setFlashDelay(unsigned long flashDelay) {
  _flashDelay = flashDelay;
}
unsigned long GameState::getFlashDelay() {
  return _flashDelay;
}

void GameState::setUpdateDisplayDelay(int updateDisplayDelay) {
  _updateDisplayDelay = updateDisplayDelay;
}

int GameState::getUpdateDisplayDelay() {
  return _updateDisplayDelay;
}

void GameState::setWinDelay(int winDelay) {
  _winDelay = winDelay;
}

int GameState::getWinDelay() {
  return _winDelay;
}

void GameState::setPointFlash(int pointFlash) {
  _pointFlash = pointFlash;
}
int GameState::getPointFlash() {
  return _pointFlash;
}
void GameState::setServe(int serve) {
  _serve = serve;
}
int GameState::getServe() {
  return _serve;
}
void GameState::setTieBreak(int tieBreak) {
  _tieBreak = tieBreak;
}
int GameState::getTieBreak() {
  return _tieBreak;
}
void GameState::setSetTieBreak(int setTieBreak) {
  _setTieBreak = setTieBreak;
}
int GameState::getSetTieBreak() {
  return _setTieBreak;
}
void GameState::setTieLEDsOn(int tieLEDsOn) {
  _tieLEDsOn = tieLEDsOn;
}
int GameState::getTieLEDsOn() {
  return _tieLEDsOn;
}
void GameState::setServeSwitch(int serveSwitch) {
  _serveSwitch = serveSwitch;
}
int GameState::getServeSwitch() {
  return _serveSwitch;
}
void GameState::setPlayerButton(int playerButton) {
  _playerButton = playerButton;
}
int GameState::getPlayerButton() {
  return _playerButton;
}
void GameState::setStarted(int started) {
  _started = started;
}
int GameState::getStarted() {
  return _started;
}
void GameState::setUndo(int undo) {
  _undo = undo;
}
int GameState::getUndo() {
  return _undo;
}
void GameState::setRotaryChange(int rotaryChange) {
  _rotaryChange = rotaryChange;
}
int GameState::getRotaryChange() {
  return _rotaryChange;
}
int GameState::getRotaryPosition() {
  return _rotaryPosition;
}
void GameState::setRotaryPosition(int rotaryPosition) {
  _rotaryPosition = rotaryPosition;
}
void GameState::setPreviousTime(unsigned long previousTime) {
  _previousTime = previousTime;
}
void GameState::setPrevRotaryPosition(int prevRotaryPosition) {
  _prevRotaryPosition = prevRotaryPosition;
}
int GameState::getPrevRotaryPosition() {
  return _prevRotaryPosition;
}
unsigned long GameState::getPreviousTime() {
  return _previousTime;
}
void GameState::setFreezePlayerButton(int freezePlayerButton) {
  _freezePlayerButton = freezePlayerButton;
}
int GameState::getFreezePlayerButton() {
  return _freezePlayerButton;
}
void GameState::setP1PointsMem(int p1PointsMem) {
  _p1PointsMem = p1PointsMem;
}
int GameState::getP1PointsMem() {
  return _p1PointsMem;
}
void GameState::setP2PointsMem(int p2PointsMem) {
  _p2PointsMem = p2PointsMem;
}
int GameState::getP2PointsMem() {
  return _p2PointsMem;
}
void GameState::setP1GamesMem(int p1GamesMem) {
  _p1GamesMem = p1GamesMem;
}
int GameState::getP1GamesMem() {
  return _p1GamesMem;
}
void GameState::setP2GamesMem(int p2GamesMem) {
  _p2GamesMem = p2GamesMem;
}
int GameState::getP2GamesMem() {
  return _p2GamesMem;
}
void GameState::setP1SetsMem(int p1SetsMem) {
  _p1SetsMem = p1SetsMem;
}
int GameState::getP1SetsMem() {
  return _p1SetsMem;
}
void GameState::setP2SetsMem(int p2SetsMem) {
  _p2SetsMem = p2SetsMem;
}
int GameState::getP2SetsMem() {
  return _p2SetsMem;
}
void GameState::setNow(unsigned long now) {
  _now = now;
}
unsigned long GameState::getNow() {
  return _now;
}
void GameState::setToggle(int toggle) {
  _toggle = toggle;
}
int GameState::getToggle() {
  return _toggle;
}
void GameState::setTieBreakOnly(int tieBreakOnly) {
  _tieBreakOnly = tieBreakOnly;
}
int GameState::getTieBreakOnly() {
  return _tieBreakOnly;
}

// _prev3TieLEDsOn      = 0; // = false;
void GameState::setPrev3TieLEDsOn(int prev3TieLEDsOn) {
  _prev3TieLEDsOn = prev3TieLEDsOn;
}
int GameState::getPrev3TieLEDsOn() {
  return _prev3TieLEDsOn;
}

// _prev2TieLEDsOn      = 0; // = false;

void GameState::setPrev2TieLEDsOn(int prev2TieLEDsOn) {
  _prev2TieLEDsOn = prev2TieLEDsOn;
}
int GameState::getPrev2TieLEDsOn() {
  return _prev2TieLEDsOn;
}
// _prev1TieLEDsOn      = 0; // = false;

void GameState::setPrev1TieLEDsOn(int prev1TieLEDsOn) {
  _prev1TieLEDsOn = prev1TieLEDsOn;
}
int GameState::getPrev1TieLEDsOn() {
  return _prev1TieLEDsOn;
}

// _prevTieLEDsOn       = 0; // = false;

int GameState::getPrevTieLEDsOn() {
  return _prevTieLEDsOn;
}
void GameState::setPrevTieLEDsOn(int prevTieLEDsOn) {
  _prevTieLEDsOn = prevTieLEDsOn;
}

// _prev1SetTieBreak    = 0;

int GameState::getPrev1SetTieBreak() {
  return _prev1SetTieBreak;
}
void GameState::setPrev1SetTieBreak(int prev1SetTieBreak) {
  _prev1SetTieBreak = prev1SetTieBreak;
}

// _prev2SetTieBreak    = 0;

void GameState::setPrev2SetTieBreak(int prev2SetTieBreak) {
  _prev2SetTieBreak = prev2SetTieBreak;
}
int GameState::getPrev2SetTieBreak() {
  return _prev2SetTieBreak;
}

// _prev3SetTieBreak    = 0;

void GameState::setPrev3SetTieBreak(int prev3SetTieBreak) {
  _prev3SetTieBreak = prev3SetTieBreak;
}
int GameState::getPrev3SetTieBreak() {
  return _prev3SetTieBreak;
}

// _prev3TieBreak       = 0;

void GameState::setPrev3TieBreak(int prev3TieBreak) {
  _prev3TieBreak = prev3TieBreak;
}
int GameState::getPrev3TieBreak() {
  return _prev3TieBreak;
}

// _prev2TieBreak       = 0;
void GameState::setPrev2TieBreak(int prev2TieBreak) {
  _prev2TieBreak = prev2TieBreak;
}
int GameState::getPrev2TieBreak() {
  return _prev2TieBreak;
}

// _prev1TieBreak       = 0;
void GameState::setPrev1TieBreak(int prev1TieBreak) {
  _prev1TieBreak = prev1TieBreak;
}
int GameState::getPrev1TieBreak() {
  return _prev1TieBreak;
}

// _prevTieBreak        = 0;
void GameState::setPrevTieBreak(int prevTieBreak) {
  _prevTieBreak = prevTieBreak;
}
int GameState::getPrevTieBreak() {
  return _prevTieBreak;
}

// _prevSetTieBreak     = 0;
void GameState::setPrevSetTieBreak(int prevSetTieBreak) {
  _prevSetTieBreak = prevSetTieBreak;
}
int GameState::getPrevSetTieBreak() {
  return _prevSetTieBreak;
}

void GameState::setPrevPointFlash(int prevPointFlash) {
  _prevPointFlash = prevPointFlash;
}
int GameState::getPrevPointFlash() {
  return _prevPointFlash;
}
void GameState::setPrevP1Points(int prevP1Points) {
  _prevP1Points = prevP1Points;
}
int GameState::getPrevP1Points() {
  return _prevP1Points;
}
void GameState::setPrevP2Points(int prevP2Points) {
  _prevP2Points = prevP2Points;
}
int GameState::getPrevP2Points() {
  return _prevP2Points;
}
void GameState::setPrevP1Games(int prevP1Games) {
  _prevP1Games = prevP1Games;
}
int GameState::getPrevP1Games() {
  return _prevP1Games;
}
void GameState::setPrevP2Games(int prevP2Games) {
  _prevP2Games = prevP2Games;
}
int GameState::getPrevP2Games() {
  return _prevP2Games;
}
void GameState::setPrevP1Sets(int prevP1Sets) {
  _prevP1Sets = prevP1Sets;
}
int GameState::getPrevP1Sets() {
  return _prevP1Sets;
}
void GameState::setPrevP2Sets(int prevP2Sets) {
  _prevP2Sets = prevP2Sets;
}
int GameState::getPrevP2Sets() {
  return _prevP2Sets;
}
void GameState::setPrevP1Matches(int prevP1Matches) {
  _prevP1Matches = prevP1Matches;
}
int GameState::getPrevP1Matches() {
  return _prevP1Matches;
}
void GameState::setPrevP2Matches(int prevP2Matches) {
  _prevP2Matches = prevP2Matches;
}
int GameState::getPrevP2Matches() {
  return _prevP2Matches;
}
void GameState::setPrevServe(int prevServe) {
  _prevServe = prevServe;
}
int GameState::getPrevServe() {
  return _prevServe;
}

void GameState::setPrev1PointFlash(int prev1PointFlash) {
  _prev1PointFlash = prev1PointFlash;
}
int GameState::getPrev1PointFlash() {
  return _prev1PointFlash;
}
void GameState::setPrev1P1Points(int prev1P1Points) {
  _prev1P1Points = prev1P1Points;
}
int GameState::getPrev1P1Points() {
  return _prev1P1Points;
}
void GameState::setPrev1P2Points(int prev1P2Points) {
  _prev1P2Points = prev1P2Points;
}
int GameState::getPrev1P2Points() {
  return _prev1P2Points;
}
void GameState::setPrev1P1Games(int prev1P1Games) {
  _prev1P1Games = prev1P1Games;
}
int GameState::getPrev1P1Games() {
  return _prev1P1Games;
}
void GameState::setPrev1P2Games(int prev1P2Games) {
  _prev1P2Games = prev1P2Games;
}
int GameState::getPrev1P2Games() {
  return _prev1P2Games;
}
void GameState::setPrev1P1Sets(int prev1P1Sets) {
  _prev1P1Sets = prev1P1Sets;
}
int GameState::getPrev1P1Sets() {
  return _prev1P1Sets;
}
void GameState::setPrev1P2Sets(int prev1P2Sets) {
  _prev1P2Sets = prev1P2Sets;
}
int GameState::getPrev1P2Sets() {
  return _prev1P2Sets;
}
void GameState::setPrev1P1Matches(int prev1P1Matches) {
  _prev1P1Matches = prev1P1Matches;
}
int GameState::getPrev1P1Matches() {
  return _prev1P1Matches;
}
void GameState::setPrev1P2Matches(int prev1P2Matches) {
  _prev1P2Matches = prev1P2Matches;
}
int GameState::getPrev1P2Matches() {
  return _prev1P2Matches;
}
void GameState::setPrev1Serve(int prev1Serve) {
  _prev1Serve = prev1Serve;
}
int GameState::getPrev1Serve() {
  return _prev1Serve;
}

void GameState::setTieBreakMem(int tieBreakMem) {
  _tieBreakMem = tieBreakMem;
}
int GameState::getTieBreakMem() {
  return _tieBreakMem;
}

void GameState::setSetTieBreakMem(int setTieBreakMem) {
  _setTieBreakMem = setTieBreakMem;
}
int GameState::getSetTieBreakMem() {
  return _setTieBreakMem;
}

void GameState::setPrev2PointFlash(int prev2PointFlash) {
  _prev2PointFlash = prev2PointFlash;
}
int GameState::getPrev2PointFlash() {
  return _prev2PointFlash;
}

void GameState::setPrev2P1Points(int prev2P1Points) {
  _prev2P1Points = prev2P1Points;
}
int GameState::getPrev2P1Points() {
  return _prev2P1Points;
}

void GameState::setPrev2P2Points(int prev2P2Points) {
  _prev2P2Points = prev2P2Points;
}
int GameState::getPrev2P2Points() {
  return _prev2P2Points;
}

void GameState::setPrev2P1Games(int prev2P1Games) {
  _prev2P1Games = prev2P1Games;
}
int GameState::getPrev2P1Games() {
  return _prev2P1Games;
}

void GameState::setPrev2P2Games(int prev2P2Games) {
  _prev2P2Games = prev2P2Games;
}
int GameState::getPrev2P2Games() {
  return _prev2P2Games;
}

void GameState::setPrev2P1Sets(int prev2P1Sets) {
  _prev2P1Sets = prev2P1Sets;
}
int GameState::getPrev2P1Sets() {
  return _prev2P1Sets;
}

void GameState::setPrev2P2Sets(int prev2P2Sets) {
  _prev2P2Sets = prev2P2Sets;
}
int GameState::getPrev2P2Sets() {
  return _prev2P2Sets;
}

void GameState::setPrev2P1Matches(int prev2P1Matches) {
  _prev2P1Matches = prev2P1Matches;
}
int GameState::getPrev2P1Matches() {
  return _prev2P1Matches;
}

void GameState::setPrev2P2Matches(int prev2P2Matches) {
  _prev2P2Matches = prev2P2Matches;
}
int GameState::getPrev2P2Matches() {
  return _prev2P2Matches;
}

void GameState::setPrev2Serve(int prev2Serve) {
  _prev2Serve = prev2Serve;
}
int GameState::getPrev2Serve() {
  return _prev2Serve;
}

void GameState::setPrev3PointFlash(int prev3PointFlash) {
  _prev3PointFlash = prev3PointFlash;
}
int GameState::getPrev3PointFlash() {
  return _prev3PointFlash;
}

void GameState::setPrev3P1Points(int prev3P1Points) {
  _prev3P1Points = prev3P1Points;
}
int GameState::getPrev3P1Points() {
  return _prev3P1Points;
}

void GameState::setPrev3P2Points(int prev3P2Points) {
  _prev3P2Points = prev3P2Points;
}
int GameState::getPrev3P2Points() {
  return _prev3P2Points;
}
void GameState::setPrev3P1Games(int prev3P1Games) {
  _prev3P1Games = prev3P1Games;
}
int GameState::getPrev3P1Games() {
  return _prev3P1Games;
}
void GameState::setPrev3P2Games(int prev3P2Games) {
  _prev3P2Games = prev3P2Games;
}
int GameState::getPrev3P2Games() {
  return _prev3P2Games;
}
void GameState::setPrev3P1Sets(int prev3P1Sets) {
  _prev3P1Sets = prev3P1Sets;
}
int GameState::getPrev3P1Sets() {
  return _prev3P1Sets;
}
void GameState::setPrev3P2Sets(int prev3P2Sets) {
  _prev3P2Sets = prev3P2Sets;
}
int GameState::getPrev3P2Sets() {
  return _prev3P2Sets;
}
void GameState::setPrev3P1Matches(int prev3P1Matches) {
  _prev3P1Matches = prev3P1Matches;
}
int GameState::getPrev3P1Matches() {
  return _prev3P1Matches;
}
void GameState::setPrev3P2Matches(int prev3P2Matches) {
  _prev3P2Matches = prev3P2Matches;
}
int GameState::getPrev3P2Matches() {
  return _prev3P2Matches;
}
void GameState::setPrev3Serve(int prev3Serve) {
  _prev3Serve = prev3Serve;
}
int GameState::getPrev3Serve() {
  return _prev3Serve;
}

void GameState::setGameFlashDelay(int gameFlashDelay) {
  _gameFlashDelay = gameFlashDelay;
}
int GameState::getGameFlashDelay() {
  return _gameFlashDelay;
}
