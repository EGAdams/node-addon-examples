#include "Logger.h"
#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <regex>

#if defined _WIN32 || defined _WIN64
Logger::Logger(std::string file_path) : _file_path(file_path) {
  std::cout << "Constructing Logger..." << std::endl;
  std::cout << "opening file:" << file_path << std::endl;
  _log_file.open(_file_path, std::ios::out | std::ios::app);
}

Logger::~Logger() {
  std::cout << "Destructing Logger..." << std::endl;
  _log_file.close();
}

void Logger::logUpdate(std::string message, std::string caller = "unknown") {
  message = std::regex_replace(message, std::regex(":"), "\\:");
  std::cout << "Logger::log(" << message << ")" << std::endl;
  std::cout << "time: " << std::time(0) << std::endl;
  int random_variable = this->_get_random_number();
  _log_file << "{\"timestamp\":"
            << this->_get_seconds_since_epoch() * 1000;  // timestamp
  _log_file << ",\"id\":\"MessageManager_" << random_variable << "_"
            << this->_get_seconds_since_epoch() * 1000;  // id
  _log_file << "\",\"message\":\"" << message;           // message
  _log_file << "\",\"method\":\"" << caller << "\"}";    // method
  _log_file << std::endl;
  std::cout << "done Logger::log(" << message << ")" << std::endl;
}

decltype(std::chrono::seconds().count()) Logger::_get_seconds_since_epoch() {
  const auto now = std::chrono::system_clock::now();
  const auto epoch = now.time_since_epoch();
  const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
  return seconds.count();
}

int Logger::_get_random_number() {
  time_t now = time(0);
  std::srand(std::time(&now));  // use current time as seed for random generator
  GameTimer::gameDelay(100);
  std::cout << "game millis before log: "
            << this->_get_seconds_since_epoch() * 1000 << std::endl;
  int random_variable = std::rand();
  while (inArray(random_variable)) {
    random_variable++;
  }
  _used_random_numbers.push_back(random_variable);
  return random_variable;
}

bool Logger::inArray(int supposed_random_number) {
  if (std::count(_used_random_numbers.begin(),
                 _used_random_numbers.end(),
                 supposed_random_number) > 0) {
    return true;
  }
  return false;
}
#else
Logger::Logger(String path) {}
Logger::~Logger() {}
void Logger::logUpdate(String message, String caller = "unknown") {}
#endif
