#include "fileCountInfo.hpp"

FileCountInfo::FileCountInfo(CountInfo *ci)
    : _fileCount{1}, _lineInfo{ci->_lineInfo} {}
