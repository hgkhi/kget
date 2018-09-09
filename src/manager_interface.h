#ifndef MANAGER_INTERFACE
#define MANAGER_INTERFACE

namespace kget {
  class ManagerInterface
  {
    public:
      /**
       * @brief Carries the downloading job.
       * Calculates, assigns tasks for workers and report progress for user
       */
      virtual int execute() = 0;
  };
};

#endif  // MANAGER_INTERFACE
