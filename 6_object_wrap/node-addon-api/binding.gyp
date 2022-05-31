{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "addon.cc", "CppInterface.cpp",
                   "GameTimer/GameTimer.h", "GameTimer/GameTimer.cpp",
                   "TranslateConstant/TranslateConstant.h", "TranslateConstant/TranslateConstant.cpp",
                   "GameState/GameState.h", "GameState/GameState.cpp",
                   "DigiFunctions.h", "DigiFunctions.cpp",
                   "WebLiquidCrystal/WebLiquidCrystal.h", "WebLiquidCrystal/WebLiquidCrystal.cpp",
                   "RESET/RESET.h", "RESET/RESET.cpp",
                   "DIGI_V6_15/DIGI_V6_15.h",
                   "INPUTS/INPUTS.h", "INPUTS/INPUTS.cpp",
                   "GAME_MODES/GAME_MODES.h", "GAME_MODES/GAME_MODES.cpp",
                   "ScoreBoard/ScoreBoard.h", "ScoreBoard/ScoreBoard.cpp",
                   "GameObject/GameObject.h", "GameObject/GameObject.cpp",
                   "POINT_LEDs/POINT_LEDs.h", "POINT_LEDs/POINT_LEDs.cpp",
                   "GAME_LEDs/GAME_LEDs.h", "GAME_LEDs/GAME_LEDs.cpp",
                   "SET_LEDs/SET_LEDs.h", "SET_LEDs/SET_LEDs.cpp",
                   "SERVE_LEDs/SERVE_LEDs.h", "SERVE_LEDs/SERVE_LEDs.cpp",
                   "UNDO/UNDO.h", "UNDO/UNDO.cpp",
                   "MODE_1_SCORE/MODE_1_SCORE.h", "MODE_1_SCORE/MODE_1_SCORE.cpp",
                   "MODE_1_FUNCTIONS/MODE_1_FUNCTIONS.h", "MODE_1_FUNCTIONS/MODE_1_FUNCTIONS.cpp",
                   "MODE_2_FUNCTIONS/MODE_2_FUNCTIONS.h", "MODE_2_FUNCTIONS/MODE_2_FUNCTIONS.cpp",
                   "MODE_1_WIN_SEQUENCES/MODE_1_WIN_SEQUENCES.h", "MODE_1_WIN_SEQUENCES/MODE_1_WIN_SEQUENCES.cpp",
                   "MODE_1_TIEBREAKER/MODE_1_TIEBREAKER.h", "MODE_1_TIEBREAKER/MODE_1_TIEBREAKER.cpp",
                   "PinState/PinState.h", "PinState/PinState.cpp",
                   "PinInterface/PinInterface.h", "PinInterface/PinInterface.cpp",
                   "Player/Player.h", "Player/Player.cpp",
                   "Serial.h", "Serial.cpp",
                   "Arduino/Arduino.h", "SubjectManager/SubjectManager.h", "SubjectManager/SubjectManager.cpp",
                   "TieLeds/TieLeds.h", "TieLeds/TieLeds.cpp",
                   "Logger/Logger.h", "Logger/Logger.cpp",
                    ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "UNDO", "DIGI_V6_15", "GAME_LEDs", "GAME_MODES", "Arduino", "PinState",
        "PinInterface", "Player", "GameState", "GameTimer", "INPUTS", "RESET",
        "POINT_LEDs", "MODE_1_FUNCTIONS", "MODE_1_SCORE", "SERVE_LEDs", "MODE_1_TIEBREAKER",
        "MODE_1_WIN_SEQUENCES", "SET_LEDs", "MODE_2_FUNCTIONS", "GameObject",
        "WebLiquidCrystal", "ScoreBoard", "TranslateConstant", "SubjectManager", "TieLeds",
        "Logger"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
