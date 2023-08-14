#ifndef COUNT_INFO_HPP
#define COUNT_INFO_HPP

#include "lineInfo.hpp"
#include "language.hpp"

#include <memory>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

struct CountInfo
{
	fs::path _filePath;
	std::string _languageIdentifier;
	LineInfo _lineInfo;

	CountInfo(fs::path filePath, std::string language);
};

#endif
