#include "DigiFunctions.h"

DigiFunctions::DigiFunctions(Player* player1,
                             Player* player2,
                             PinInterface* pinInterface,
                             GameState* gameState)
    : _player1(player1),
      _player2(player2),
      _gameState(gameState),
      _gameInputs(player1, player2, pinInterface, gameState),
      _gameModes(player1, player2, pinInterface, gameState) {}
DigiFunctions::~DigiFunctions() {}

void DigiFunctions::digitalWrite(int pin, int mode) {
  // std::cout << "digitalWrite(" << pin << ", " << mode << ")" << std::endl;
  // std::string pin_name = _translateConstant.get_translated_constant( pin );
  // if ( _pinState.getPinState( pin_name ) != mode ) {
  //     _curlObject.writeDataToPin( pin_name,
  //     _translateConstant.get_translated_digital_mode( mode ));

  //     _pinState.setPinState( pin_name, mode );
  // } else {
  //     // std::cout << "digitalWrite(" << pin << ", " << mode
  //     //           << ") - pin already set to this mode" << std::endl;
  // }
  // digitalWrite( int pin, int mode );
}

int DigiFunctions::digitalRead(int pin) {
  // std::cout << "digitalRead(" << pin << ")" << std::endl;
  // // std::cout << "getting data with curl object..." << std::endl;
  // std::string data = _curlObject.getData( std::to_string( pin ));
  // std::cout << "data from curl: " << data << std::endl;
  // return stoi( data );
  // return digitalRead( int pin );
  return 0;
}

int DigiFunctions::analogRead(int pin) {
  // std::cout << "analogRead(" << pin << ")" << std::endl;
  // std::string data = _curlObject.getData( std::to_string( pin ));
  // std::cout << "read curl data: " << data << std::endl;
  // return stoi( data );
  // return analogRead( int pin );
  return 0;
}

void DigiFunctions::gameDelay(int ms) {
  GameTimer::delay(ms);
  std::cout << "delay(" << ms << ")" << std::endl;
}

unsigned long DigiFunctions::millis(int placeHolder) {
  //   std::chrono::milliseconds ms =
  //       std::chrono::duration_cast<std::chrono::milliseconds>(
  //           std::chrono::system_clock::now().time_since_epoch());
  //   return ms.count();
  return GameTimer::millis(1);
}

// void pinMode(int pin, int mode) {std::cout << "pinMode(" << pin << ", " <<
// mode << ")" << std::endl; }

void DigiFunctions::loop() {
  _gameInputs.readReset();
  _gameModes.setGameMode(_gameInputs.readRotary());
  gameDelay(750);
  std::cout << ("exiting loop...") << std::endl;
  return;
}

// void setup() { std::cout << "calling setup()..." << std::endl;}

// Pulled below out of setup() to make it easier to read.
// uint8_t  INPUT = 0;
// pinMode(PLAYER_BUTTONS, INPUT);
// pinMode(ROTARY, INPUT);
// pinMode(UNDO, INPUT);
// pinMode(RESET, INPUT);

// // uint8_t  OUTPUT = 0;
// pinMode(P1_POINTS_LED1, OUTPUT);
// pinMode(P1_POINTS_LED2, OUTPUT);
// pinMode(P1_POINTS_LED3, OUTPUT);
// pinMode(P1_POINTS_LED4, OUTPUT);

// pinMode(P2_POINTS_LED1, OUTPUT);
// pinMode(P2_POINTS_LED2, OUTPUT);
// pinMode(P2_POINTS_LED3, OUTPUT);
// pinMode(P2_POINTS_LED4, OUTPUT);

// pinMode(P1_SERVE, OUTPUT);
// pinMode(P2_SERVE, OUTPUT);

// pinMode(P1_GAMES_LED0, OUTPUT);
// pinMode(P1_GAMES_LED1, OUTPUT);
// pinMode(P1_GAMES_LED2, OUTPUT);
// pinMode(P1_GAMES_LED3, OUTPUT);
// pinMode(P1_GAMES_LED4, OUTPUT);
// pinMode(P1_GAMES_LED5, OUTPUT);
// pinMode(P1_GAMES_LED6, OUTPUT);
// pinMode(P1_TIEBREAKER, OUTPUT);

// pinMode(P2_GAMES_LED0, OUTPUT);
// pinMode(P2_GAMES_LED1, OUTPUT);
// pinMode(P2_GAMES_LED2, OUTPUT);
// pinMode(P2_GAMES_LED3, OUTPUT);
// pinMode(P2_GAMES_LED4, OUTPUT);
// pinMode(P2_GAMES_LED5, OUTPUT);
// pinMode(P2_GAMES_LED6, OUTPUT);
// pinMode(P2_TIEBREAKER, OUTPUT);

// pinMode(P1_SETS_LED1, OUTPUT);
// pinMode(P1_SETS_LED2, OUTPUT);

// pinMode(P2_SETS_LED1, OUTPUT);
// pinMode(P2_SETS_LED2, OUTPUT);

// Serial.begin(9600);
