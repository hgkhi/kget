#ifndef MANAGER_UTILITIES
#define MANAGER_UTILITIES

#include "byte_block.h"

#include <vector>

using kget::ByteBlock;

using std::vector;

namespace kget {
  vector<ByteBlock> divideByteBlocks(size_t size);
}

#endif  // MANAGER_UTILITIES
