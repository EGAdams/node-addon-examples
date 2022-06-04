#ifndef History_h
#define History_h

#include <stack>
#include "GameState.h"

class History {
 public:
  History();
  ~History();
  void push(GameState gameState);
  GameState pop();
  int size();

 private:
  std::stack<GameState> _history;
};

#endif
