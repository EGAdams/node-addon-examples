#ifndef GameTimer_h
#define GameTimer_h

class GameTimer {
 public:
  GameTimer();
  void sleep_until(int milliseconds);
  static void delay(int milliseconds);
  static unsigned long millis(int default = 0);
  ~GameTimer();
};

#endif