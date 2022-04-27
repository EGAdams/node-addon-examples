#include <iostream>
#include <string>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include "INPUTS.h"

Inputs::Inputs( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
                _gameState( digiFunctions->getGameState()),
                _digiFunctions( digiFunctions ),
                _reset( player1, player2, digiFunctions )  {}

Inputs::~Inputs(){};

void Inputs::readReset() {
    SerialObject Serial;
    Serial.println( "readReset()" );
    if ( _digiFunctions->digitalRead( RESET ) == LOW  ) {
        // Serial.println( "Reset press detected _digiFunctions->digitalRead( RESET ) == LOW infinite loop starts here..." );
        while (_digiFunctions->digitalRead( RESET ) == LOW ) {
            Serial.println( "waiting for reset release..." );
            _digiFunctions->gameDelay( 1000 );
        } // infinite loop
        Serial.println( "exited loop." );
        _digiFunctions->gameDelay( 1000 );
        _reset.resetScoreboard();
        _digiFunctions->clearPinState();
    }
    else {
        // Serial.println( "_digiFunctions->digitalRead( RESET ) != LOW" );
    }
}

void Inputs::readUndoButton() {
    SerialObject Serial;
    if ( _digiFunctions->digitalRead( UNDO ) == LOW  ) {
        Serial.println( "entering _digiFunctions->digitalRead( UNDO ) == LOW infinite loop...  waiting for it to go HIGH..." );
        // while ( _digiFunctions->digitalRead( UNDO ) == LOW  ) {}
        Serial.println( "broke out of loop." );
        _digiFunctions->gameDelay( 2000 );
        Serial.println( "setting undo to true." );
        _gameState->setUndo( 1 );                   // undo = true;
    } else {
        // Serial.println( "_digiFunctions->digitalRead( UNDO ) != LOW" );
    }
}

int Inputs::readRotary() {  // TODO: make this one read.
    SerialObject Serial;
    _gameState->setRotaryPosition( 0 );     // int rotaryPosition = 0;
    Serial.println( "reading rotary pin " + ROTARY );
    int rotaryAnalogValue = _digiFunctions->analogRead( ROTARY );
    if ( rotaryAnalogValue <= 100 ) { _gameState->setRotaryPosition( 1 ); } // rotaryPosition = 1
    if ( rotaryAnalogValue >= 350 && rotaryAnalogValue <= 450  ) { _gameState->setRotaryPosition( 2 ); /* rotaryPosition = 2 */; }
    if ( rotaryAnalogValue >= 550 && rotaryAnalogValue <= 700  ) { _gameState->setRotaryPosition( 3 ); /* rotaryPosition = 3 */; }
    if ( rotaryAnalogValue >= 750 && rotaryAnalogValue <= 800  ) { _gameState->setRotaryPosition( 4 ); /* rotaryPosition = 4 */; }
    if ( rotaryAnalogValue >= 850 && rotaryAnalogValue <= 1000 ) { _gameState->setRotaryPosition( 5 ); /* rotaryPosition = 5 */; }
    Serial.print( "rotaryPosition set to: " + _gameState->getRotaryPosition() /* rotaryPosition */ );
    // if ( rotaryPosition != prevRotaryPosition  ) {
    if ( _gameState->getRotaryPosition() != _gameState->getPrevRotaryPosition()) {
        _gameState->setRotaryChange( 1 );   // rotaryChange = true;
        _gameState->setPrevRotaryPosition( _gameState->getRotaryPosition() ); //  prevRotaryPosition = rotaryPosition;
        _reset.refresh();                    // set rotaryChange to false and reset the scoreboard
    }
    return _gameState->getRotaryPosition();
}

void Inputs::readPlayerButtons() {
    SerialObject Serial;
    Serial.println( "reading player buttons..." );
    int anlgPlyrBtnVal = _digiFunctions->analogRead( PLAYER_BUTTONS );
    if ( anlgPlyrBtnVal <= 1000 ) { // if one of the player buttons is pressed...
        Serial.println( "analog value of player button input: " + std::to_string( anlgPlyrBtnVal ) + ".");
        _digiFunctions->gameDelay( 20 );
        if ( anlgPlyrBtnVal <= 50                                ) { _gameState->setPlayerButton( 1 ); /* playerButton = 1 */ }
        else if ( anlgPlyrBtnVal >= 350 && anlgPlyrBtnVal <= 400 ) { _gameState->setPlayerButton( 2 ); /* playerButton = 2 */ }
        else if ( anlgPlyrBtnVal >= 550 && anlgPlyrBtnVal <= 650 ) { _gameState->setPlayerButton( 3 ); /* playerButton = 3 */ }
        else if ( anlgPlyrBtnVal >= 750 && anlgPlyrBtnVal <= 800 ) { _gameState->setPlayerButton( 4 ); /* playerButton = 4 */ }
        while ( _digiFunctions->analogRead( PLAYER_BUTTONS ) <= 1000  ) {
            Serial.println( "waiting for player button to release..." );
            _digiFunctions->gameDelay( 1000 );
        }
        std::string thePlayerButton = std::to_string( _gameState->getPlayerButton());
        Serial.println( "done reading buttons.  playerButton = " + thePlayerButton /* playerButton */ );
    }
}
