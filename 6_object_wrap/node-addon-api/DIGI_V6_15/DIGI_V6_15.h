#ifndef DIGI_V6_15_H
#define DIGI_V6_15_H
#include "Arduino.h"

//  Written by Chris Bean for Teensy 4.1 only
//  re-written in C++ by EG in June 2022

// #define INPUT 0 // not in windows.. ouch!!
// #define OUTPUT 0
#define LOW 0
#define HIGH 1

#if defined(_WIN32)
#define SIMULATION 1
#define PLAYER_BUTTONS 202
#define ROTARY 15
#define LOG_FILE_PATH                                                          \
  "C:\\Users\\EG\\Desktop\\2022\\may\\4th_week\\log_viewer_sand\\test.txt"
#else
#define SIMULATION 0
#define PLAYER_BUTTONS A2
#define ROTARY A15
#define LOG_FILE_PATH "unkown file system"
#endif

// #define SIMULATION 0
// #define PLAYER_BUTTONS A2 // 202 // changed from A2 to rid of compiler
// warning #define ROTARY A15        //15   // changed from A15 to rid of
// compiler error in second line of setup()
#define UNDO 26
#define RESET 38

//-----------------------------------------------------------------------------------------------
// The Prototype board uses the following pins:

#define P1_POINTS_LED1 22
#define P1_POINTS_LED2 23
#define P1_POINTS_LED3 0
#define P1_POINTS_LED4 1

#define P1_SERVE 19

#define P1_GAMES_LED0 31
#define P1_GAMES_LED1 18
#define P1_GAMES_LED2 15
#define P1_GAMES_LED3 14
#define P1_GAMES_LED4 41
#define P1_GAMES_LED5 37
#define P1_GAMES_LED6 36

#define P1_TIEBREAKER 33

#define P1_SETS_LED1 29
#define P1_SETS_LED2 25

#define P2_POINTS_LED1 21
#define P2_POINTS_LED2 20
#define P2_POINTS_LED3 3
#define P2_POINTS_LED4 2

#define P2_SERVE 4

#define P2_GAMES_LED0 32
#define P2_GAMES_LED1 5
#define P2_GAMES_LED2 6
#define P2_GAMES_LED3 7
#define P2_GAMES_LED4 8
#define P2_GAMES_LED5 9
#define P2_GAMES_LED6 10

#define P2_TIEBREAKER 11

#define P2_SETS_LED1 28
#define P2_SETS_LED2 12

#endif

// The Updated board uses the following pins:
/*
  #define P1_POINTS_LED1 22
  #define P1_POINTS_LED2 23
  #define P1_POINTS_LED3 0
  #define P1_POINTS_LED4 1

  #define P1_SERVE 19

  #define P1_GAMES_LED0 18
  #define P1_GAMES_LED1 15
  #define P1_GAMES_LED2 14
  #define P1_GAMES_LED3 41
  #define P1_GAMES_LED4 37
  #define P1_GAMES_LED5 36
  #define P1_GAMES_LED6 33

  #define P1_TIEBREAKER 32

  #define P1_SETS_LED1 29
  #define P1_SETS_LED2 25

  #define P2_POINTS_LED1 21
  #define P2_POINTS_LED2 20
  #define P2_POINTS_LED3 3
  #define P2_POINTS_LED4 2

  #define P2_SERVE 4

  #define P2_GAMES_LED0 5
  #define P2_GAMES_LED1 6
  #define P2_GAMES_LED2 7
  #define P2_GAMES_LED3 8
  #define P2_GAMES_LED4 9
  #define P2_GAMES_LED5 10
  #define P2_GAMES_LED6 11

  #define P2_TIEBREAKER 31


  #define P2_SETS_LED1 28
  #define P2_SETS_LED2 12
*/
