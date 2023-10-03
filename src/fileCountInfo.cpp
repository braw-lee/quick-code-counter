#include "fileCountInfo.hpp"

FileCountInfo::FileCountInfo() {}
FileCountInfo::FileCountInfo(CountInfo *ci)
    : _fileCount{1}, _lineInfo{ci->_lineInfo} {}
