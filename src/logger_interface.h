#ifndef LOGGER_INTERFACE
#define LOGGER_INTERFACE

#include <string>

namespace kget {
  class LoggerInterface;
};

using std::string;
using kget::LoggerInterface;

class LoggerInterface
{
  public:
    virtual void debug(const string& msg) = 0;
    virtual void info(const string& msg) = 0;
    virtual void warn(const string& msg) = 0;
};

#endif  // LOGGER_INTERFACE
