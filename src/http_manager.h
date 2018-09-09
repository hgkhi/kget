/**
 * @file http_manager.h
 * @brief 
 * @author Khoi Hoang
 * @version 1.0.0
 * @date 2018-09-09
 */
#ifndef HTTP_MANAGER
#define HTTP_MANAGER

#include "interface_manager.h"
#include "interface_logger.h"

#include <string>
#include <unordered_map>

using kget::IManager;
using kget::ILogger;

using std::string;
using std::unordered_map;

namespace kget {
  class HttpManager : public IManager
  {
    public:
      HttpManager(  const string& url,
          size_t numberWorkers,
          ILogger* logger);
      ~HttpManager();
      int execute();

    private:
      void validate();

      string url;
      size_t numberWorkers;
      ILogger* logger;

      bool flagValidUrl;
      bool flagSupportPartialRequests;

      unordered_map<string, string> resHeaderMap;
  };
};




#endif  // HTTP_MANAGER
