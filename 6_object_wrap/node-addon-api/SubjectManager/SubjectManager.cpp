/*
 *  class SubjectManager
 *  stringifies the GameState object and writes it to disk
 */
#include "SubjectManager.h"
#include <fstream>
#include <string>

SubjectManager::SubjectManager() {}
SubjectManager::~SubjectManager() {}

#if defined _WIN32 || defined _WIN64
void SubjectManager::gameStateUpdate(GameState* gameState) {
  std::string update_path =
      "C:\\Users\\EG\\Desktop\\2022\\april\\5th_week\\node-addon-examples\\6_"
      "object_wrap\\node-addon-api\\game_state_data\\";
  std::string stringifiedGameState("{");
  stringifiedGameState +=
      "\"_toggle\": \"" + std::to_string(gameState->getToggle()) + "\",\n";
  stringifiedGameState +=
      "\"_started\": \"" + std::to_string(gameState->getStarted()) + "\",\n";
  stringifiedGameState += "\"_rotaryPosition\": \"" +
                          std::to_string(gameState->getRotaryPosition()) +
                          "\",\n";
  stringifiedGameState += "\"_prevRotaryPosition\": \"" +
                          std::to_string(gameState->getPrevRotaryPosition()) +
                          "\",\n";
  stringifiedGameState += "\"_playerButton\": \"" +
                          std::to_string(gameState->getPlayerButton()) +
                          "\",\n";
  stringifiedGameState +=
      "\"_undo\": \"" + std::to_string(gameState->getUndo()) + "\",\n";
  stringifiedGameState += "\"_rotaryChange\": \"" +
                          std::to_string(gameState->getRotaryChange()) +
                          "\",\n";
  stringifiedGameState +=
      "\"_now\": \"" + std::to_string(gameState->getNow()) + "\",\n";
  stringifiedGameState += "\"_previousTime\": \"" +
                          std::to_string(gameState->getPreviousTime()) +
                          "\",\n";
  stringifiedGameState += "\"_updateDisplayDelay\": \"" +
                          std::to_string(gameState->getUpdateDisplayDelay()) +
                          "\",\n";
  stringifiedGameState += "\"_buttonDelay\": \"" +
                          std::to_string(gameState->getButtonDelay()) + "\",\n";
  stringifiedGameState += "\"_flashDelay\": \"" +
                          std::to_string(gameState->getFlashDelay()) + "\",\n";
  stringifiedGameState += "\"_gameFlashDelay\": \"" +
                          std::to_string(gameState->getGameFlashDelay()) +
                          "\",\n";
  stringifiedGameState += "\"_tiePulseCount\": \"" +
                          std::to_string(gameState->getTiePulseCount()) +
                          "\",\n";
  stringifiedGameState += "\"_gameWinPulseCount\": \" " +
                          std::to_string(gameState->getGameWinPulseCount()) +
                          "\",\n";
  stringifiedGameState += "\"_setWinPulseCount\": \" " +
                          std::to_string(gameState->getSetWinPulseCount()) +
                          "\",\n";
  stringifiedGameState += "\"_matchWinPulseCount\": \" " +
                          std::to_string(gameState->getMatchWinPulseCount()) +
                          "\",\n";
  stringifiedGameState += "\"_serveSwitch\": \" " +
                          std::to_string(gameState->getServeSwitch()) + "\",\n";
  stringifiedGameState += "\"_setTieBreakMem\": \" " +
                          std::to_string(gameState->getSetTieBreakMem()) +
                          "\",\n";
  stringifiedGameState += "\"_tieBreakMem\": \" " +
                          std::to_string(gameState->getTieBreakMem()) + "\",\n";
  stringifiedGameState += "\"_p1PointsMem\": \"" +
                          std::to_string(gameState->getP1PointsMem()) + "\",\n";
  stringifiedGameState += "\"_p2PointsMem\": \"" +
                          std::to_string(gameState->getP2PointsMem()) + "\",\n";
  stringifiedGameState += "\"_p1GamesMem\": \"" +
                          std::to_string(gameState->getP1GamesMem()) + "\",\n";
  stringifiedGameState += "\"_p2GamesMem\": \"" +
                          std::to_string(gameState->getP2GamesMem()) + "\",\n";
  stringifiedGameState += "\"_p1SetsMem\": \"" +
                          std::to_string(gameState->getP1SetsMem()) + "\",\n";
  stringifiedGameState += "\"_p2SetsMem\": \"" +
                          std::to_string(gameState->getP2SetsMem()) + "\",\n";
  stringifiedGameState += "\"_tieBreakOnly\": \"" +
                          std::to_string(gameState->getTieBreakOnly()) +
                          "\",\n";
  stringifiedGameState += "\"_prevP1Points\": \"" +
                          std::to_string(gameState->getPrevP1Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prevP2Points\": \"" +
                          std::to_string(gameState->getPrevP2Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prevP1Games\": \"" +
                          std::to_string(gameState->getPrevP1Games()) + "\",\n";
  stringifiedGameState += "\"_prevP2Games\": \"" +
                          std::to_string(gameState->getPrevP2Games()) + "\",\n";
  stringifiedGameState += "\"_prevP1Sets\": \"" +
                          std::to_string(gameState->getPrevP1Sets()) + "\",\n";
  stringifiedGameState += "\"_prevP2Sets\": \"" +
                          std::to_string(gameState->getPrevP2Sets()) + "\",\n";
  stringifiedGameState += "\"_prev2P1Points\": \"" +
                          std::to_string(gameState->getPrev2P1Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P2Points\": \"" +
                          std::to_string(gameState->getPrev2P2Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P1Games\": \"" +
                          std::to_string(gameState->getPrev2P1Games()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P2Games\": \"" +
                          std::to_string(gameState->getPrev2P2Games()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P1Sets\": \"" +
                          std::to_string(gameState->getPrev2P1Sets()) + "\",\n";
  stringifiedGameState += "\"_prev2P2Sets\": \"" +
                          std::to_string(gameState->getPrev2P2Sets()) + "\",\n";
  stringifiedGameState += "\"_prev3P1Points\": \"" +
                          std::to_string(gameState->getPrev3P1Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P2Points\": \"" +
                          std::to_string(gameState->getPrev3P2Points()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P1Games\": \"" +
                          std::to_string(gameState->getPrev3P1Games()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P2Games\": \"" +
                          std::to_string(gameState->getPrev3P2Games()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P1Sets\": \"" +
                          std::to_string(gameState->getPrev3P1Sets()) + "\",\n";
  stringifiedGameState += "\"_prev3P2Sets\": \"" +
                          std::to_string(gameState->getPrev3P2Sets()) + "\",\n";
  stringifiedGameState += "\"_prevP1Matches\": \"" +
                          std::to_string(gameState->getPrevP1Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prevP2Matches\": \"" +
                          std::to_string(gameState->getPrevP2Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev1P1Matches\": \"" +
                          std::to_string(gameState->getPrev1P1Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev1P2Matches\": \"" +
                          std::to_string(gameState->getPrev1P2Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P1Matches\": \"" +
                          std::to_string(gameState->getPrev2P1Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2P2Matches\": \"" +
                          std::to_string(gameState->getPrev2P2Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P1Matches\": \"" +
                          std::to_string(gameState->getPrev3P1Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3P2Matches\": \"" +
                          std::to_string(gameState->getPrev3P2Matches()) +
                          "\",\n";
  stringifiedGameState += "\"_prevTieLEDsOn\": \"" +
                          std::to_string(gameState->getPrevTieLEDsOn()) +
                          "\",\n";
  stringifiedGameState += "\"_tieLEDsOn\": \"" +
                          std::to_string(gameState->getTieLEDsOn()) + "\",\n";
  stringifiedGameState += "\"_prev1TieLEDsOn\": \"" +
                          std::to_string(gameState->getPrev1TieLEDsOn()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2TieLEDsOn\": \"" +
                          std::to_string(gameState->getPrev2TieLEDsOn()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3TieLEDsOn\": \"" +
                          std::to_string(gameState->getPrev3TieLEDsOn()) +
                          "\",\n";
  stringifiedGameState += "\"_setTieBreak\": \"" +
                          std::to_string(gameState->getSetTieBreak()) + "\",\n";
  stringifiedGameState += "\"_prevSetTieBreak\": \"" +
                          std::to_string(gameState->getPrevSetTieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev1SetTieBreak\": \"" +
                          std::to_string(gameState->getPrev1SetTieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2SetTieBreak\": \"" +
                          std::to_string(gameState->getPrev2SetTieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3SetTieBreak\": \"" +
                          std::to_string(gameState->getPrev3SetTieBreak()) +
                          "\",\n";
  stringifiedGameState +=
      "\"_tieBreak\": \"" + std::to_string(gameState->getTieBreak()) + "\",\n";
  stringifiedGameState += "\"_prevTieBreak\": \"" +
                          std::to_string(gameState->getPrevTieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev1TieBreak\": \"" +
                          std::to_string(gameState->getPrev1TieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2TieBreak\": \"" +
                          std::to_string(gameState->getPrev2TieBreak()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3TieBreak\": \"" +
                          std::to_string(gameState->getPrev3TieBreak()) +
                          "\",\n";
  stringifiedGameState +=
      "\"_serve\": \"" + std::to_string(gameState->getServe()) + "\",\n";
  stringifiedGameState += "\"_prevServe\": \"" +
                          std::to_string(gameState->getPrevServe()) + "\",\n";
  stringifiedGameState += "\"_prev1Serve\": \"" +
                          std::to_string(gameState->getPrev1Serve()) + "\",\n";
  stringifiedGameState += "\"_prev2Serve\": \"" +
                          std::to_string(gameState->getPrev2Serve()) + "\",\n";
  stringifiedGameState += "\"_prev3Serve\": \"" +
                          std::to_string(gameState->getPrev3Serve()) + "\",\n";
  stringifiedGameState += "\"_pointFlash\": \"" +
                          std::to_string(gameState->getPointFlash()) + "\",\n";
  stringifiedGameState += "\"_prevPointFlash\": \"" +
                          std::to_string(gameState->getPrevPointFlash()) +
                          "\",\n";
  stringifiedGameState += "\"_prev1PointFlash\": \"" +
                          std::to_string(gameState->getPrev1PointFlash()) +
                          "\",\n";
  stringifiedGameState += "\"_prev2PointFlash\": \"" +
                          std::to_string(gameState->getPrev2PointFlash()) +
                          "\",\n";
  stringifiedGameState += "\"_prev3PointFlash\": \"" +
                          std::to_string(gameState->getPrev3PointFlash()) +
                          "\"\n";
  stringifiedGameState += "}";

  std::ofstream game_state_file(update_path + "game_state_data.txt");
  game_state_file << stringifiedGameState;
  game_state_file.close();
}
#else
void SubjectManager::gameStateUpdate(GameState* gameState) {}
#endif
