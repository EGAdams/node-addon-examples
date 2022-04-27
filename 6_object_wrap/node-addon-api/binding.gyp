{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "addon.cc", "myobject.cc",
                   "GameObject.h", "GameObject.cc",
                   "GameTimer.h", "GameTimer.ino",
                   "TranslateConstant.h", "TranslateConstant.cpp",
                   "GameState.h", "GameState.cpp",
                   "PinState.h", "PinState.cpp",
                   "DigiFunctions.h", "DigiFunctions.ino",
                   "ScoreBoard.h", "ScoreBoard.ino",
                   "LiquidCrystal_I2C.h", "LiquidCrystal_I2C.cpp",
                   "RESET.h", "RESET.ino",
                   "DIGI_V6_15.h",
                   "INPUTS.h", "INPUTS.ino",
                   "GAME_MODES.h", "GAME_MODES.ino"
                   "POINT_LEDs.h", "POINT_LEDs.ino",
                   "GAME_LEDs.h", "GAME_LEDs.ino",
                   "SET_LEDs.h", "SET_LEDs.ino",
                   "SERVO_LEDs.h", "SERVO_LEDs.ino",
                   "UNDO.h", "UNDO.ino"
                    ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
