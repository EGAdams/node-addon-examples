#pragma once
#include "GameTimer.h"
#include <chrono>
#include <iostream>
#include <thread>

GameTimer::GameTimer() {}
GameTimer::~GameTimer() {}

void GameTimer::delay(int milliseconds) {
  // cout << "Sleeping for " << milliseconds << " milliseconds" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void GameTimer::sleep_until(int milliseconds) {
  // cout << "Sleeping until " << milliseconds << " milliseconds" << endl;
  std::this_thread::sleep_until(std::chrono::system_clock::now() +
                                std::chrono::milliseconds(milliseconds));
}

unsigned long GameTimer::millis(int placeHolder) {
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now().time_since_epoch());
  return ms.count();
}
