#include "../include/qcc/result.hpp"
#include "../include/qcc/countInfo.hpp"
#include "../include/qcc/textFormatting.hpp"
#include "../include/qcc/languageId.hpp"
#include "../include/qcc/fileCountInfo.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <iostream>
#include <vector>

Result::Result(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs)
	:_countInfoPtrs{countInfoPtrs}
{
	setFinalData();
	setTotalColumn();
	setCellSize();
	setRowSeperator();
}

void Result::setFinalData()
{
	for(auto& it : _countInfoPtrs)
		insertCountInfo(it.get());	
}

void Result::insertCountInfo(CountInfo* ci)
{
	auto it = _finalData.find(ci->_languageIdentifier);
	if(it != _finalData.end())
	{
		it->second._lineInfo += ci->_lineInfo;
		it->second._fileCount++;
		_totalCount._lineInfo += ci->_lineInfo;
	}
	else
	{
		FileCountInfo temp(ci);
		_finalData[ci->_languageIdentifier] = temp;
		_totalCount._lineInfo += temp._lineInfo;
	}
	++_totalCount._fileCount;
}

void Result::print()
{
	printHeading();
	printRowSeperator();
	for(auto& it : _finalData)
	{
		std::array<std::string, column_size> cellString {
			std::string(idToString(it.first)),	
			std::to_string(it.second._fileCount),
			std::to_string(it.second._lineInfo.code),
			std::to_string(it.second._lineInfo.comments),
			std::to_string(it.second._lineInfo.blanks),
			std::to_string(it.second._lineInfo.total),
			std::to_string(100.0 * it.second._lineInfo.total / _totalCount._lineInfo.total)
		};
		printColumn(cellString);
	}
	printRowSeperator();
	printColumn(_total);
	std::cout<<'\n';
}

void Result::setCellSize()
{
	for(auto& it : _finalData)
	{
		_cellSize[language] = std::max(_cellSize[language], idToString(it.first).size());
		_cellSize[fileCount] = std::max(_cellSize[fileCount], std::to_string(it.second._fileCount).size());
		_cellSize[code] = std::max(_cellSize[code], std::to_string(it.second._lineInfo.code).size());
		_cellSize[comment] = std::max(_cellSize[comment], std::to_string(it.second._lineInfo.comments).size());
		_cellSize[blank] = std::max(_cellSize[blank], std::to_string(it.second._lineInfo.blanks).size());
		_cellSize[total] = std::max(_cellSize[total], std::to_string(it.second._lineInfo.total).size());
		_cellSize[ratio] = std::max(_cellSize[ratio], std::to_string(100.0 * it.second._lineInfo.total / _totalCount._lineInfo.total).size());
	}
	_cellSize[language] = std::max(_cellSize[language], _total[language].size());
	_cellSize[fileCount] = std::max(_cellSize[fileCount], _total[fileCount].size());
	_cellSize[code] = std::max(_cellSize[code], _total[code].size());
	_cellSize[comment] = std::max(_cellSize[comment], _total[comment].size());
	_cellSize[blank] = std::max(_cellSize[blank], _total[blank].size());
	_cellSize[total] = std::max(_cellSize[total], _total[total].size());
	_cellSize[ratio] = std::max(_cellSize[ratio], _total[ratio].size());
}

void Result::printHeading()
{
	for(size_t i=0; i<_heading.size(); i++)
	{
		fillCell(_heading[i], _cellSize[i], true);
		if(i == 0)
			std::cout<<padBoth(_heading[i]);
		else
			std::cout<<padRight(_heading[i]);
	}
}

void Result::printColumn(std::array<std::string, column_size>& column)
{
	std::cout<<'\n';
	for(size_t i=0; i<column.size(); i++)
	{
		bool alignLeft = false;
		if(i == language)
			alignLeft = true;
		fillCell(column[i], _cellSize[i], alignLeft);
		if(i == 0)
			std::cout<<padBoth(column[i]);
		else
			std::cout<<padRight(column[i]);
	}
}

void Result::setRowSeperator()
{
	//cell_padding + left_cell_seperator + last_right_seperator
	size_t rowSize{(column_size) * 2 + column_size + 1};
	for(auto it : _cellSize)
		rowSize += it;
	_rowSeperator = std::string(rowSize,'-');
}

void Result::printRowSeperator()
{
	std::cout<<'\n'<<_rowSeperator;
}

void Result::setTotalColumn()
{
	_total = 
	{
		"Total",
		std::to_string(_totalCount._fileCount),
		std::to_string(_totalCount._lineInfo.code),
		std::to_string(_totalCount._lineInfo.comments),
		std::to_string(_totalCount._lineInfo.blanks),
		std::to_string(_totalCount._lineInfo.total),
		std::to_string(100.00)
	};
}
