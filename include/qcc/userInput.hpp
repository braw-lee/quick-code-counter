#ifndef QCC_USERINPUT_HPP
#define QCC_USERINPUT_HPP

#include "outputFormat.hpp"

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

struct UserInput {
  bool includeHidden;
  bool includeUnknown;
  fs::path targetDirectory;
  std::vector<std::string> ignorePatterns;
  OutputFormat outputFormat;
};

#endif
