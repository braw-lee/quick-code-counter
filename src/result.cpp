#include "../include/qcc/result.hpp"
#include "../include/qcc/countInfo.hpp"
#include "../include/qcc/textFormatting.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <string>
#include <string_view>
#include <utility>
#include <iostream>
#include <vector>

void Result::insertCountInfo(CountInfo* ci)
{
	auto it = _finalData.find(ci->_languageIdentifier);
	if(it != _finalData.end())
	{
		it->second._lineInfo += ci->_lineInfo;
		it->second._fileCount++;
	}
	else
	{
		FileCountInfo temp(ci);
		_finalData[ci->_languageIdentifier] = temp;
	}
}

void Result::print()
{
	enum CellNames
	{
		language,
		fileCount,
		code,
		comment,
		blank,
		total,
		ratio
	};
	std::array<std::string, ratio + 1> heading
	{
		"Language",
		"FileCount",
		"Code",
		"Comments",
		"Blanks",
		"Total",
		"Ratio"
	};
	std::array<size_t, ratio + 1> cellSize 
	{
		heading[language].size(),
		heading[fileCount].size(),
		heading[code].size(),
		heading[comment].size(),
		heading[blank].size(),
		heading[total].size(),
		heading[ratio].size()
	};

	for(auto& it : _finalData)
	{
		cellSize[language] = std::max(cellSize[language], it.first.size());
		cellSize[fileCount] = std::max(cellSize[fileCount], std::to_string(it.second._fileCount).size());
		cellSize[code] = std::max(cellSize[code], std::to_string(it.second._lineInfo.code).size());
		cellSize[comment] = std::max(cellSize[comment], std::to_string(it.second._lineInfo.comments).size());
		cellSize[blank] = std::max(cellSize[blank], std::to_string(it.second._lineInfo.blanks).size());
		cellSize[total] = std::max(cellSize[total], std::to_string(it.second._lineInfo.total).size());
		cellSize[ratio] = std::max(cellSize[ratio], std::to_string(it.second._ratio).size());
	}
	size_t rowSize{22};
	for(auto it : cellSize)
		rowSize += it;
	std::string rowSeperator = std::string(rowSize,'-');

	for(size_t i=0; i<heading.size(); i++)
	{
		fillCell(heading[i], cellSize[i], true);
		if(i == language)
			std::cout<<padBoth(heading[i]);
		else
			std::cout<<padRight(heading[i]);
	}
	std::cout<<'\n'<<rowSeperator;
	for(auto& it : _finalData)
	{
		std::array<std::string, ratio + 1> cellString {
			it.first,
			std::to_string(it.second._fileCount),
			std::to_string(it.second._lineInfo.code),
			std::to_string(it.second._lineInfo.comments),
			std::to_string(it.second._lineInfo.blanks),
			std::to_string(it.second._lineInfo.total),
			std::to_string(it.second._ratio)
		};
		for(size_t i=0; i<cellString.size(); i++)
		{
			bool alignLeft = false;
			if(i == language)
				alignLeft = true;
			fillCell(cellString[i], cellSize[i], alignLeft);
		}
		std::cout<<'\n';
		for(size_t i=0; i<cellString.size(); i++)
		{
			if(i == 0)
				std::cout<<padBoth(cellString[i]);
			else
				std::cout<<padRight(cellString[i]);
		}
	}
	std::cout<<'\n';
}
