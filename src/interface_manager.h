#ifndef MANAGER_INTERFACE
#define MANAGER_INTERFACE

namespace kget {
  class IManager
  {
    public:
      ~IManager() = default;
      virtual int execute() = 0;
  };
};

#endif  // MANAGER_INTERFACE
