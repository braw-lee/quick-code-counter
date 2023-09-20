#ifndef FILE_INFO
#define FILE_INFO

#include "commentInfo.hpp"
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
	static inline const LanguageData _languageData{};
	LanguageId _languageIdentifier;
	std::shared_ptr<CommentInfo> _fileCommentInfo;
	
	FileInfo(const fs::path& filePath);
};
#endif
