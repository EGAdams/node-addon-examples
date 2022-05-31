#include "GameTimer.h"
#include <chrono>
#include <iostream>
#include <thread>
#include "Arduino.h"

GameTimer::GameTimer() {}

void GameTimer::gameDelay(int milliseconds) {
  std::cout << "Sleeping for " << milliseconds << " milliseconds" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
  // delay( milliseconds ); // TODO: find out if we can use Arduino delay()
  // here. delay( milliseconds ); delay( milliseconds );
  //_arduino->gameDelay( milliseconds );
}
GameTimer::~GameTimer() {}

void GameTimer::sleep_until(int milliseconds) {
  // cout << "Sleeping until " << milliseconds << " milliseconds" << endl;
  // std::this_thread::sleep_until(std::chrono::system_clock::now() +
  //                               std::chrono::milliseconds(milliseconds));
  // sleep_until( milliseconds );
}

unsigned long GameTimer::gameMillis() {
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now().time_since_epoch());
  std::cout << "gameMillis(): " << ms.count() << std::endl;
  return ms.count();
  // return millis( placeHolder );
  // return millis(); // TODO: find out if we can use Arduino's millis() here.
  // return _arduino->gameMillis();
  // return 1000;
}
