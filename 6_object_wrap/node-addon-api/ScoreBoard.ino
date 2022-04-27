#include "ScoreBoard.h"
//#include <iostream>
//#include <iomanip>
//#include <LiquidCrystal_I2C.h>
#include "LiquidCrystal_I2C.h"
// using namespace std;

ScoreBoard::ScoreBoard( Player *player1, Player *player2, LiquidCrystal_I2C *lcdDisplay ) {
    _player1 = player1;
    _player2 = player2; 
    _lcd = lcdDisplay; //(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

    _lcd->init();                      // initialize the lcd
    // Print a message to the LCD.
    _lcd->backlight();
    _lcd->setCursor(3,0);
    _lcd->print("Hello, earth. ");
    _lcd->setCursor(2,1);
    _lcd->print("Ywrobot Arduino!");
    _lcd->setCursor(1,2);
    _lcd->print("Arduino LCM IIC");
}


void ScoreBoard::update() {
    // delay( 400 );
    _lcd->setCursor(1,0);
    _lcd->print( "PLayer1   Player2" );
    _lcd->setCursor(1,1);
    _lcd->print( "Points:" + std::to_string( _player1->getPoints()) +  "  Points:" + std::to_string( _player2->getPoints()) );
    _lcd->setCursor(1,2);
    _lcd->print( "Games :" + std::to_string( _player1->getGames()) +  "  Games :" + std::to_string( _player2->getGames()) );
    _lcd->setCursor(1,3);
    _lcd->print( "Sets  :" + std::to_string( _player1->getSets()) +  "  Sets  :" + std::to_string( _player2->getSets()) );


}

ScoreBoard::~ScoreBoard() { /* Serial.println( "ScoreBoard destructor called." ); */ }
