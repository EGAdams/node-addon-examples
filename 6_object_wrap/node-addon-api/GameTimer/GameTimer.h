#ifndef GameTimer_h
#define GameTimer_h
#include "Arduino.h"
class GameTimer {
 public:
  GameTimer();
  ~GameTimer();
  void sleep_until(int milliseconds);
  static void gameDelay(int milliseconds);
  static unsigned long gameMillis();
};

#endif