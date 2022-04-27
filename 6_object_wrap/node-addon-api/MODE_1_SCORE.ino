#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include <iostream>
#include "MODE_1_SCORE.h"

Mode1Score::Mode1Score( Player *player1, Player *player2, DigiFunctions *digiFunctions ) :
                       _player1( player1 ),
                       _player2( player2 ),
                       _gameState( digiFunctions->getGameState() ),
                       _pointLeds(         player1, player2, digiFunctions ),
                       _gameLeds(          player1, player2, digiFunctions ),
                       _setLeds(           player1, player2, digiFunctions ),
                       _mode1WinSequences( player1, player2, digiFunctions ),
                       _mode1TieBreaker(   player1, player2, digiFunctions ),
                       _undo(              player1, player2, digiFunctions ) {
}

Mode1Score::~Mode1Score() {}

void Mode1Score::mode1P1Score() {
    if ( _player1->getPoints() >= 3 /* p1Points >= 3 */ ) {
        if ( _player1->getPoints() == _player2->getPoints() /* p1Points == p2Points */ ) { 
            // Tie, Back to Deuce
            _player1->setPoints( 3 ); // p1Points = 3;
            _player2->setPoints( 3 ); // p2Points = 3;
        // } else if ( p1Points > 3 && ( p1Points - p2Points) > 1) { // Game win Scenario
        } else if ( _player1->getPoints() > 3 && ( _player1->getPoints() - _player2->getPoints() ) > 1 ) { // Game win Scenario
            _player1->setGames( _player1->getGames() + 1 ); // p1Games++;
            _undo.memory();
            _pointLeds.updatePoints();
            mode1P1Games();
        }

        if ( _player1->getPoints() /* p1Points */ == 4 ) {
            _gameState->setPointFlash( 1 );                           // pointFlash = true;
            _gameState->setPreviousTime( _digiFunctions.millis( 1 )); // now;
            _gameState->setToggle( 0 ); // toggle = 0;
        }
    }
    _pointLeds.updatePoints();
}

void Mode1Score::mode1P1Games() {
    _gameLeds.updateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); //  serveSwitch++;
    _digiFunctions.gameDelay( updateDisplayDelay );
    if ( _player1->getGames() /* p1Games */ >= 6 ) {
        if ( _player1->getGames() /* p1Games */ == 6 && _player2->getGames() /* p2Games */ == 6 ) {
            _gameState->setTieBreak( 1 ); // tieBreak = true;
            _mode1TieBreaker.tieBreakEnable();
        }
        if ( _gameState->getTieBreak() == 0 /* tieBreak == false */ ) {
            if (( _player1->getGames() - _player2->getGames() /* p1Games - p2Games */ ) > 1 ) {
                _player1->setSets( _player1->getSets() + 1 ); // p1Sets++;
                _setLeds.updateSets();
                _digiFunctions.gameDelay( updateDisplayDelay );
                if ( _player1->getSets() == _player2->getSets() /* p1Sets == p2Sets */ ) {
                    _mode1WinSequences.p1TBSetWinSequence(); // P1TBSetWinSequence();
                    _gameState->setTieBreak( 1 ); // setTieBreak = true;
                    _mode1TieBreaker.setTieBreakEnable();
                } else if ( _player1->getSets() == 2 /* p1Sets == 2 */ ) {
                    _mode1WinSequences.p1MatchWinSequence(); // P1MatchWinSequence();
                } else {
                    _setLeds.updateSets();                          // UpdateSets();
                    _digiFunctions.gameDelay( updateDisplayDelay ); // delay
                    _mode1WinSequences.p1SetWinSequence();          // P1SetWinSequence();
                    _setLeds.updateSets();                          // UpdateSets();
                    _digiFunctions.gameDelay( winDelay );           // delay
                    _player1->setPoints( 0 );                       // p1Points = 0;
                    _player2->setPoints( 0 );                       // p2Points = 0;
                }
                _player1->setGames( 0 );                            // p1Games = 0;
                _player2->setGames( 0 );                            // p2Games = 0;
            } else {
                _mode1WinSequences.p1GameWinSequence();             // P1GameWinSequence();
                _gameLeds.updateGames();                            // UpdateGames();
                _digiFunctions.gameDelay( updateDisplayDelay );     // delay( updateDisplayDelay );
                _player1->setPoints( 0 );                           // p1Points = 0;
                _player2->setPoints( 0 );                           // p2Points = 0;
            }
        }
    } else {
        _mode1WinSequences.p1GameWinSequence();                     // P1GameWinSequence();
        _gameLeds.updateGames();                                    // UpdateGames();
        _digiFunctions.gameDelay( updateDisplayDelay );             // delay( updateDisplayDelay );
        _player1->setPoints( 0 );                                   // p1Points = 0;
        _player2->setPoints( 0 );                                   // p2Points = 0;
    }
}

