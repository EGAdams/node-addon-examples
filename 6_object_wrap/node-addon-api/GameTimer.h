#ifndef GameTimer_h
#define GameTimer_h

class GameTimer {
 public:
  GameTimer();
  void sleep_until(int milliseconds);
  void sleep(int milliseconds);
  ~GameTimer();
};

#endif