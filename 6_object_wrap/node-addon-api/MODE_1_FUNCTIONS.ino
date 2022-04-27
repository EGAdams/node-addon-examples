#include <iostream>
#include <chrono>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#ifndef SERVE_LEDS_HEADER_
#define SERVE_LEDS_HEADER_
//#include "SERVE_LEDs.h"
#endif

#include "MODE_1_FUNCTIONS.h"
#include "Serial.h"

Mode1Functions::Mode1Functions( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
    _mode1Score( player1, player2, digiFunctions ),
    _undo(       player1, player2, digiFunctions ),
    _gameState(  digiFunctions->getGameState() ),
    _player1(    player1 ),
    _player2(    player2 ),
    _pointLeds(  player1, player2, digiFunctions ) {}

Mode1Functions::~Mode1Functions() {
    SerialObject Serial;
    Serial.println( "Mode 1 destructor" );
}

void Mode1Functions::mode1ButtonFunction() {
    SerialObject Serial;
    switch ( _gameState->getPlayerButton() /* playerButton */ ) {

    case 0:
        break;

    case 1:
        _undo.setMode1Undo();
        if ( _gameState->getPointFlash() == 1 /* *_pointFlash == true */ ) {
            _gameState->setPointFlash( 0 );     // *_pointFlash = false;
            _player1->setPoints( _gameState->getP1PointsMem() /* p1PointsMem */ ); // p1Points = p1PointsMem;
            _player2->setPoints( _gameState->getP2PointsMem() /* p2PointsMem */ ); // p2Points = p2PointsMem;
            _pointLeds.updatePoints();
        }

        Serial.println(" p1 button up" );
        _digiFunctions.gameDelay( buttonDelay );
        _player1->setPoints( _player1->getPoints() + 1 ); // p1Points++;
        _undo.memory();
        _mode1Score.mode1P1Score();
        break;

    case 2:
        Serial.println( "p1 button undo" );
        _digiFunctions.gameDelay( buttonDelay );
        _undo.mode1Undo();  // Mode1Undo();
        break;

    case 3:
        _undo.setMode1Undo();       // SetMode1Undo();
        if ( _gameState->getPointFlash() == 1 /* pointFlash == true */ ) {
            _gameState->setPointFlash( 0 ); // pointFlash = false;
            _player1->setPoints( _gameState->getP1PointsMem() /* p1PointsMem */ );  // p1Points = p1PointsMem;
            _player2->setPoints( _gameState->getP2PointsMem() /* p2PointsMem */ );  // p2Points = p2PointsMem;
            _pointLeds.updatePoints();           // UpdatePoints();
        }

        Serial.println( "p2 button up" );
        _digiFunctions.gameDelay( buttonDelay );
        _player2->setPoints( _player2->getPoints() + 1 );   // p2Points++;
        _undo.memory();                                     // Memory();
        _mode1Score.mode1P2Score();                         // Mode1P2Score();
        break;

    case 4:
        Serial.println( "p2 button undo" );
        _digiFunctions.gameDelay( buttonDelay );
        _undo.mode1Undo();                                  // Mode1Undo();
        break;
    }
    _gameState->setPlayerButton( 0 );                       // playerButton = 0;
}

void Mode1Functions::mode1ServeFunction() {
    //SetMode1Undo();
    //ServeSwitch();
}


void Mode1Functions::pointFlash() {
    if ( _gameState->getPointFlash() == 1 /* pointFlash == true */ ) {
        if ( _player1->getPoints() /* p1Points */ > 3 ) {
            // if ( now - previous_time > flashDelay ) {
            if ( _gameState->getNow() /* now */ - _gameState->getPreviousTime() > flashDelay ) {
                if ( _gameState->getToggle() /* toggle */ == 0) {
                    _player1->setPoints( 99 );  // p1Points = 99;
                    _pointLeds.updatePoints();  // UpdatePoints();
                    _gameState->setToggle( 1 ); // toggle = 1;
                }
                else {
                    _player1->setPoints( _gameState->getP1PointsMem() /* p1PointsMem */ ); // p1Points = p1PointsMem;
                    _pointLeds.updatePoints();          //  UpdatePoints();
                    _gameState->setToggle( 0 );         // toggle = 0;
                }
                _gameState->setPreviousTime( _gameState->getNow() /* now */ );     // previous_time = now;
            }
        }

        if ( _player2->getPoints() /* p2Points */ > 3) {
            // if ( now - previous_time > flashDelay ) {
            if ( _gameState->getNow() /* now */ - _gameState->getPreviousTime() > flashDelay ) {
                if ( _gameState->getToggle() /* toggle */ == 0 ) {
                    _player2->setPoints( 99 );  // p2Points = 99;
                    _pointLeds.updatePoints();  // UpdatePoints();
                    _gameState->setToggle( 1 ); // toggle = 1;
                }
                else {
                    _player2->setPoints( _gameState->getP2PointsMem() /* p2PointsMem */ ); // p2Points = p2PointsMem;
                    _pointLeds.updatePoints();          //  UpdatePoints();
                    _gameState->setToggle( 0 );         // toggle = 0;
                }
                _gameState->setPreviousTime( _gameState->getNow() /* now */ );     // previous_time = now;
            }
        }
    }
}

