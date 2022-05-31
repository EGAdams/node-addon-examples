#include "Logger.h"
#include <ctime>
#include <iostream>

Logger::Logger(std::string file_path) : _file_path(file_path) {
  std::cout << "Constructing Logger..." << std::endl;
  std::cout << "opening file:" << file_path << std::endl;
  _log_file.open(_file_path, std::ios::out | std::ios::app);
  std::cout << "file opened:" << _log_file.is_open() << std::endl;
}

Logger::~Logger() {
  std::cout << "Destructing Logger..." << std::endl;
  _log_file.close();
}

void Logger::logUpdate(std::string message) {
  std::cout << "Logger::log(" << message << ")" << std::endl;
  std::cout << "time: " << std::time(0) << std::endl;
  time_t now = time(0);
  std::string time_string = ctime(&now);
  std::srand(
      std::time(nullptr));  // use current time as seed for random generator
  int random_variable = std::rand();
  _log_file << "{\"timestamp\":" << time_string;
  _log_file << ",\"id\":\"MessageManager_" << random_variable;
  _log_file << "_" << time_string << "\",\"message\":\"" << message
            << "\",\"method\":\"unknown\"}";
  _log_file << std::endl;
  std::cout << "done Logger::log(" << message << ")" << std::endl;
}
