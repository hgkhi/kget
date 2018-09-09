#ifndef LOGGER_INTERFACE
#define LOGGER_INTERFACE

#include <string>

using std::string;

namespace kget {
  class LoggerInterface
  {
    public:
      virtual void debug(const string& msg) = 0;
      virtual void info(const string& msg) = 0;
      virtual void warn(const string& msg) = 0;
  };
};

#endif  // LOGGER_INTERFACE
