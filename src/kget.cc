/**
 * @file kget.cc
 * @brief 
 * @author Khoi Hoang
 * @version 1.0.0
 * @date 2018-09-09
 */

#include "kget.h"
#include "kget_status.h"

#include <exception>

using kget::Kget;

using std::exception;

Kget::Kget(unique_ptr<IManager>& manager,
           unique_ptr<ILogger>& logger)
{
  this->manager.swap(manager);
  this->logger.swap(logger);
}

int Kget::run()
{
  try {
    return this->manager->execute();
  } catch (exception unknownException){
    logger->warn("Uncaught exception: " + string(unknownException.what()));
    return kget::STATUS_FATAL_ERROR;
  }
}
