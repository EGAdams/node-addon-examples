/*
 *  class SubjectManager
 *  stringifies the GameState object and writes it to disk
 */
#include "SubjectManager.h"
#include <fstream>
#include <string>

SubjectManager::SubjectManager() {}
SubjectManager::~SubjectManager() {}

void SubjectManager::gameStateUpdate(GameState* gameState) {
  std::string update_path =
      "C:\\Users\\EG\\Desktop\\2022\\april\\5th_week\\node-addon-examples\\6_"
      "object_wrap\\node-addon-api\\game_state_data\\";
  std::string stringifiedGameState("{");
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
  stringifiedGameState +=
      "\"_toggle\": \"" + std::to_string(gameState->getToggle()) + "\",\n";
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
                          std::to_string(gameState->getPrevP2Sets()) + "\"\n";

  stringifiedGameState += "}";

  std::ofstream pin_file(update_path + "game_state_data.txt");
  pin_file << stringifiedGameState;
  pin_file.close();
}
