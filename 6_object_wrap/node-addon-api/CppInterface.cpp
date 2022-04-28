#include "CppInterface.h"

Napi::Object CppInterface::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func =
      DefineClass(env,
                  "CppInterface",
                  {InstanceMethod("plusOne", &CppInterface::PlusOne),
                   InstanceMethod("value", &CppInterface::GetValue),
                   InstanceMethod("multiply", &CppInterface::Multiply)});

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
  this->_gameObject.startGame();

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

Napi::Value CppInterface::digitalRead(const Napi::CallbackInfo& info) {
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
