#ifndef QCC_USERINPUT_HPP
#define QCC_USERINPUT_HPP

#include "outputFormat.hpp"

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

struct UserInput {
  bool includeHidden;
  fs::path targetDirectory;
  std::vector<std::string> ignoreThem;
  OutputFormat outputFormat;
};

#endif
