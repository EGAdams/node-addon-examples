{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "addon.cc", "myobject.cc",
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
                   "GAME_MODES.h", "GAME_MODES.ino",
                   "GameObject.h", "GameObject.cc",
                   "POINT_LEDs.h", "POINT_LEDs.ino",
                   "GAME_LEDs.h", "GAME_LEDs.ino",
                   "SET_LEDs.h", "SET_LEDs.ino",
                   "SERVO_LEDs.h", "SERVO_LEDs.ino",
                   "UNDO.h", "UNDO.ino",
                   "MODE_1_SCORE.h", "MODE_1_SCORE.ino",
                   "MODE_1_FUNCTIONS.h", "MODE_1_FUNCTIONS.ino",
                   "MODE_2_FUNCTIONS.h", "MODE_2_FUNCTIONS.ino",
                   "MODE_1_WIN_SEQUENCES.h", "MODE_1_WIN_SEQUENCES.ino",
                   "MODE_1_TIEBRAKER.h", "MODE_1_TIEBRAKER.ino",
                   "PinState.h", "PinState.cpp",
                   "PinInterface.h", "PinInterface.cpp",
                    ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
