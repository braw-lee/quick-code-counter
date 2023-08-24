#include "../include/qcc/fileInfo.hpp"
#include <filesystem>
#include <memory>
#include <iostream>
#include <string>

FileInfo::FileInfo(const fs::path& tempFilePath, const LanguageData& languageData)
	:_filePath{tempFilePath},
	_languageData{languageData},
	_languageIdentifier{_languageData.getIdentifier(_filePath)},
	_fileLanguage { _languageData.getLanguage(_languageIdentifier)}
{
}
