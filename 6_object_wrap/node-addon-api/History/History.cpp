#include "History.h"

History::History() {
  _logger = new Logger(LOG_FILE_PATH);
}
History::~History() {}

void History::push(GameState state) {
  _history.push(state);
}

int History::size() {
  return _history.size();
}

GameState History::pop() {
  _logger->logUpdate("inside history pop...", __FUNCTION__);
  GameState lastGameState = _history.top();
  _history.pop();
  _logger->logUpdate("popped history.", __FUNCTION__);
  std::string player1_points = std::to_string(lastGameState.getPlayer1Points());
  // std::string player2_points = std::to_string(
  // lastGameState.getPlayer2Points()); std::string player1_games =
  // std::to_string( lastGameState.getPlayer1Games()); std::string player2_games
  // =  std::to_string( lastGameState.getPlayer2Games()); std::string
  // player1_sets =    std::to_string( lastGameState.getPlayer1Sets());
  // std::string player2_sets =    std::to_string(
  // lastGameState.getPlayer2Sets());
  _logger->logUpdate("player1_points __ " + player1_points, __FUNCTION__);
  // _logger->logUpdate( "popped state: " + player1_points + " " +
  // player2_points + " " + player1_games + " " + player2_games + " " +
  // player1_sets + " " + player2_sets, __FUNCTION__ );
  return lastGameState;
}
