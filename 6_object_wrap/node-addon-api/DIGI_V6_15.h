#pragma once
#ifndef DIGI_V6_15_H
#define DIGI_V6_15_H
// #include <string>
// typedef struct {
//   int key;
//   std::string value;
// } constantDictionary;
//
//  Written by Chris Bean for Teensy 4.1 only
//

// #define INPUT 0 // not in windows.. ouch!!
#define OUTPUT 0
#define LOW 0
#define HIGH 1
#define SIMULATION 1
#define PLAYER_BUTTONS 202  // changed from A2 to rid of compiler warning
#define ROTARY                                                                 \
  15  // changed from A15 to rid of compiler error in second line of setup()
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

//-----------------------------------------------------------------------------------------------
namespace {
// bool setTieBreak = false;
// bool tieBreak = false;
// bool tieLEDsOn = false;
bool prev3TieLEDsOn = false;
bool prev2TieLEDsOn = false;
bool prev1TieLEDsOn = false;
bool prevTieLEDsOn = false;

int prevSetTieBreak = 0;
int prev1SetTieBreak = 0;
int prev2SetTieBreak = 0;
int prev3SetTieBreak = 0;
int prev3TieBreak = 0;
int prev2TieBreak = 0;
int prev1TieBreak = 0;
int prevTieBreak = 0;

// int p1Points = 0;
// int p2Points = 0;
// int p1Games = 0;
// int p2Games = 0;
// int p1Sets = 0;
// int p2Sets = 0;
// int p1Matches = 0;
// int p2Matches = 0;
int p1TBGames = 0;
int p2TBGames = 0;
int prevP1TBGames = 0;
int prevP2TBGames = 0;
int prev1P1TBGames = 0;
int prev1P2TBGames = 0;
int prev2P1TBGames = 0;
int prev2P2TBGames = 0;
int prev3P1TBGames = 0;
int prev3P2TBGames = 0;

// Variables for Undo()
int undoPos = 0;
int prevPointFlash = 0;
int prevP1Points = 0;
int prevP2Points = 0;
int prevP1Games = 0;
int prevP2Games = 0;
int prevP1Sets = 0;
int prevP2Sets = 0;
int prevP1Matches = 0;
int prevP2Matches = 0;
int prevServe = 0;

int prev1PointFlash = 0;
int prev1P1Points = 0;
int prev1P2Points = 0;
int prev1P1Games = 0;
int prev1P2Games = 0;
int prev1P1Sets = 0;
int prev1P2Sets = 0;
int prev1P1Matches = 0;
int prev1P2Matches = 0;
int prev1Serve = 0;

int prev2PointFlash = 0;
int prev2P1Points = 0;
int prev2P2Points = 0;
int prev2P1Games = 0;
int prev2P2Games = 0;
int prev2P1Sets = 0;
int prev2P2Sets = 0;
int prev2P1Matches = 0;
int prev2P2Matches = 0;
int prev2Serve = 0;

int prev3PointFlash = 0;
int prev3P1Points = 0;
int prev3P2Points = 0;
int prev3P1Games = 0;
int prev3P2Games = 0;
int prev3P1Sets = 0;
int prev3P2Sets = 0;
int prev3P1Matches = 0;
int prev3P2Matches = 0;
int prev3Serve = 0;

bool gameStart = true;

// int sequenceTime = 4;
// int sequence = 0;
// int flashTime = 1000; // Use to control Win Sequence flash speeds when not
// using PWM. int flash = 0;

bool resetScoreBoard = false;

int modeP1 = 0;
int modeP2 = 0;
int p1Setting = 0;
int p2Setting = 0;

int rotaryValue = 0;
int rotaryPosition = 0;
int prevRotaryPosition = 0;
bool rotaryChange = false;

int buttonValue = 0;
int playerButton = 0;
bool buttonPress = false;
// bool undo = false;

int serveButtonValue = 0;
int serveButtonPress = 0;
// int serveSwitch = 1;
int serve = 0;

unsigned long previous_time = 0;
// unsigned long prev = 0;
unsigned long pointFlashPrev = 0;

/*--------------------------------------USER SELECTABLE
 * VARIABLES--------------------------------------*/

int buttonDelay = 20;         // 300;
int updateDisplayDelay = 20;  // 700;
int winDelay = 20;            // 1000;
// long matchWinDelay = 15000;
int flashDelay = 1000;  // SET TO 1000
int tiePulseCount = 3;
int GameWinPulseCount = 0 /* 3 */;
int SetWinPulseCount = 0 /* 3 */;
int MatchWinPulseCount = 5;

/*------------------------------------END USER SELECTABLE
 * VARIABLES------------------------------------*/
// int toggle = 0;
// bool pointFlash = false;
// bool p1PointFlash = false;
// bool p2PointFlash = false;
// int currentPulseCount = 0;
// int p1TBGamesMem = 0;
// int p2TBGamesMem = 0;
// int tieBreakMem = 0;
// int setTieBreakMem = 0;
// int p1PointsMem = 0;
// int p2PointsMem = 0;
// int p1GamesMem = 0;
// int p2GamesMem = 0;
// int p1SetsMem = 0;
// int p2SetsMem = 0;
// unsigned long now = 1000;
}  // namespace

#endif
