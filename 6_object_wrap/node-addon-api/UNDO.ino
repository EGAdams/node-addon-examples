#include <iostream>

#ifndef DIGI_V6_15_H_ONLY_
#define DIGI_V6_15_H_ONLY_
#include "DIGI_V6_15.h"
#endif

#include "Serial.h"
#include "UNDO.h"

Undo::Undo( Player *player1, Player *player2, DigiFunctions *digiFunctions ) : 
    _player1( player1 ),
    _player2( player2 ),
    _gameState( digiFunctions->getGameState()   ),
    _pointLeds( player1, player2, digiFunctions ),
    _gameLeds( player1,  player2, digiFunctions ),
    _setLeds( player1,   player2, digiFunctions ),
    _serveLeds( digiFunctions                   ){};

Undo::~Undo(){};

void Undo::memory() {
    /* p1PointsMem */ _gameState->setP1PointsMem( _player1->getPoints()); // = p1Points;
    /* p2PointsMem */ _gameState->setP2PointsMem( _player2->getPoints()); // = p2Points;
    /* p1GamesMem  */ _gameState->setP1GamesMem(  _player1->getGames());  // = p1Games;
    /* p2GamesMem  */ _gameState->setP2GamesMem(  _player2->getGames());  // = p2Games;
    /* p1SetsMem   */ _gameState->setP1SetsMem(   _player1->getSets());   // = p1Sets;
    /* p2SetsMem   */ _gameState->setP1SetsMem(   _player2->getSets());   // = p2Sets;
    // tieBreakMem    = _gameState->getTieBreak();     // tieBreak;
    // setTieBreakMem = _gameState->getSetTieBreak();  // setTieBreak;
}

void Undo::setMode1Undo() {
    SerialObject Serial;
    Serial.println( "Set Undo" );
    prev3PointFlash = prev2PointFlash;
    prev3P1Points = prev2P1Points;
    prev3P2Points = prev2P2Points;
    prev3P1Games = prev2P1Games;
    prev3P2Games = prev2P2Games;
    prev3P1Sets = prev2P1Sets;
    prev3P2Sets = prev2P2Sets;
    prev3P1Matches = prev2P1Matches;
    prev3P2Matches = prev2P2Matches;
    prev3Serve = prev2Serve;
    prev3TieBreak = prev2TieBreak;
    prev3SetTieBreak = prev2SetTieBreak;
    prev3TieLEDsOn = prev2TieLEDsOn;

    prev2PointFlash = prev1PointFlash;
    prev2P1Points = prev1P1Points;
    prev2P2Points = prev1P2Points;
    prev2P1Games = prev1P1Games;
    prev2P2Games = prev1P2Games;
    prev2P1Sets = prev1P1Sets;
    prev2P2Sets = prev1P2Sets;
    prev2P1Matches = prev1P1Matches;
    prev2P2Matches = prev1P2Matches;
    prev2Serve = prev1Serve;
    prev2TieBreak = prev1TieBreak;
    prev2SetTieBreak = prev1SetTieBreak;
    prev2TieLEDsOn = prev1TieLEDsOn;

    prev1PointFlash = prevPointFlash;
    prev1P1Points = prevP1Points;
    prev1P2Points = prevP2Points;
    prev1P1Games = prevP1Games;
    prev1P2Games = prevP2Games;
    prev1P1Sets = prevP1Sets;
    prev1P2Sets = prevP2Sets;
    prev1P1Matches = prevP1Matches;
    prev1P2Matches = prevP2Matches;
    prev1Serve = prevServe;
    prev1TieBreak = prevTieBreak;
    prev1SetTieBreak = prevSetTieBreak;
    prev1TieLEDsOn = prevTieLEDsOn;

    prevPointFlash =  _gameState->getPointFlash();  // pointFlash;
    prevP1Points =    _player1->getPoints();        // p1Points;
    prevP2Points =    _player2->getPoints();        // p2Points;
    prevP1Games =     _player1->getGames();         // p1Games;
    prevP2Games =     _player2->getGames();         // p2Games;
    prevP1Sets =      _player1->getSets();          // p1Sets;
    prevP2Sets =      _player2->getSets();          // p2Sets;
    prevP1Matches =   _player1->getMatches();       // p1Matches;
    prevP2Matches =   _player2->getMatches();       // p2Matches;
    prevServe =       _gameState->getServe();       // serve;
    prevTieBreak =    _gameState->getTieBreak();    // tieBreak;
    prevSetTieBreak = _gameState->getSetTieBreak(); // setTieBreak;
    prevTieLEDsOn =   _gameState->getTieLEDsOn();   // tieLEDsOn;
}

