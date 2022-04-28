#include <iostream>

#ifndef DIGI_V6_15_H_
#define DIGI_V6_15_H_
#include "DIGI_V6_15.h"
#endif

#include "POINT_LEDs.h"

PointLeds::PointLeds( Player *player1, Player *player2, PinInterface *pinInterface ) :
    _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ){}

PointLeds::~PointLeds() {}

void PointLeds::updatePoints() {
    switch ( _player1->getPoints() /* p1Points */ ) {
    case 0:
        _pinInterface->digitalWrite(P1_POINTS_LED1, HIGH);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, LOW);
        //      Serial.println("p1Points 0");
        break;
    case 1:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, HIGH);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, LOW);
        //      Serial.println("p1Points 1");
        break;
    case 2:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, HIGH);
        _pinInterface->digitalWrite(P1_POINTS_LED4, LOW);
        //      Serial.println("p1Points 2");
        break;
    case 3:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, HIGH);
        //      Serial.println("p1Points 3");
        break;
    case 4:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, HIGH);
        break;
    case 5:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, HIGH);
        //      Serial.println("p1Points 4");
        break;
    case 99:
        _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P1_POINTS_LED4, LOW);
        //      Serial.println("p1Points 4");
        break;
    }

    switch ( _player2->getPoints() /* p2Points */ ) {

    case 0:
        _pinInterface->digitalWrite(P2_POINTS_LED1, HIGH);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, LOW);
        //      Serial.println("p2Points 0");
        break;
    case 1:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, HIGH);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, LOW);
        //      Serial.println("p2Points 1");
        break;
    case 2:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, HIGH);
        _pinInterface->digitalWrite(P2_POINTS_LED4, LOW);
        //      Serial.println("p2Points 2");
        break;
    case 3:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, HIGH);
        //      Serial.println("p2Points 3");
        break;
    case 4:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, HIGH);
        break;
    case 5:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, HIGH);
        //      Serial.println("p2Points 4");
        break;
    case 99:
        _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
        _pinInterface->digitalWrite(P2_POINTS_LED4, LOW);
        //      Serial.println("p2Points 4");
        break;
    }
}

void PointLeds::updateTBPoints() {
    _pinInterface->digitalWrite(P1_POINTS_LED1, LOW);
    _pinInterface->digitalWrite(P1_POINTS_LED2, LOW);
    _pinInterface->digitalWrite(P1_POINTS_LED3, LOW);
    _pinInterface->digitalWrite(P1_POINTS_LED4, LOW);
    //      Serial.println("p1Points OFF");

    _pinInterface->digitalWrite(P2_POINTS_LED1, LOW);
    _pinInterface->digitalWrite(P2_POINTS_LED2, LOW);
    _pinInterface->digitalWrite(P2_POINTS_LED3, LOW);
    _pinInterface->digitalWrite(P2_POINTS_LED4, LOW);
    //      Serial.println("p2Points OFF");
}
