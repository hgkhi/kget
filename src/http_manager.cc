#include "http_manager.h"

#include "http_client.h"
#include "kget_status.h"
#include "byte_block.h"
#include "manager_utilities.h"

#include <unordered_map>
#include <vector>

using kget::HttpManager;
using kget::ByteBlock;

using std::unordered_map;
using std::vector;
using std::stoi;

HttpManager::HttpManager( const string& url,
                          size_t numberWorkers,
                          ILogger* logger)
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

  size_t contentLength = (size_t) stoi(this->resHeaderMap["Content-Length"]);
  vector<ByteBlock> byteBlocks = kget::divideByteBlocks(contentLength,
                                                        this->numberWorkers);
  return kget::STATUS_SUCCESS;
}

void HttpManager::validate()
{
  this->resHeaderMap = kget::head(this->url);
  this->flagValidUrl = !this->resHeaderMap.empty();
  
  /* Supports partial request if:
      Accept-Ranges: bytes
      Content-Length exists */
  this->flagSupportPartialRequests =
    (this->resHeaderMap["Accept-Ranges"] == "bytes" &&
     this->resHeaderMap.find("Content-Length") != this->resHeaderMap.end());
}
