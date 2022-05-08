#include "INPUTS.h"
#include "DIGI_V6_15.h"

Inputs::Inputs(Player* player1,
               Player* player2,
               PinInterface* pinInterface,
               GameState* gameState)
    : _player1(player1),
      _player2(player2),
      _gameState(gameState),
      _pinInterface(pinInterface),
      _reset(player1, player2, pinInterface, gameState) {}
Inputs::~Inputs(){};

void Inputs::readReset() {
  //   Serial.println("RESET: " +
  //   std::to_string(_pinInterface->digitalRead(RESET)));
  if (_pinInterface->digitalRead(RESET) == LOW) {
    // Serial.println("Reset press detected _pinInterface->digitalRead( RESET )
    // "
    //                "== LOW infinite loop starts here...");
    while (_pinInterface->digitalRead(RESET) == LOW) {
      //   Serial.println("waiting for reset release...");
      GameTimer::delay(250);  // _digiFunctions->gameDelay( 1000 );          //
                              // careful here!!!
    }                         // infinite loop
    // Serial.println("exited loop.");
    // _digiFunctions->gameDelay( 1000 );
    _reset.resetScoreboard();
    // _digiFunctions->clearPinState();
  } else {
    // Serial.println("_pinInterface->digitalRead( RESET ) != LOW");
  }
}

void Inputs::readUndoButton() {
  if (_pinInterface->digitalRead(UNDO) == LOW) {
    // Serial.println("entering _pinInterface->digitalRead( UNDO ) == LOW ");
    // Serial.println("infinite loop...  waiting for it to go HIGH...");
    while (_pinInterface->digitalRead(UNDO) == LOW) {
      // Serial.println("infinite loop...  waiting for it to go HIGH...");
      GameTimer::delay(250);
      if (SIMULATION) break;
    }
    GameTimer::delay(2000);
    _gameState->setUndo(1);  // undo = true;
  } else {
    // Serial.println("_pinInterface->digitalRead( UNDO ) != LOW");
  }
}

int Inputs::readRotary() {           // TODO: make this one read.
  _gameState->setRotaryPosition(0);  // int rotaryPosition = 0;
  //   Serial.println("reading rotary pin " + ROTARY);
  int rotaryAnalogValue = _pinInterface->analogRead(ROTARY);
  if (rotaryAnalogValue <= 100) {
    _gameState->setRotaryPosition(1);
  }  // rotaryPosition = 1
  if (rotaryAnalogValue >= 350 && rotaryAnalogValue <= 450) {
    _gameState->setRotaryPosition(2); /* rotaryPosition = 2 */
  }
  if (rotaryAnalogValue >= 550 && rotaryAnalogValue <= 700) {
    _gameState->setRotaryPosition(3); /* rotaryPosition = 3 */
  }
  if (rotaryAnalogValue >= 750 && rotaryAnalogValue <= 800) {
    _gameState->setRotaryPosition(4); /* rotaryPosition = 4 */
  }
  if (rotaryAnalogValue >= 850 && rotaryAnalogValue <= 1000) {
    _gameState->setRotaryPosition(5); /* rotaryPosition = 5 */
  }

  // if ( rotaryPosition != prevRotaryPosition  ) {
  if (_gameState->getRotaryPosition() != _gameState->getPrevRotaryPosition()) {
    _gameState->setRotaryChange(1);  // rotaryChange = true;
    _gameState->setPrevRotaryPosition(
        _gameState
            ->getRotaryPosition());  //  prevRotaryPosition = rotaryPosition;
    _reset.refresh();  // set rotaryChange to false and reset the scoreboard
  }
  return _gameState->getRotaryPosition();
}

void Inputs::readPlayerButtons() {
  //   Serial.println("reading player buttons...");
  int anlgPlyrBtnVal = _pinInterface->analogRead(PLAYER_BUTTONS);
  if (anlgPlyrBtnVal <= 1000) {  // if one of the player buttons is pressed...
    // Serial.println("analog value of player button input: " +
    //                std::to_string(anlgPlyrBtnVal) + ".");
    GameTimer::delay(20);  // _digiFunctions->gameDelay( 20 );
    if (anlgPlyrBtnVal <= 50) {
      _gameState->setPlayerButton(1); /* playerButton = 1 */
    } else if (anlgPlyrBtnVal >= 350 && anlgPlyrBtnVal <= 400) {
      _gameState->setPlayerButton(2); /* playerButton = 2 */
    } else if (anlgPlyrBtnVal >= 550 && anlgPlyrBtnVal <= 650) {
      _gameState->setPlayerButton(3); /* playerButton = 3 */
    } else if (anlgPlyrBtnVal >= 750 && anlgPlyrBtnVal <= 800) {
      _gameState->setPlayerButton(4); /* playerButton = 4 */
    }
    while (_pinInterface->analogRead(PLAYER_BUTTONS) <= 1000) {
      // Serial.println( "PLAYER_BUTTONS: " + String( _pinInterface->analogRead(
      // PLAYER_BUTTONS ) ) );
      //   Serial.println("waiting for player button to release...");
      GameTimer::delay(250);  // Be careful with the infinite loop!!!
      if (SIMULATION) break;
    }
    // String thePlayerButton = String( _gameState->getPlayerButton());

    // Serial.println("done reading buttons.");
  }
}