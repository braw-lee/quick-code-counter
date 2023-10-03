#ifndef QCC_DIRECTORYITERATOR_HPP
#define QCC_DIRECTORYITERATOR_HPP

#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;

std::vector<fs::path> directoryIterator(fs::path& targetDirectory, std::vector<std::string>& ignoreThem, bool ignoreHiddenFiles = false);

#endif
