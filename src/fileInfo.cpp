#include "fileInfo.hpp"

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

FileInfo::FileInfo(fs::path tempFilePath)
    : _filePath{std::move(tempFilePath)},
      _languageIdentifier{_languageData.getIdentifier(_filePath)},
      _fileCommentInfo{_languageData.getCommentInfo(_languageIdentifier)} {}
