#include "INPUTS.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

Inputs::Inputs(Player* player1,
               Player* player2,
               PinInterface* pinInterface,
               GameState* gameState)
    : _player1(player1),
      _player2(player2),
      _pinInterface(pinInterface),
      _gameState(gameState),
      _reset(player1, player2, pinInterface, gameState) {}
Inputs::~Inputs(){};

void Inputs::readReset() {
  // SerialObject Serial;
  // Serial.println("readReset()");
  std::cout << "inside readReset()  calling pinDigitalRead()..." << std::endl;
  if (_pinInterface->pinDigitalRead(RESET) == LOW) {
    // Serial.println("Reset press detected _pinInterface->pinDigitalRead( RESET
    // ) "
    //                "== LOW infinite loop starts here...");
    if (SIMULATION == 0) {
      while (_pinInterface->pinDigitalRead(RESET) == LOW) {
        std::cout << "waiting for reset release..." << std::endl;
        GameTimer::gameDelay(25);  // careful here!!!
      }                            // semi infinite loop
    }
    std::cout << "exited loop.  calling _reset.resetScoreboard..." << std::endl;
    // _digiFunctions->gameDelay( 1000 );
    _reset.resetScoreboard();
    // _digiFunctions->clearPinState();
  } else {
    std::cout << "_pinInterface->pinDigitalRead( RESET ) != LOW" << std::endl;
  }
}

void Inputs::readUndoButton() {
  // SerialObject Serial;
  if (_pinInterface->pinDigitalRead(UNDO) == LOW) {
    // Serial.println("entering _pinInterface->pinDigitalRead( UNDO ) == LOW ");
    // Serial.println("infinite loop...  waiting for it to go HIGH...");
    // Serial.println("broke out of loop.");
    if (SIMULATION == 0) {
      while (_pinInterface->pinDigitalRead(UNDO) == LOW) {
        GameTimer::gameDelay(25);
      }
    }
    // GameTimer::gameDelay(2000 );
    _gameState->setUndo(1);  // undo = true;
  } else {
    // Serial.println( "_pinInterface->pinDigitalRead( UNDO ) != LOW" );
  }
}

int Inputs::readRotary() {  // TODO: make this one read.
  // SerialObject Serial;
  _gameState->setRotaryPosition(0);  // int rotaryPosition = 0;
  // Serial.println("reading rotary pin " + ROTARY);
  int rotaryAnalogValue = _pinInterface->pinAnalogRead(ROTARY);
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
  // Serial.print("rotaryPosition set to: " +
  //              _gameState->getRotaryPosition() /* rotaryPosition */);
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
  // SerialObject Serial;
  // Serial.println("reading player buttons...");
  int anlgPlyrBtnVal = _pinInterface->pinAnalogRead(PLAYER_BUTTONS);
  if (anlgPlyrBtnVal <= 1000) {  // if one of the player buttons is pressed...
    // Serial.println("analog value of player button input: " +
    //                std::to_string(anlgPlyrBtnVal) + ".");
    GameTimer::gameDelay(20);  // _digiFunctions->gameDelay( 20 );
    if (anlgPlyrBtnVal <= 50) {
      _gameState->setPlayerButton(1); /* playerButton = 1 */
    } else if (anlgPlyrBtnVal >= 350 && anlgPlyrBtnVal <= 400) {
      _gameState->setPlayerButton(2); /* playerButton = 2 */
    } else if (anlgPlyrBtnVal >= 550 && anlgPlyrBtnVal <= 650) {
      _gameState->setPlayerButton(3); /* playerButton = 3 */
    } else if (anlgPlyrBtnVal >= 750 && anlgPlyrBtnVal <= 800) {
      _gameState->setPlayerButton(4); /* playerButton = 4 */
    }
    if (SIMULATION == 0) {
      while (_pinInterface->pinAnalogRead(PLAYER_BUTTONS) <= 1000) {
        // GameTimer::gameDelay( 750 );  // Be careful inside this infinite
        // loop!!!
      }
    }
    // std::string thePlayerButton =
    // std::to_string(_gameState->getPlayerButton()); Serial.println("done
    // reading buttons.  playerButton = " +
    //                thePlayerButton /* playerButton */);
  }
}
