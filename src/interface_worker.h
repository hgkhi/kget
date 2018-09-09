#ifndef INTERFACE_WORKER
#define INTERFACE_WORKER

namespace kget {
  class IWorker
  {
    public:
      int execute();
      ~IWorker() = default;
  };
}

#endif  // INTERFACE_WORKER
