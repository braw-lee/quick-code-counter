#include "../include/qcc/fileInfo.hpp"
#include <filesystem>
#include <memory>
#include <iostream>
#include <string>

FileInfo::FileInfo(const fs::path& tempFilePath, std::shared_ptr<LanguageData> languageData)
	:_filePath{tempFilePath},
	_languageData{languageData},
	_fileLanguage { _languageData->getLanguage(
		[this]()->std::string
		{
			if(_filePath.has_extension())
			{
				std::string ext{_filePath.extension()};
				return ext.substr(1);
			}
			else
				return "";
		}())}
{
}

void FileInfo::printLineInfo()
{
	std::cout<<"\nblanks :\t"<<_lineInfo.blanks;
	std::cout<<"\ncomments :\t"<<_lineInfo.comments;
	std::cout<<"\ncode :\t\t"<<_lineInfo.code;
	std::cout<<"\ntotal :\t\t"<<_lineInfo.total;
}
