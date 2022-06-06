#include <DIGI_V6_15.h>
#include <GAME_LEDs.h>
#include <GAME_MODES.h>
#include <GameObject.h>
#include <GameState.h>
#include <GameTimer.h>
#include <INPUTS.h>
#include <MODE_1_FUNCTIONS.h>
#include <MODE_2_FUNCTIONS.h>
#include <MODE_1_SCORE.h>
#include <MODE_1_TIEBREAKER.h>
#include <Morse.h>
#include <PinInterface.h>
#include <PinState.h>
#include <Player.h>
#include <POINT_LEDs.h>
#include <RESET.h>
#include <ScoreBoard.h>
#include <SERVE_LEDs.h>
#include <SET_LEDs.h>
#include <UNDO.h>
#include <History.h>
#include <Logger.h>

void setup() {
    pinMode( PLAYER_BUTTONS, INPUT );
    pinMode( ROTARY, INPUT);
    pinMode( UNDO, INPUT );
    pinMode( RESET, INPUT ); 

    pinMode( P1_POINTS_LED1, OUTPUT );
    pinMode( P1_POINTS_LED2, OUTPUT );
    pinMode( P1_POINTS_LED3, OUTPUT );
    pinMode( P1_POINTS_LED4, OUTPUT ); 

    pinMode( P2_POINTS_LED1, OUTPUT );
    pinMode( P2_POINTS_LED2, OUTPUT );
    pinMode( P2_POINTS_LED3, OUTPUT );
    pinMode( P2_POINTS_LED4, OUTPUT ); 

    pinMode( P1_SERVE, OUTPUT );
    pinMode( P2_SERVE, OUTPUT ); 

    pinMode( P1_GAMES_LED0, OUTPUT );
    pinMode( P1_GAMES_LED1, OUTPUT );
    pinMode( P1_GAMES_LED2, OUTPUT );
    pinMode( P1_GAMES_LED3, OUTPUT );
    pinMode( P1_GAMES_LED4, OUTPUT );
    pinMode( P1_GAMES_LED5, OUTPUT );
    pinMode( P1_GAMES_LED6, OUTPUT );
    pinMode( P1_TIEBREAKER, OUTPUT ); 

    pinMode( P2_GAMES_LED0, OUTPUT );
    pinMode( P2_GAMES_LED1, OUTPUT );
    pinMode( P2_GAMES_LED2, OUTPUT );
    pinMode( P2_GAMES_LED3, OUTPUT );
    pinMode( P2_GAMES_LED4, OUTPUT );
    pinMode( P2_GAMES_LED5, OUTPUT );
    pinMode( P2_GAMES_LED6, OUTPUT );
    pinMode( P2_TIEBREAKER, OUTPUT ); 

    pinMode( P1_SETS_LED1, OUTPUT );
    pinMode( P1_SETS_LED2, OUTPUT ); 

    pinMode( P2_SETS_LED1, OUTPUT );
    pinMode( P2_SETS_LED2, OUTPUT ); 

    Serial.begin( 9600 ); }

GameObject gameObject;

void loop() { gameObject.loopGame(); }

/*
 * Version: 11
 * 
 * Monday June 6, 2022
 * 
 * Completely re-wrote undo functionality.  We are now able to undo an entire game.
 * 
 */

 