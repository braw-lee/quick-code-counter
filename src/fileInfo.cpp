#include "fileInfo.hpp"

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

FileInfo::FileInfo(const fs::path &tempFilePath)
    : _filePath{tempFilePath}, _languageIdentifier{_languageData.getIdentifier(
                                   _filePath)},
      _fileCommentInfo{_languageData.getCommentInfo(_languageIdentifier)} {}
