#include "directoryIterator.hpp"

#include <algorithm>
#include <filesystem>
#include <fnmatch.h>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

std::vector<fs::path>
directoryIterator(const fs::path &targetDirectory,
                  const std::vector<std::string> &ignorePatterns,
                  const bool includeHidden) {
  // return empty array if invalid path
  if (!fs::exists(targetDirectory))
    return {};
  std::vector<fs::path> result;
  // if path is to a file, return single file path
  if (!fs::is_directory(targetDirectory)) {
    if (!ignoreFileOrDir(targetDirectory.filename(), ignorePatterns,
                         includeHidden))
      result.push_back(targetDirectory);
    return result;
  }
  // iterate recursively over the targetDirectory
  // disable recursion if directory is to be ignored
  // push to result if file is not to be ignored
  // else do nothing
  for (auto it = fs::recursive_directory_iterator(targetDirectory);
       it != fs::recursive_directory_iterator(); it++) {
    if (ignoreFileOrDir(it->path().filename(), ignorePatterns, includeHidden)) {
      if (it->is_directory())
        it.disable_recursion_pending();
    } else {
      if (!it->is_directory())
        result.push_back(it->path());
    }
  }
  // return the vector of fs::path of found files
  return result;
}

bool isHidden(const std::string &name) {
  if (name.at(0) == '.')
    return true;
  return false;
}

bool ignoreFileOrDir(const std::string &name,
                     const std::vector<std::string> &ignorePatterns,
                     const bool includeHidden) {
  if (!includeHidden && isHidden(name))
    return true;
  // ignore file or directory if it matches any pattern in ignoreThem
  for (const auto &pattern : ignorePatterns) {
    // fnmatch() returns 0 for a successfull match
    if (fnmatch(pattern.c_str(), name.c_str(), FNM_PATHNAME) == 0) {
      return true;
    }
  }
  return false;
}
