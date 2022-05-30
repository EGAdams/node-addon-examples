#include "TieLeds.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

TieLeds::TieLeds(PinInterface* pinInterface) : _pinInterface(pinInterface) {}
TieLeds::~TieLeds() {}

void TieLeds::turnOff() {
  std::cout << "writing low to P1_TIEBREAKER..." << std::endl;
  _pinInterface->pinDigitalWrite(P1_TIEBREAKER, LOW);
  std::cout << "writing low to P2_TIEBREAKER..." << std::endl;
  _pinInterface->pinDigitalWrite(P2_TIEBREAKER, LOW);
}

void TieLeds::turnOn() {
  std::cout << "writing high to P1_TIEBREAKER..." << std::endl;
  _pinInterface->pinDigitalWrite(P1_TIEBREAKER, HIGH);
  std::cout << "writing high to P2_TIEBREAKER..." << std::endl;
  _pinInterface->pinDigitalWrite(P2_TIEBREAKER, HIGH);
}
