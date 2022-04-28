#include <iostream>
#include "DIGI_V6_15.h"
#include "SET_LEDs.h"

SetLeds::SetLeds( Player *player1, Player *player2, PinInterface *pinInterface ) :
    _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ){}

SetLeds::~SetLeds() {}

void SetLeds::updateSets() {
    switch ( _player1->getSets() /* p1Sets */ ) {
    case 0:
        _pinInterface->digitalWrite( P1_SETS_LED1, LOW );
        _pinInterface->digitalWrite( P1_SETS_LED2, LOW );
        // Serial.println("p1Sets 0");
        break;
    case 1:
        _pinInterface->digitalWrite( P1_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P1_SETS_LED2, LOW );
        // Serial.println("p1Sets 1");
        break;
    case 2:
        _pinInterface->digitalWrite( P1_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P1_SETS_LED2, HIGH );
        // Serial.println("p1Sets 2");
        break;
    case 3:
        _pinInterface->digitalWrite( P1_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P1_SETS_LED2, HIGH );
        // Serial.println("p1Sets 3");
        break;
    }

    switch ( _player2->getSets() /* p2Sets */ ) {
    case 0:
        _pinInterface->digitalWrite( P2_SETS_LED1, LOW );
        _pinInterface->digitalWrite( P2_SETS_LED2, LOW );
        break;
    case 1:
        _pinInterface->digitalWrite( P2_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P2_SETS_LED2, LOW );
        break;
    case 2:
        _pinInterface->digitalWrite( P2_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P2_SETS_LED2, HIGH );
        break;
    case 3:
        _pinInterface->digitalWrite( P2_SETS_LED1, HIGH );
        _pinInterface->digitalWrite( P2_SETS_LED2, HIGH );
        break;
    }
}
