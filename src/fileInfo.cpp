#include "../include/qcc/fileInfo.hpp"
#include <filesystem>
#include <memory>
#include <iostream>
#include <string>

FileInfo::FileInfo(const fs::path& tempFilePath, std::shared_ptr<LanguageData> languageData)
	:_filePath{tempFilePath},
	_languageData{languageData},
	_languageIdentifier{_languageData->getIdentifier(
			[this]()->std::string
			{
				if(_filePath.has_extension())
				{
					std::string ext{_filePath.extension()};
					return ext.substr(1);
				}
				else
					return "";
			}())},
	_fileLanguage { _languageData->getLanguage(_languageIdentifier)}
{
}
