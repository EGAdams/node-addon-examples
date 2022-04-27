#include <iostream>
#include "DIGI_V6_15.h"
#include "RESET.h"
#include "DigiFunctions.h"

Reset::Reset( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
			  _player1( player1 ),
			  _player2( player2 ),
              _digiFunctions( digiFunctions ),
			  _gameState( digiFunctions->getGameState() ) {}
              
Reset::~Reset() {}

void Reset::resetScoreboard() {
    // SerialObject Serial;
    // Serial.println( "resetting score board..." );
    _digiFunctions->digitalWrite( P1_POINTS_LED1, LOW );
    _digiFunctions->digitalWrite( P1_POINTS_LED2, LOW );
    _digiFunctions->digitalWrite( P1_POINTS_LED3, LOW );
    _digiFunctions->digitalWrite( P1_POINTS_LED4, LOW ); ///////// <------- add a mapped for loop to flash Player 1 LED's ---<< 

    _digiFunctions->digitalWrite( P2_POINTS_LED1, LOW );
    _digiFunctions->digitalWrite( P2_POINTS_LED2, LOW );
    _digiFunctions->digitalWrite( P2_POINTS_LED3, LOW );
    _digiFunctions->digitalWrite( P2_POINTS_LED4, LOW );

    _digiFunctions->digitalWrite( P1_GAMES_LED0, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED1, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED2, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED3, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED4, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED5, LOW );
    _digiFunctions->digitalWrite( P1_GAMES_LED6, LOW );
    _digiFunctions->digitalWrite( P1_TIEBREAKER, LOW );

    _digiFunctions->digitalWrite( P2_GAMES_LED0, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED1, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED2, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED3, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED4, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED5, LOW );
    _digiFunctions->digitalWrite( P2_GAMES_LED6, LOW );
    _digiFunctions->digitalWrite( P2_TIEBREAKER, LOW );

    _digiFunctions->digitalWrite( P1_SETS_LED1, LOW );
    _digiFunctions->digitalWrite( P1_SETS_LED2, LOW );

    _digiFunctions->digitalWrite( P2_SETS_LED1, LOW );
    _digiFunctions->digitalWrite( P2_SETS_LED2, LOW );

    _digiFunctions->digitalWrite( P1_SERVE, LOW );
    _digiFunctions->digitalWrite( P2_SERVE, LOW );

    tieLEDsOff();                     // TieLEDsOff();

    _gameState->setTieBreak(     0 ); // tieBreak = false;
    _gameState->setSetTieBreak(  0 ); // setTieBreak = false;
    _gameState->setServeSwitch(  1 ); // serveSwitch = 1;
    _gameState->setServe(        0 ); // serve = 0;
    _gameState->setPlayerButton( 0 ); // playerButton = 0;
    _gameState->setStarted(/*1*/ 0 ); // gameStart = true; TODO: the placing of this is questionable
    _digiFunctions->gameDelay( 200 ); // delay( 200 );
}

void Reset::refresh() {
    // SerialObject Serial;
    if ( _gameState->getRotaryChange() == 1 /* rotaryChange == true */ ) {
        // Serial.println( "rotaryChange == true, setting to false..." );
        _gameState->setRotaryChange( 0 ); // rotaryChange = false;
        resetScoreboard();
        resetPreviousValues();
        _gameState->setTieBreakOnly( 0 );
    }
}

void Reset::tieLEDsOn() {
    _gameState->setTieLEDsOn( 1 ); // tieLEDsOn = true;
    _digiFunctions->digitalWrite( P1_TIEBREAKER, HIGH );
    _digiFunctions->digitalWrite( P2_TIEBREAKER, HIGH ); 
}

void Reset::tieLEDsOff() {
    _gameState->setTieLEDsOn( 0 ); // tieLEDsOn = false;
    _digiFunctions->digitalWrite( P1_TIEBREAKER, LOW );
    _digiFunctions->digitalWrite( P2_TIEBREAKER, LOW ); 
}

void Reset::resetPreviousValues() {
    prev3TieLEDsOn = false;
	prev2TieLEDsOn = false;
	prev1TieLEDsOn = false;
	prevTieLEDsOn = false;

	prevSetTieBreak = 0;
	prev1SetTieBreak = 0;
	prev2SetTieBreak = 0;
	prev3SetTieBreak = 0;
	prev3TieBreak = 0;
	prev2TieBreak = 0;
	prev1TieBreak = 0;
	prevTieBreak = 0;

	_player1->setPoints(  0 ); // p1Points = 0;
	_player2->setPoints(  0 ); // p2Points = 0;
	_player1->setGames(   0 ); // p1Games = 0;
	_player2->setGames(   0 ); // p2Games = 0;
	_player1->setSets(    0 ); // p1Sets = 0;
	_player2->setSets(    0 ); // p2Sets = 0;
	_player1->setMatches( 0 ); // p1Matches = 0;
	_player2->setMatches( 0 ); // p2Matches = 0;

	p1TBGames = 0;
	p2TBGames = 0;
	prevP1TBGames = 0;
	prevP2TBGames = 0;
	prev1P1TBGames = 0;
	prev1P2TBGames = 0;
	prev2P1TBGames = 0;
	prev2P2TBGames = 0;
	prev3P1TBGames = 0;
	prev3P2TBGames = 0;

	// Variables for Undo()
	undoPos = 0;
	prevPointFlash = 0;
	prevP1Points = 0;
	prevP2Points = 0;
	prevP1Games = 0;
	prevP2Games = 0;
	prevP1Sets = 0;
	prevP2Sets = 0;
	prevP1Matches = 0;
	prevP2Matches = 0;
	prevServe = 0;

	prev1PointFlash = 0;
	prev1P1Points = 0;
	prev1P2Points = 0;
	prev1P1Games = 0;
	prev1P2Games = 0;
	prev1P1Sets = 0;
	prev1P2Sets = 0;
	prev1P1Matches = 0;
	prev1P2Matches = 0;
	prev1Serve = 0;

	prev2PointFlash = 0;
	prev2P1Points = 0;
	prev2P2Points = 0;
	prev2P1Games = 0;
	prev2P2Games = 0;
	prev2P1Sets = 0;
	prev2P2Sets = 0;
	prev2P1Matches = 0;
	prev2P2Matches = 0;
	prev2Serve = 0;

	prev3PointFlash = 0;
	prev3P1Points = 0;
	prev3P2Points = 0;
	prev3P1Games = 0;
	prev3P2Games = 0;
	prev3P1Sets = 0;
	prev3P2Sets = 0;
	prev3P1Matches = 0;
	prev3P2Matches = 0;
	prev3Serve = 0;
}
