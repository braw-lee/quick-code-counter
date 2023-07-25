#ifndef DIRECTORY_ITERATOR_HPP
#define DIRECTORY_ITERATOR_HPP

#include <vector>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

std::vector<fs::path> directoryIterator(fs::path& targetDirectory, std::vector<std::string>& ignoreThem, bool ignoreHiddenFiles = false);

#endif
