#ifndef HTTP_CLIENT
#define HTTP_CLIENT

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

namespace kget {
  unordered_map<string, string> head(const string& url);
};

#endif  // HTTP_CLIENT
