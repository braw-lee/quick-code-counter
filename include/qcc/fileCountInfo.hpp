#ifndef QCC_FILECOUNTINFO_HPP
#define QCC_FILECOUNTINFO_HPP

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
