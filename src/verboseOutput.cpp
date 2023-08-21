#include "../include/qcc/verboseOutput.hpp"
#include "../include/qcc/textFormatting.hpp"
#include "../include/qcc/languageId.hpp"

#include <array>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

void printVerboseOutput(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs)
{
	enum CellNames
	{
		file,
		language,
		code,
		comment,
		blank,
		total,
		ratio
	};
	std::array<std::string, ratio + 1> heading
	{
		"File",
		"Language",
		"Code",
		"Comments",
		"Blanks",
		"Total",
		"Ratio"
	};
	std::array<size_t, ratio + 1> cellSize
	{
		heading[file].size(),
		heading[language].size(),
		heading[code].size(),
		heading[comment].size(),
		heading[blank].size(),
		heading[total].size(),
		heading[ratio].size()
	};
	for(auto& ptr : countInfoPtrs)
	{
		cellSize[file] = std::max(cellSize[file], ptr->_filePath.generic_string().size());
		cellSize[language] = std::max(cellSize[language], idToString(ptr->_languageIdentifier).size());
		cellSize[code] = std::max(cellSize[code], std::to_string(ptr->_lineInfo.code).size());
		cellSize[comment] = std::max(cellSize[comment], std::to_string(ptr->_lineInfo.comments).size());
		cellSize[blank] = std::max(cellSize[blank], std::to_string(ptr->_lineInfo.blanks).size());
		cellSize[total] = std::max(cellSize[total], std::to_string(ptr->_lineInfo.total).size());
		cellSize[ratio] = std::max(cellSize[ratio], std::to_string(1.0000).size());
	}
	size_t rowSize = 22;
	for(auto it : cellSize)
		rowSize += it;
	std::string rowSeperator = std::string(rowSize, '-');
	for(size_t i=0; i<heading.size(); i++)
	{
		fillCell(heading[i], cellSize[i], true);
		if(i == file)
			std::cout<<padBoth(heading[i]);
		else
			std::cout<<padRight(heading[i]);
	}
	std::cout<<'\n'<<rowSeperator;
	for(auto& ptr : countInfoPtrs)
	{
		std::array<std::string, ratio + 1> cellString
		{
			ptr->_filePath.generic_string(),
			std::string(idToString(ptr->_languageIdentifier)),
			std::to_string(ptr->_lineInfo.code),
			std::to_string(ptr->_lineInfo.comments),
			std::to_string(ptr->_lineInfo.blanks),
			std::to_string(ptr->_lineInfo.total),
			std::to_string(0.00)
		};
		for(size_t i=0; i<cellString.size(); i++)
		{
			bool alignLeft = false;
			if(i == file || i == language)
				alignLeft = true;
			fillCell(cellString[i], cellSize[i], alignLeft);
		}
		std::cout<<'\n';
		for(size_t i=0; i<cellString.size(); i++)
		{
			if(i == file)
				std::cout<<padBoth(cellString[i]);
			else
				std::cout<<padRight(cellString[i]);
		}
	}
	std::cout<<'\n';
}
