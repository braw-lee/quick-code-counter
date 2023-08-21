#ifndef FILE_INFO
#define FILE_INFO

#include "language.hpp"
#include "languageData.hpp"
#include "lineInfo.hpp"
#include "languageId.hpp"

#include <filesystem>
#include <memory>
#include <string>

namespace fs = std::filesystem;

struct FileInfo
{
	fs::path _filePath;
	const LanguageData& _languageData;
	LanguageId _languageIdentifier;
	std::shared_ptr<Language> _fileLanguage;
	
	FileInfo(const fs::path& filePath, const LanguageData& languageData);
	//temp
};
#endif