void Mode1Score::mode1TBP1Games() {
    _gameLeds.updateGames(); // UpdateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); // serveSwitch++;
    _digiFunctions.gameDelay( updateDisplayDelay );

    if ( _player1->getGames() == 15 /* p1Games == 15 */ ) {
        _player1->setSets( _player1->getSets() + 1 ); // p1Sets++;

        if ( _player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */ ) {
            _mode1TieBreaker.endTieBreak();          // EndTieBreak();
            _mode1WinSequences.p1TBSetWinSequence(); // P1TBSetWinSequence();
            _gameState->setTieBreak( 1 );            // setTieBreak = true;
            _mode1TieBreaker.setTieBreakEnable();    // SetTieBreakEnable();
        } else {
            _mode1WinSequences.p1SetWinSequence();   // P1SetWinSequence();
            _mode1TieBreaker.endTieBreak();          // EndTieBreak();
        }
    }

    // if ( p1Games >= 10 && ( p1Games - p2Games) > 1) {
    if ( _player1->getGames() >= 10 && ( _player1->getGames() - _player2->getGames() ) > 1) {
        _player1->setSets( _player1->getSets() + 1 ); // p1Sets++;
        if ( _player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */ ) {
            _mode1TieBreaker.endTieBreak();          // EndTieBreak();
            _mode1WinSequences.p1TBSetWinSequence(); // P1TBSetWinSequence();
            _gameState->setTieBreak( 1 );            // setTieBreak = true;
            _mode1TieBreaker.setTieBreakEnable();    // SetTieBreakEnable();
        } else {
            _mode1WinSequences.p1SetWinSequence();   // P1SetWinSequence();
            _mode1TieBreaker.endTieBreak();          // EndTieBreak();
        }
    }
}

void Mode1Score::mode1SetTBP1Games() {
    _gameLeds.updateGames();        // UpdateGames();
    _digiFunctions.gameDelay( updateDisplayDelay );

    if ( _player1->getGames() /* p1Games */ == 7) {
        _player1->setSets( _player1->getSets() + 1 ); // p1Sets++;
        _setLeds.updateSets();                        // UpdateSets();
        _digiFunctions.gameDelay( updateDisplayDelay );
        _mode1WinSequences.p1SetTBWinSequence();      // P1SetTBWinSequence();
        _mode1TieBreaker.tieLEDsOff();                // TieLEDsOff();
        _mode1WinSequences.p1MatchWinSequence();      // P1MatchWinSequence();
    }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); // serveSwitch++;
}

//----------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------RED RED RED RED RED RED RED

void Mode1Score::mode1P2Games() {
    _gameLeds.updateGames(); // UpdateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); //  serveSwitch++;
    _digiFunctions.gameDelay( updateDisplayDelay );

    if ( _player2->getGames() /* p2Games */ >= 6 ) {
        if ( _player2->getGames() /* p2Games */ == 6 && _player1->getGames() /* p1Games */ == 6 ) {
            _gameState->setTieBreak( 1 );       // tieBreak = true;
            _mode1TieBreaker.tieBreakEnable();  /* TieBreakEnable(); */ }
        if ( _gameState->getTieBreak() == 0 /* tieBreak == false */) {
            if (( _player2->getGames() /* p2Games */  - _player1->getGames() /* p1Games */ ) > 1 ) {
                _player2->setSets( _player2->getSets() + 1 ); // p2Sets++;
                _setLeds.updateSets();                        // UpdateSets();
                _digiFunctions.gameDelay( updateDisplayDelay );

                if ( _player2->getSets() == _player1->getSets() /* p2Sets == p1Sets */ ) {
                    _mode1WinSequences.p2TBSetWinSequence();    // P2TBSetWinSequence();
                    _gameState->setTieBreak( 1 );               // setTieBreak = true;
                    _mode1TieBreaker.setTieBreakEnable();       //  SetTieBreakEnable();
                }
                else if ( _player2->getSets() /* p2Sets */ == 2 ) {
                    _mode1WinSequences.p2MatchWinSequence();    //  P2MatchWinSequence();
                }
                else {
                    _setLeds.updateSets();                      // UpdateSets();
                    _digiFunctions.gameDelay( updateDisplayDelay );
                    _mode1WinSequences.p2SetWinSequence();      // P2SetWinSequence();
                    _setLeds.updateSets();                      // UpdateSets();
                    _digiFunctions.gameDelay( winDelay );
                    _player1->setPoints( 0 ); // p1Points = 0;
                    _player2->setPoints( 0 ); // p2Points = 0;
                }
                _player1->setGames( 0 );      // p1Games = 0;
                _player2->setGames( 0 );      // p2Games = 0;
            }

            else {
                _mode1WinSequences.p2GameWinSequence(); // P2GameWinSequence();
                _gameLeds.updateGames();                // UpdateGames();
                _digiFunctions.gameDelay(updateDisplayDelay);
                _player1->setPoints( 0 ); // p1Points = 0;
                _player2->setPoints( 0 ); // p2Points = 0;
            }
        }
    } else {
        _mode1WinSequences.p2GameWinSequence();         // P2GameWinSequence();
        _gameLeds.updateGames();                        // UpdateGames();
        _digiFunctions.gameDelay( updateDisplayDelay );
        _player1->setPoints( 0 ); /* p1Points = 0; */
        _player2->setPoints( 0 ); /* p2Points = 0; */ }
}

