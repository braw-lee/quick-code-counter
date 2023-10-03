#ifndef FILE_COUNT_INFO_HPP
#define FILE_COUNT_INFO_HPP

#include "lineInfo.hpp"
#include "countInfo.hpp"

struct FileCountInfo
{
	size_t _fileCount{};
	LineInfo _lineInfo{};

	FileCountInfo();
	FileCountInfo(CountInfo* ci);
};

#endif
