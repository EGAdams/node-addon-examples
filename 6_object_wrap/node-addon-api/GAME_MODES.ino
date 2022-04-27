
#include <iostream>
#include <chrono>
#include "DIGI_V6_15.h"
#include "MODE_1_TIEBREAKER.h"
#include "SERVE_LEDs.h"
#include "Serial.h"
#include "INPUTS.h"
#include "GAME_MODES.h"

GameModes::~GameModes() {}
GameModes::GameModes( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
                      _player1( player1 ),
                      _player2( player2 ),
                      _gameState( digiFunctions->getGameState()),
                      _digiFunctions( digiFunctions ),
                      _inputs(          player1, player2, digiFunctions ), 
                      _gameLeds(        player1, player2, digiFunctions ), 
                      _pointLeds(       player1, player2, digiFunctions ), 
                      _setLeds(         player1, player2, digiFunctions ),
                      _mode1TieBreaker( player1, player2, digiFunctions ),
                      _mode1Functions(  player1, player2, digiFunctions ),
                      _mode2Functions(  player1, player2, digiFunctions ),
                      _undo(            player1, player2, digiFunctions ),
                      _serveLeds(                         digiFunctions ) {}

void GameModes::gameStart() {
    if ( _gameState->getStarted() == 0 /* gameStart == true */ ) { // if not started...
        std::cout << "resetting points, games and set counters to zero..." << std::endl;
        _player1->setPoints( 0 );   // p1Points = 0;
        _player2->setPoints( 0 );   // p2Points = 0;
        _player1->setGames(  0 );   // p1Games = 0;
        _player2->setGames(  0 );   // p2Games = 0;
        _player1->setSets(   0 );   // p1Sets = 0;
        _player2->setSets(   0 );   // p2Sets = 0;
        std::cout << "updating points, games and set LEDs..." << std::endl;
        _digiFunctions->clearPinState();  // clear the pin state map
        _pointLeds.updatePoints();  // UpdatePoints();
        _gameLeds.updateGames();    // UpdateGames();
        _setLeds.updateSets();      // UpdateSets();
        _gameState->setTieBreakOnly( 0 ); // tieBreakOnly = false;
        std::cout << "setting game started flag..." << std::endl;
        _gameState->setStarted( 1 );    // gameStart = false; // set to started.
    }
}

void GameModes::mode1() {
    _gameState->setNow( _digiFunctions->millis( 1 )); // now = 
    _inputs.readUndoButton();   // ReadUndoButton();
    if ( _gameState->getUndo() == 1 /* undo == true */ ) { // undo button pressed
        _gameState->setUndo( 0 );   // undo = false;
        _undo.mode1Undo(); }        // Mode1Undo();
    
    _inputs.readPlayerButtons();    // digital read on player buttons.  sets playerButton if tripped.
    _serveLeds.serveSwitch();       // ServeSwitch(); // if serveSwitch >= 2, serveSwitch = 0; and toggle serve variable

    if ( _gameState->getTieBreak() == 1  /* tieBreak == true */ ) {
        _mode1TieBreaker.tieBreaker(); } // TieBreaker();
    
    if ( _gameState->getSetTieBreak() /* setTieBreak == true */ == 1 ) {
        _mode1TieBreaker.setTieBreaker();       // SetTieBreaker();
    } else {
        _mode1Functions.mode1ButtonFunction();  // Mode1ButtonFunction();
        _mode1Functions.pointFlash();           // PointFlash();
    }
}

void GameModes::mode2() {
    SerialObject Serial;
    Serial.println( " Starting Mode2." );
    _inputs.readUndoButton();    // ReadUndoButton();    // sets undo to true if button is pressed.
    _inputs.readPlayerButtons(); // ReadPlayerButtons();  
                                 // if one of the player buttons is pressed, 
                                 // the playerButton variable is set to the player number.

    _mode2Functions.m2PlayerButtons( _gameState->getPlayerButton() /* playerButton */ );
    _mode2Functions.m2Loop();  // May want this on, may not.
}

void GameModes::mode4() {
    _gameState->setNow( _digiFunctions->millis( 1 )); // now = 
    if ( _gameState->getTieBreakOnly() == 0 ) {
        _gameState->setTieBreak( 1 ); // tieBreak = true;
        _mode1TieBreaker.tieBreakEnable();
        _gameState->setTieBreakOnly( 1 ); // tieBreakOnly = true;
    }
    mode1(); }

void GameModes::noCode() {
    SerialObject Serial;
    Serial.println("No Code");
    _player1->setPoints( _player1->getPoints() + 1 ); // p1Points++;
    _pointLeds.updatePoints();  // UpdatePoints();
    _digiFunctions->gameDelay( 1000 );
    _player1->setPoints( _player1->getPoints() - 1 ); // p1Points--;
    _pointLeds.updatePoints();      // UpdatePoints();
    _digiFunctions->gameDelay( 1000 );
}


void GameModes::setGameMode( int rotaryPosition ) {
    SerialObject Serial;
    // std::cout << "switching to rotaryPosition: " << rotaryPosition << std::endl;
    switch ( rotaryPosition ) {
    case 0:
        break;

    case 1:
        // Serial.println( "Game Mode 1" );
        gameStart(); // sets gameStart to true. resets player and score board.
        mode1();
        break;

    case 2: // Game mode 2 (test mode)
        std::cout << "Game Mode 2" << std::endl;
        gameStart();
        mode2();
        Serial.println( "Game Mode 2" );
        break;

    case 3: // Game mode 3 (Not yet written)
        Serial.println( "Game Mode 3 redirecting to Mode1..." );
        gameStart();
        mode1();
        //Mode2();
        //noCode();
        break;

    case 4: // Game mode 4 (Not yet written)
        Serial.println( "Game Mode 4" );
        gameStart();
        mode4();
        //Mode2();
        //noCode();
        break;

    case 5: // Game mode 5 (Not yet written)
        Serial.println( "Game Mode 5" );
        //Mode2();
        noCode();
        break;
    }
}