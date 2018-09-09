#ifndef HTTP_MANAGER
#define HTTP_MANAGER

#include "manager_interface.h"
#include "logger_interface.h"

#include <string>

using kget::ManagerInterface;
using kget::LoggerInterface;

using std::string;

namespace kget {
  class HttpManager : public ManagerInterface
  {
    public:
      HttpManager(  const string& url,
          size_t numberWorkers,
          LoggerInterface* logger);
      ~HttpManager();
      int execute();

    private:
      void validate();

      string url;
      size_t numberWorkers;
      LoggerInterface* logger;

      bool flagValidUrl;
      bool flagSupportPartialRequests;
  };
};




#endif  // HTTP_MANAGER
