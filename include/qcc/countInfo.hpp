#ifndef COUNT_INFO_HPP
#define COUNT_INFO_HPP

#include "lineInfo.hpp"
#include "languageId.hpp"

#include <memory>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

struct CountInfo
{
	fs::path _filePath;
	LanguageId _languageIdentifier;
	LineInfo _lineInfo;

	CountInfo(fs::path filePath, LanguageId language);
};

#endif
