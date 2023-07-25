#ifndef FILE_INFO
#define FILE_INFO

#include "language.hpp"
#include "languageData.hpp"
#include "lineInfo.hpp"

#include <filesystem>
#include <memory>
#include <string>

namespace fs = std::filesystem;

struct FileInfo
{
	fs::path _filePath;
	std::shared_ptr<LanguageData> _languageData;
	std::shared_ptr<Language> _fileLanguage;
	LineInfo _lineInfo;
	
	FileInfo(const fs::path& filePath, std::shared_ptr<LanguageData> languageData);
	//temp
	void printLineInfo();
};
#endif
