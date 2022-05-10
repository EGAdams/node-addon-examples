/*
 * c++ notes
 */

PinInterface* goPinInt = _gameObject->getPinInterface();
std::cout << (reinterpret_cast<const char*>(std::addressof(_pinInterface)) ==
              reinterpret_cast<const char*>(std::addressof(goPinInt)))
          << std::endl;
