#ifndef COUNT_INFO_HPP
#define COUNT_INFO_HPP

#include "lineInfo.hpp"
#include "languageId.hpp"

#include <filesystem>

namespace fs = std::filesystem;

struct CountInfo
{
	const fs::path& _filePath;
	LanguageId _languageIdentifier;
	LineInfo _lineInfo;

	CountInfo(const fs::path& filePath, const LanguageId language);
};

#endif
