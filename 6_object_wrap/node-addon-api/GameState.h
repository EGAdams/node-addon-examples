#ifndef GAMESTATE_H
#define GAMESTATE_H

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

#pragma once

class GameState {
 public:
  GameState();
  GameState(Player* player1, Player* player2);
  ~GameState();

  void setPointFlash(int pointFlash);
  int getPointFlash();
  void setServe(int serve);
  int getServe();
  void setTieBreak(int tieBreak);
  int getTieBreak();
  void setTieLEDsOn(int tieLEDsOn);
  int getTieLEDsOn();
  void setServeSwitch(int serveSwitch);
  int getServeSwitch();
  void setPlayerButton(int playerButton);
  int getPlayerButton();
  void setUndo(int undo);
  int getUndo();
  void setStarted(int started);
  int getStarted();
  void setSetTieBreak(int setTieBreak);
  int getSetTieBreak();
  void setRotaryChange(int rotaryChange);
  int getRotaryChange();
  void setPreviousTime(unsigned long previousTime);
  int getRotaryPosition();
  void setRotaryPosition(int rotaryPosition);
  int getPrevRotaryPosition();
  void setPrevRotaryPosition(int prevRotaryPosition);
  unsigned long getPreviousTime();
  int getFreezePlayerButton();
  void setFreezePlayerButton(int freezePlayerButton);
  void setP1PointsMem(int p1PointsMem);
  int getP1PointsMem();
  void setP2PointsMem(int p2PointsMem);
  int getP2PointsMem();
  void setP1GamesMem(int p1GamesMem);
  int getP1GamesMem();
  void setP2GamesMem(int p2GamesMem);
  int getP2GamesMem();
  void setP1SetsMem(int p1SetsMem);
  int getP1SetsMem();
  void setP2SetsMem(int p2SetsMem);
  int getP2SetsMem();
  void setNow(unsigned long now);
  unsigned long getNow();
  void setToggle(int toggle);
  int getToggle();
  int getTieBreakOnly();
  void setTieBreakOnly(int tieBreakOnly);

 private:
  Player* _player1;
  Player* _player2;
  int _pointFlash;
  int _serve;
  int _tieBreak;
  int _setTieBreak;
  int _tieLEDsOn;
  int _started;
  int _serveSwitch;
  int _playerButton;
  int _undo;
  int _gameStarted;
  int _rotaryPosition;
  int _prevRotaryPosition;
  int _rotaryChange;
  unsigned long _now;
  unsigned long _previousTime;
  int _freezePlayerButton;
  int _p1PointsMem;
  int _p2PointsMem;
  int _p1GamesMem;
  int _p2GamesMem;
  int _p1SetsMem;
  int _p2SetsMem;
  int _toggle;
  int _tieBreakOnly;
};

#endif

// int _playerOnePoints;
// int _playerOneGames;
// int _playerOneSets;
// int _playerOneMatches;

// int _playerTwoPoints;
// int _playerTwoGames;
// int _playerTwoSets;
// int _playerTwoMatches;

// void setPlayerOnePoints( int points );
// int  getPlayerOnePoints();
// void setPlayerOneGames( int games );
// int  getPlayerOneGames();
// void setPlayerOneSets( int sets );
// int  getPlayerOneSets();
// void setPlayerOneMatches( int matches );
// int  getPlayerOneMatches();

// void setPlayerTwoPoints( int points );
// int  getPlayerTwoPoints();
// void setPlayerTwoGames( int games );
// int  getPlayerTwoGames();
// void setPlayerTwoSets( int sets );
// int  getPlayerTwoSets();
// void setPlayerTwoMatches( int matches );
// int  getPlayerTwoMatches();