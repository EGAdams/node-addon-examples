#ifndef Logger_h
#define Logger_h
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include "GameTimer.h"

#if defined _WIN32 || defined _WIN64

class Logger {
 public:
  Logger(std::string file_path);
  ~Logger();
  void logUpdate(std::string message, std::string caller);
  decltype(std::chrono::seconds().count()) _get_seconds_since_epoch();
  int _get_random_number();
  bool inArray(int supposed_random_number);

 private:
  std::string _file_path;
  std::ofstream _log_file;
  std::vector<int> _used_random_numbers;
};
#else
class Logger {
 public:
  Logger(String path);
  ~Logger();
  void logUpdate(String message, String caller);
};
#endif  // defined _WIN*

#endif  // Logger_h