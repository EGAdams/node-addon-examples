#include <iostream>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include "SET_LEDs.h"

SetLeds::SetLeds( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
    _player1( player1 ),
    _player2( player2 ),
    _digiFunctions( digiFunctions ) {}


SetLeds::~SetLeds() {}

void SetLeds::setPlayers( Player *player1, Player *player2 ) {
    _player1   = player1;
    _player2   = player2; }

void SetLeds::updateSets() {
    switch ( _player1->getSets() /* p1Sets */ ) {
    case 0:
        _digiFunctions->digitalWrite( P1_SETS_LED1, LOW );
        _digiFunctions->digitalWrite( P1_SETS_LED2, LOW );
        // Serial.println("p1Sets 0");
        break;
    case 1:
        _digiFunctions->digitalWrite( P1_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P1_SETS_LED2, LOW );
        // Serial.println("p1Sets 1");
        break;
    case 2:
        _digiFunctions->digitalWrite( P1_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P1_SETS_LED2, HIGH );
        // Serial.println("p1Sets 2");
        break;
    case 3:
        _digiFunctions->digitalWrite( P1_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P1_SETS_LED2, HIGH );
        // Serial.println("p1Sets 3");
        break;
    }

    switch ( _player2->getSets() /* p2Sets */ ) {
    case 0:
        _digiFunctions->digitalWrite( P2_SETS_LED1, LOW );
        _digiFunctions->digitalWrite( P2_SETS_LED2, LOW );
        break;
    case 1:
        _digiFunctions->digitalWrite( P2_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P2_SETS_LED2, LOW );
        break;
    case 2:
        _digiFunctions->digitalWrite( P2_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P2_SETS_LED2, HIGH );
        break;
    case 3:
        _digiFunctions->digitalWrite( P2_SETS_LED1, HIGH );
        _digiFunctions->digitalWrite( P2_SETS_LED2, HIGH );
        break;
    }
}
