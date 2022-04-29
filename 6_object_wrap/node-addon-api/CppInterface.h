#ifndef CppInterface_H
#define CppInterface_H

#include <napi.h>
#include <iostream>
#include <string>
#include "GameObject.h"
#include "TranslateConstant.h"

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
  GameObject _gameObject;
  TranslateConstant _translator;
};

#endif
