#include "GameState.h"
// #include <string>

GameState::GameState() {}
GameState::GameState(Player* player1, Player* player2) {
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
  _gameStarted = 0;
  _freezePlayerButton = 0;
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
GameState::~GameState() {}
