#include "../include/qcc/counter.hpp"

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <memory>
#include <string_view>

Counter::Counter(FileInfo* fileInfo)
	:_fileInfo{fileInfo}, _currentMultiLineComment{nullptr}
{
}

std::unique_ptr<CountInfo> Counter::count()
{
	auto result{std::make_unique<CountInfo>(_fileInfo->_languageIdentifier)};
	if(auto fileHandle = std::ifstream{_fileInfo->_filePath})
	{
		std::string line;
		while(!fileHandle.eof())
		{
			std::getline(fileHandle, line);
			countLine(std::move(line), &result->_lineInfo);
		}
		--result->_lineInfo.blanks;
		result->_lineInfo.total = result->_lineInfo.blanks + result->_lineInfo.comments +  result->_lineInfo.code;
	}
	return result;
}

void Counter::countLine(std::string line, LineInfo* lineInfo)
{
	line = trimLeadingWhiteSpace(line);
	//if line has only white spaces, it is blank line
	if(isEmpty(line))
		lineInfo->blanks++;
	//if line aint blank, it must be either comment or code line
	else
	{	
		line = trimComments(line);
		line = trimLeadingWhiteSpace(line);
		//if line is empty/blank after trimming the comments, it is comment line
		if(isEmpty(line))
			lineInfo->comments++;
		//if line is not blank after trimming the comments, it is a code line
		else
			lineInfo->code++;
	}
}

std::string Counter::trimLeadingWhiteSpace(const std::string& line)
{
	int spaceIndex{};
	for(size_t i=0; i<line.size(); i++)
	{
		if(!std::isspace(line[i]))
			break;
		spaceIndex++;
	}
	return line.substr(spaceIndex);
}

bool Counter::isEmpty(const std::string& line)
{
	if(line.size() == 0)
		return true;
	else
		return false;
}

bool Counter::isSingleLineComment(const std::string& line)
{
	for(auto it : _fileInfo->_fileLanguage->singleLineComment)
		if(line.size() >= it.size() && line.substr(0,it.size()) == it)
				return true;
	return false;
}

std::string Counter::trimComments(const std::string& line)
{
	if(_currentMultiLineComment != nullptr)
	{
		size_t commentEndIndex = searchCommentEndIndex(line);
		if(commentEndIndex == std::string::npos)
			return "";
		auto remainingLine = line.substr(commentEndIndex); 
		return trimComments(remainingLine);
	}
	else
	{
		if(isSingleLineComment(line))
			return "";
		size_t commentStartIndex {searchCommentStartIndex(line)};
		size_t commentEndIndex;
		if(commentStartIndex == std::string::npos)
			return line;
		else
			commentEndIndex = searchCommentEndIndex(line, commentStartIndex);
		auto firstPart = line.substr(0,commentStartIndex);
		if(commentEndIndex == std::string::npos)
			return firstPart;
		auto remainingLine = line.substr(commentEndIndex); 
		auto secondPart = trimComments(remainingLine);
		return firstPart + secondPart;
	}
}

size_t Counter::searchCommentStartIndex(const std::string& line)
{
	for(size_t i=0; i<line.size(); i++)
		for(auto& it : _fileInfo->_fileLanguage->multiLineComment)
			if(line.size() - i >= it.start.size() && line.substr(i,it.start.size()) == it.start)
			{
				_currentMultiLineComment = &it;
				return i;
			}
	//if startIndex not found, return npos
	return std::string::npos;
}

size_t Counter::searchCommentEndIndex(const std::string& line, const size_t commentStartIndex)
{
	size_t ans;
	if(commentStartIndex != std::string::npos)
		ans = line.find(_currentMultiLineComment->end, commentStartIndex + _currentMultiLineComment->start.size());
	else
		ans = line.find(_currentMultiLineComment->end);
	if(ans != std::string::npos)
	{
		size_t endCommentSize = _currentMultiLineComment->end.size();
		_currentMultiLineComment = nullptr;
		return ans + endCommentSize;
	}
	return ans;
}