//----------------------------------------------------------------------------------------------------------------
void Mode1Score::mode1P2Score() {
    if ( _player2->getPoints() /* p2Points */ >= 3 ) {
        // if ( p2Points == p1Points) { // Tie, Back to Deuce
        if ( _player2->getPoints() == _player1->getPoints() ) { // Tie, Back to Deuce
            _player1->setPoints( 3 ); // p1Points = 3;
            _player2->setPoints( 3 ); // p2Points = 3;
        }

        // else if ( p2Points > 3 && ( p2Points - p1Points ) > 1 ) { // Game win Scenario
        else if ( _player2->getPoints() > 3 && ( _player2->getPoints() - _player1->getPoints() ) > 1 ) { // Game win Scenario
            _player2->setGames( _player2->getGames() + 1 ); // p2Games++;
            _undo.memory();             // Memory();
            _pointLeds.updatePoints();  // UpdatePoints();
            mode1P2Games();
        }

        if ( _player2->getPoints() /* p2Points */ == 4 ) {
            _gameState->setPointFlash( 1 );     //  pointFlash = true;
            _gameState->setPreviousTime( _digiFunctions.millis( 1 )); // now;
            _gameState->setToggle( 0 ); // toggle = 0;
        }
    }
    _pointLeds.updatePoints();  // UpdatePoints();
}

void Mode1Score::mode1TBP2Games() {
    _gameLeds.updateGames();        // UpdateGames();
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); // serveSwitch++;
    _digiFunctions.gameDelay( updateDisplayDelay );

    if ( _player2->getGames() /* p2Games */ == 15 ) {
        _player2->setSets( _player2->getSets() + 1 ); // p2Sets++;

        if ( _player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */ ) {
            _mode1TieBreaker.endTieBreak();             // EndTieBreak();
            _mode1WinSequences.p2TBSetWinSequence();    // P2TBSetWinSequence();
            _gameState->setTieBreak( 1 );               // setTieBreak = true;
            _mode1TieBreaker.setTieBreakEnable();       // SetTieBreakEnable();
        }
        else {
            _mode1WinSequences.p2SetWinSequence();      // P2SetWinSequence();
            _mode1TieBreaker.endTieBreak();             // EndTieBreak();
        }
    }

    if ( _player2->getGames() /* p2Games */ >= 10 && 
       ( _player2->getGames() /* p2Games */ - _player1->getGames() /* p1Games */ ) > 1) {
       
        _player2->setSets( _player2->getSets() + 1 );   // p2Sets++;

        if ( _player2->getSets() /* p2Sets */ == _player1->getSets() /* p1Sets */ ) {
            _mode1TieBreaker.endTieBreak();             // EndTieBreak();
            _mode1WinSequences.p2TBSetWinSequence();    // P2TBSetWinSequence();
            _gameState->setSetTieBreak( 1 );            // setTieBreak = true;
            _mode1TieBreaker.setTieBreakEnable();       // SetTieBreakEnable();
        }
        else {
            _mode1WinSequences.p2SetWinSequence();      // P2SetWinSequence();
            _mode1TieBreaker.endTieBreak();             // EndTieBreak();
        }
    }
}

void Mode1Score::mode1SetTBP2Games() {
    _gameLeds.updateGames();                // UpdateGames();
    _digiFunctions.gameDelay( updateDisplayDelay );

    if ( _player2->getGames() /* p2Games */ == 7) {
        _player2->setSets( _player2->getSets() + 1 );   // p2Sets++;
        _setLeds.updateSets();                          // UpdateSets();
        _digiFunctions.gameDelay( updateDisplayDelay );
        _mode1WinSequences.p2SetTBWinSequence();        // P2SetTBWinSequence();
        _mode1TieBreaker.tieLEDsOff();                  // TieLEDsOff();
        _mode1WinSequences.p2MatchWinSequence();        // P2MatchWinSequence();
    }
    _gameState->setServeSwitch( _gameState->getServeSwitch() + 1 ); // serveSwitch++;
}
