#include "http_manager.h"

#include "http_client.h"
#include "kget_status.h"
#include "byte_block.h"
#include "manager_utilities.h"

#include <unordered_map>

using kget::HttpManager;
using kget::ByteBlock;

using std::unordered_map;

HttpManager::HttpManager( const string& url,
                          size_t numberWorkers,
                          LoggerInterface* logger)
{
  this->url = url;
  this->numberWorkers = numberWorkers;
  this->logger = logger;

  this->validate();
}

int HttpManager::execute()
{
  if (!this->flagValidUrl) {
    this->logger->warn("Invalid URL");
    return kget::STATUS_INVALID_URL;
  }

  if (!this->flagSupportPartialRequests) {
    this->logger->warn("Non-partial request not supported yet");
    return kget::STATUS_NOT_SUPPORTED;
  }  

  return kget::STATUS_SUCCESS;
}

void HttpManager::validate()
{
  unordered_map<string, string> headerMap = kget::head(this->url);
  this->flagValidUrl = !headerMap.empty();
  
  /* Supports partial request if:
      Accept-Ranges: bytes
      Content-Length exists */
  this->flagSupportPartialRequests =
    (headerMap["Accept-Ranges"] == "bytes" &&
     headerMap.find("Content-Length") != headerMap.end());
}
