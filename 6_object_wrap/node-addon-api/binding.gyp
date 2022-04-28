{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "addon.cc", "CppInterface.cpp",
                   "GameTimer.h", "GameTimer.cpp",
                   "TranslateConstant.h", "TranslateConstant.cpp",
                   "GameState.h", "GameState.cpp",
                   "PinState.h", "PinState.cpp",
                   "DigiFunctions.h", "DigiFunctions.cpp",
                   "LiquidCrystal_I2C.h", "LiquidCrystal_I2C.cpp",
                   "RESET.h", "RESET.cpp",
                   "DIGI_V6_15.h",
                   "INPUTS.h", "INPUTS.cpp",
                   "GAME_MODES.h", "GAME_MODES.cpp",
                   "ScoreBoard.h", "ScoreBoard.cpp",
                   "GameObject.h", "GameObject.cc",
                   "POINT_LEDs.h", "POINT_LEDs.cpp",
                   "GAME_LEDs.h", "GAME_LEDs.cpp",
                   "SET_LEDs.h", "SET_LEDs.cpp",
                   "SERVE_LEDs.h", "SERVE_LEDs.cpp",
                   "UNDO.h", "UNDO.cpp",
                   "MODE_1_SCORE.h", "MODE_1_SCORE.cpp",
                   "MODE_1_FUNCTIONS.h", "MODE_1_FUNCTIONS.cpp",
                   "MODE_2_FUNCTIONS.h", "MODE_2_FUNCTIONS.cpp",
                   "MODE_1_WIN_SEQUENCES.h", "MODE_1_WIN_SEQUENCES.cpp",
                   "MODE_1_TIEBREAKER.h", "MODE_1_TIEBREAKER.cpp",
                   "PinState.h", "PinState.cpp",
                   "PinInterface.h", "PinInterface.cpp",
                   "Player.h", "Player.cpp",
                   "Serial.h", "Serial.cpp",
                    ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
