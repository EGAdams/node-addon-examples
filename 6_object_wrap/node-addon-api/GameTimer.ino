#pragma once
#include <chrono>
#include <thread>
#include <iostream>
#include "GameTimer.h"

GameTimer::GameTimer() {
    // cout << "GameTimer::GameTimer() called..." << endl;
}

void GameTimer::sleep( int milliseconds ) {
    // cout << "Sleeping for " << milliseconds << " milliseconds" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds( milliseconds ));
}
GameTimer::~GameTimer() {
    // cout << "GameTimer::GameTimer() called..." << endl;
}

void GameTimer::sleep_until( int milliseconds ) {
    // cout << "Sleeping until " << milliseconds << " milliseconds" << endl;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds( milliseconds ));
}
