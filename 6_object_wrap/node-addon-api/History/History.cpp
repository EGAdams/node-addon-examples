#include "History.h"

History::History() {}
History::~History() {}

void History::push(GameState state) {
  _history.push(state);
}

int History::size() {
  return _history.size();
}

GameState History::pop() {
  GameState lastGameState = _history.top();
  _history.pop();
  return lastGameState;
}
