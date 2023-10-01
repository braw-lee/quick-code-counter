#include "fileInfo.hpp"

#include <filesystem>
#include <memory>
#include <iostream>
#include <string>

FileInfo::FileInfo(const fs::path& tempFilePath)
	:_filePath{tempFilePath},
	_languageIdentifier{_languageData.getIdentifier(_filePath)},
	_fileCommentInfo{_languageData.getCommentInfo(_languageIdentifier)}
{
}
