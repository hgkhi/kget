/**
 * @file kget.h
 * @brief 
 * @author Khoi Hoang
 * @version 1.0.0
 * @date 2018-09-09
 */
#ifndef KGET
#define KGET

#include "interface_manager.h"
#include "interface_worker.h"
#include "interface_logger.h"

#include <memory>

using kget::IManager;
using kget::IWorker;

using std::unique_ptr;
using std::string;

namespace kget {
  class Kget
  {
    public:
      Kget( unique_ptr<IManager>& manager,
            unique_ptr<ILogger>& logger);
      int run();

    private:
      unique_ptr<IManager> manager;
      unique_ptr<ILogger> logger;
  };
}

#endif  // KGET
