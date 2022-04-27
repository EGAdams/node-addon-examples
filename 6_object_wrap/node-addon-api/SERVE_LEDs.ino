#include <iostream>
#include <string>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include "SERVE_LEDs.h"

ServeLeds::ServeLeds( DigiFunctions *digiFunctions ) :
                      _digiFunctions( digiFunctions ),
                      _gameState( digiFunctions->getGameState() ) {}
ServeLeds::~ServeLeds() {}    

void ServeLeds::updateServeLED() {
    if ( _gameState->getServe() /* serve */ == 0 ) {
        _digiFunctions->digitalWrite( P1_SERVE, HIGH );
        _digiFunctions->digitalWrite( P2_SERVE, LOW );
    }
    else {
        _digiFunctions->digitalWrite( P1_SERVE, LOW );
        _digiFunctions->digitalWrite( P2_SERVE, HIGH );
    }
}

void ServeLeds::serveSwitch() {
    if ( _gameState->getServeSwitch() /* serveSwitch */ >= 2 ) {
        if ( _gameState->getServe() /* serve */ == 0 ) {
            _gameState->setServe( 1 ); // serve = 1;
        }
        else {
            _gameState->setServe( 0 ); // serve = 0;
        }
        _gameState->setServeSwitch( 0 ); // serveSwitch = 0;
    }
    updateServeLED();
}
