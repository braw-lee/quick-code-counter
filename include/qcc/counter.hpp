#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "fileInfo.hpp"
#include "countInfo.hpp"

#include <memory>

class Counter
{
private:
	FileInfo* _fileInfo;
	StringPair const* _currentMultiLineComment;
public:
	Counter();
	std::unique_ptr<CountInfo> count(FileInfo* fileInfo);
private:
	void countLine(std::string line, LineInfo* lineInfo);
	std::string trimLeadingWhiteSpace(const std::string& line);
	bool isEmpty(const std::string& line);
	bool isSingleLineComment(const std::string& line);
	std::string trimComments(const std::string& line);
	size_t searchCommentStartIndex(const std::string& line);
	size_t searchCommentEndIndex(const std::string& line, const size_t commentStartIndex = std::string::npos);
	size_t countTotalLines(std::ifstream& fileHandle);
};
#endif