void Undo::mode1Undo() {
    // delay( 1000 );
    _gameState->setPointFlash( prevPointFlash );    // pointFlash = prevPointFlash;
    _player1->setPoints( /* p1Points = */ prevP1Points );
    _player2->setPoints( /* p2Points = */ prevP2Points );
    _player1->setGames(  /* p1Games  = */ prevP1Games  );
    _player2->setGames(  /* p2Games  = */ prevP2Games  );
    _player1->setSets(   /* p1Sets =   */ prevP1Sets   );
    _player2->setSets(   /* p2Sets =   */ prevP2Sets   );
    _player1->setMatches(/* p1Matches= */ prevP1Matches);
    _player2->setMatches(/* p2Matches= */ prevP2Matches);
    _gameState->setServe( prevServe );              // serve = prevServe;
    _gameState->setTieBreak( prevTieBreak );        // tieBreak = prevTieBreak;
    _gameState->setSetTieBreak( prevSetTieBreak );  // setTieBreak = prevSetTieBreak;
    _gameState->setTieLEDsOn( prevTieLEDsOn );      // tieLEDsOn = prevTieLEDsOn;

    prevPointFlash = prev1PointFlash;
    prevP1Points = prev1P1Points;
    prevP2Points = prev1P2Points;
    prevP1Games = prev1P1Games;
    prevP2Games = prev1P2Games;
    prevP1Sets = prev1P1Sets;
    prevP2Sets = prev1P2Sets;
    prevP1Matches = prev1P1Matches;
    prevP2Matches = prev1P2Matches;
    prevServe = prev1Serve;
    prevTieBreak = prev1TieBreak;
    prevSetTieBreak = prev1SetTieBreak;
    prevTieLEDsOn = prev1TieLEDsOn;

    prev1PointFlash = prev2PointFlash;
    prev1P1Points = prev2P1Points;
    prev1P2Points = prev2P2Points;
    prev1P1Games = prev2P1Games;
    prev1P2Games = prev2P2Games;
    prev1P1Sets = prev2P1Sets;
    prev1P2Sets = prev2P2Sets;
    prev1P1Matches = prev2P1Matches;
    prev1P2Matches = prev2P2Matches;
    prev1Serve = prev2Serve;
    prev1TieBreak = prev2TieBreak;
    prev1SetTieBreak = prev2SetTieBreak;
    prev1TieLEDsOn = prev2TieLEDsOn;

    prev2PointFlash = prev3PointFlash;
    prev2P1Points = prev3P1Points;
    prev2P2Points = prev3P2Points;
    prev2P1Games = prev3P1Games;
    prev2P2Games = prev3P2Games;
    prev2P1Sets = prev3P1Sets;
    prev2P2Sets = prev3P2Sets;
    prev2P1Matches = prev3P1Matches;
    prev2P2Matches = prev3P2Matches;
    prev2Serve = prev3Serve;
    prev2TieBreak = prev3TieBreak;
    prev2SetTieBreak = prev3SetTieBreak;
    prev2TieLEDsOn = prev3TieLEDsOn;

    if ( _gameState->getTieLEDsOn() == 1 /* tieLEDsOn == true */ ) {
        // _mode1TieBreaker.tieLEDsOn();  // TieLEDsOn();
        _gameState->setTieLEDsOn( 1 ); // tieLEDsOn = true;
        _digiFunctions.digitalWrite( P1_TIEBREAKER, HIGH );
        _digiFunctions.digitalWrite( P2_TIEBREAKER, HIGH );
    }
    if ( _gameState->getTieLEDsOn() == 0 /* tieLEDsOn == false */ ) {
        // _mode1TieBreaker.tieLEDsOff(); // TieLEDsOff();
        _gameState->setTieLEDsOn( 0 ); // tieLEDsOn = false;
        _digiFunctions.digitalWrite( P1_TIEBREAKER, LOW );
        _digiFunctions.digitalWrite( P2_TIEBREAKER, LOW );
    }
    _pointLeds.updatePoints();   // UpdatePoints();
    _gameLeds.updateGames();     // UpdateGames(); 
    _setLeds.updateSets();       // UpdateSets();
    _serveLeds.updateServeLED(); // UpdateServeLED();
}
