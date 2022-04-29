#include "CppInterface.h"

Napi::Object CppInterface::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(
      env,
      "CppInterface",
      {InstanceMethod("plusOne", &CppInterface::PlusOne),
       InstanceMethod("value", &CppInterface::GetValue),
       InstanceMethod("multiply", &CppInterface::Multiply),
       InstanceMethod("gameLoop", &CppInterface::gameLoop),
       InstanceMethod("getPinState", &CppInterface::getPinState),
       InstanceMethod("digitalRead", &CppInterface::digitalRead),
       InstanceMethod("analogRead", &CppInterface::analogRead),
       InstanceMethod("digitalWrite", &CppInterface::digitalWrite)});

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("CppInterface", func);
  return exports;
}

CppInterface::CppInterface(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<CppInterface>(info) {
  Napi::Env env = info.Env();

  int length = info.Length();
  if (length <= 0 || !info[0].IsNumber()) {  // not a number?!... bail.
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    return;
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->value_ = value.DoubleValue();
}

Napi::Value CppInterface::GetValue(const Napi::CallbackInfo& info) {
  double num = this->value_;

  return Napi::Number::New(info.Env(), num);
}

Napi::Value CppInterface::PlusOne(const Napi::CallbackInfo& info) {
  _gameObject.startGame();

  return CppInterface::GetValue(info);
}

Napi::Value CppInterface::Multiply(const Napi::CallbackInfo& info) {
  Napi::Number multiple;
  if (info.Length() <= 0 || !info[0].IsNumber()) {
    multiple = Napi::Number::New(info.Env(), 1);
  } else {
    multiple = info[0].As<Napi::Number>();
  }
  Napi::Object obj = info.Env().GetInstanceData<Napi::FunctionReference>()->New(
      {Napi::Number::New(info.Env(), this->value_ * multiple.DoubleValue())});
  return obj;
}

Napi::Value CppInterface::gameLoop(const Napi::CallbackInfo& info) {
  _gameObject.loop();
  return CppInterface::GetValue(info);
}

Napi::Value CppInterface::digitalRead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  int pin_value = _gameObject.getPinInterface()->digitalRead(
      info[0].As<Napi::Number>().Int32Value());
  return Napi::Number::New(info.Env(), pin_value);
}

Napi::Value CppInterface::analogRead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  int pin_value = _gameObject.getPinInterface()->analogRead(
      info[0].As<Napi::Number>().Int32Value());
  return Napi::Number::New(info.Env(), pin_value);
}

Napi::Value CppInterface::digitalWrite(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  double pin = info[0].As<Napi::Number>().DoubleValue();
  double value = info[1].As<Napi::Number>().DoubleValue();

  SerialObject Serial;
  std::cout << " writing " << value << " to pin " << pin << "..." << std::endl;
  _gameObject.getPinInterface()->digitalWrite(pin, value);
  Napi::Number setValue = Napi::Number::New(env, pin + value);
  return setValue;
}

Napi::Value CppInterface::getPinState(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // Create a new instance
  Napi::Object pinMap = Napi::Object::New(env);
  std::map<std::string, int> pinState =
      _gameObject.getPinInterface()->getPinStateMap();
  for (const std::pair<const std::string, int>& p : pinState) {
    int key = std::stoi(p.first);
    pinMap.Set(_translator.get_translated_constant(key), p.second);
  }

  return pinMap;
}
