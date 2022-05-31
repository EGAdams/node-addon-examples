#ifndef Logger_h
#define Logger_h
#include <fstream>
#include <string>

class Logger {
 public:
  Logger(std::string file_path);
  ~Logger();
  void logUpdate(std::string message);

 private:
  std::string _file_path;
  std::ofstream _log_file;
};

#endif  // Logger_h