#include <iostream>
#include "DIGI_V6_15.h"
#include "DigiFunctions.h"
#include "GAME_LEDs.h"
#include "Player.h"
#include "GameState.h"
#include "PinInterface.h"

GameLeds::~GameLeds() {}
GameLeds::GameLeds( Player *player1, Player *player2, PinInterface *pinInterface ) :
    _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ){}

void GameLeds::updateGames() {
    switch ( _player1->getGames() /* p1Games */ ) {
    case 0:
        _pinInterface->digitalWrite( P1_GAMES_LED0, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 0");
        break;
    case 1:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 1");
        break;
    case 2:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 2");
        break;
    case 3:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 3");
        break;
    case 4:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 4");
        break;
    case 5:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 5");
        break;
    case 6:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 6");
        break;
    case 7:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 7");
        break;
    case 8:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 8");
        break;
    case 9:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 9");
        break;
    case 10:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 10");
        break;
    case 11:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 11");
        break;
    case 12:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 12");
        break;
    case 13:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 12");
        break;
    case 14:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 12");
        break;
    case 15:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
        // Serial.println("p1Games 12");
        break;
    case 99:
        _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
        // Serial.println("p1Games 12");
        break;
    }

    switch ( _player2->getGames() /* p2Games */ ) {
    case 0:
        _pinInterface->digitalWrite( P2_GAMES_LED0, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 0");
        break;
    case 1:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 1");
        break;
    case 2:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 2");
        break;
    case 3:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 3");
        break;
    case 4:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 4");
        break;
    case 5:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 5");
        break;
    case 6:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 6");
        break;
    case 7:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 7");
        break;
    case 8:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 8");
        break;
    case 9:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 9");
        break;
    case 10:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 10");
        break;
    case 11:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 11");
        break;
    case 12:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 12");
        break;
    case 13:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 12");
        break;
    case 14:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 12");
        break;
    case 15:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
        _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
        // Serial.println("p2Games 12");
        break;
    case 99:
        _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
        _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
        // Serial.println("p2Games 12");
        break;
    }
}

//-------------------------------------------------------------------------------------------TIE BREAKER LED SEQUENCES
//
//void UpdateTBGames() {
//
//  switch (p1TBGames) {
//    case 0:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
//      // Serial.println("p1Games 0");
//      break;
//    case 1:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
//      // Serial.println("p1Games 1");
//      break;
//    case 2:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
//      // Serial.println("p1Games 2");
//      break;
//    case 3:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3,  HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED4,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6,  LOW );
//      // Serial.println("p1Games 3");
//      break;
//    case 4:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4,  HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED5,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6,  LOW );
//      // Serial.println("p1Games 4");
//      break;
//    case 5:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5,  HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6,  LOW );
//      // Serial.println("p1Games 5");
//      break;
//    case 6:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5,  LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6,  HIGH );
//      // Serial.println("p1Games 6");
//      break;
//    case 7:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 7");
//      break;
//    case 8:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 8");
//      break;
//    case 9:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 9");
//      break;
//    case 10:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 10");
//      break;
//    case 11:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 11");
//      break;
//    case 12:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 12");
//      break;
//    case 13:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 12");
//      break;
//    case 14:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 12");
//      break;
//    case 15:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, HIGH );
//      // Serial.println("p1Games 12");
//      break;
//    case 99:
//      _pinInterface->digitalWrite( P1_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P1_GAMES_LED6, LOW );
//      // Serial.println("p1Games 99");
//      break;
//  }
//  
//  switch (p2TBGames) {
//    case 0:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 0");
//      break;
//    case 1:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 1");
//      break;
//    case 2:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 2");
//      break;
//    case 3:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 3");
//      break;
//    case 4:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 4");
//      break;
//    case 5:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 5");
//      break;
//    case 6:
//      _pinInterface->digitalWrite( P2_GAMES_LED0,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5,  LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6,  HIGH );
//      // Serial.println("p2Games 6");
//      break;
//    case 7:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 7");
//      break;
//    case 8:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 8");
//      break;
//    case 9:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 9");
//      break;
//    case 10:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 10");
//      break;
//    case 11:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 11");
//      break;
//    case 12:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 12");
//      break;
//    case 13:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 12");
//      break;
//    case 14:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 12");
//      break;
//    case 15:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, HIGH );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, HIGH );
//      // Serial.println("p2Games 12");
//      break;
//    case 99:
//      _pinInterface->digitalWrite( P2_GAMES_LED0, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED1, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED2, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED3, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED4, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED5, LOW );
//      _pinInterface->digitalWrite( P2_GAMES_LED6, LOW );
//      // Serial.println("p2Games 99");
//      break;
//  }
//}
