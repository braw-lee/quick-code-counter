#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "fileInfo.hpp"
#include <memory>

class Counter
{
public:
	enum class State 
	{
		code,
		lineComment,
		multiLineComment,
		justOutsideMultiLineComment,
		quotes
	};
private:
	FileInfo* _fileInfo;
	Counter::State _state{State::code};
	StringPair const* _currentMultiLineComment;
public:
	Counter(FileInfo* fileInfo);
	void count();
	void countLine(std::string line);
	std::string trimLeadingWhiteSpace(const std::string& line);
	bool isEmpty(const std::string& line);
	bool isSingleLineComment(const std::string& line);
	std::string trimComments(const std::string& line);
	size_t searchCommentStartIndex(const std::string& line);
	size_t searchCommentEndIndex(const std::string& line, const size_t commentStartIndex = std::string::npos);
};
#endif
