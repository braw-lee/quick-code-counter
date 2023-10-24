#ifndef QCC_DIRECTORYITERATOR_HPP
#define QCC_DIRECTORYITERATOR_HPP

#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;

std::vector<fs::path>
directoryIterator(const fs::path &targetDirectory,
                  const std::vector<std::string> &ignorePatterns,
                  const bool includeHidden = false);
bool ignoreFileOrDir(const std::string &name,
                     const std::vector<std::string> &ignorePatterns,
                     const bool includeHidden);
bool isHidden(const std::string &name);
#endif
