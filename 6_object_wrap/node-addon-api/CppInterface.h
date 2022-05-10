#ifndef CppInterface_H
#define CppInterface_H

#include <napi.h>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include "GAME_MODES.h"
#include "GameObject.h"
#include "GameState.h"
#include "GameTimer.h"
#include "Inputs.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "TranslateConstant.h"
#include "WebLiquidCrystal.h"

class CppInterface : public Napi::ObjectWrap<CppInterface> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  CppInterface(const Napi::CallbackInfo& info);

 private:
  Napi::Value GetValue(const Napi::CallbackInfo& info);
  Napi::Value PlusOne(const Napi::CallbackInfo& info);
  Napi::Value Multiply(const Napi::CallbackInfo& info);
  Napi::Value digitalWrite(const Napi::CallbackInfo& info);
  Napi::Value digitalRead(const Napi::CallbackInfo& info);
  Napi::Value analogRead(const Napi::CallbackInfo& info);
  Napi::Value gameLoop(const Napi::CallbackInfo& info);
  Napi::Value getPinState(const Napi::CallbackInfo& info);

  double value_;
  TranslateConstant _translator;
  //   GameObject        _gameObject( Player *player1,
  //                                 Player *player2,
  //                                 PinState *pinState,
  //                                 PinInterface *pinInterface,
  //                                 GameState *gameState,
  //                                 GameTimer *gameTimer,
  //                                 Inputs *gameInputs,
  //                                 GameModes *gameModes,
  //                                 ScoreBoard *scoreBoard,
  //                                 WebLiquidCrystal *webLiquidCrystal );
  GameObject* _gameObject;
  PinInterface* _pinInterface;
  PinState* _pinState;
  std::map<std::string, int> _cpp_interface_pin_map;
};

#endif
