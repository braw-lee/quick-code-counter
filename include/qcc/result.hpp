#ifndef RESULT_HPP
#define RESULT_HPP

#include "fileCountInfo.hpp"
#include "countInfo.hpp"
#include "languageId.hpp"
#include <vector>

#include <array>
#include <memory>
#include <unordered_map>
#include <string>

class Result
{
	enum CellNames
	{
		language,
		fileCount,
		code,
		comment,
		blank,
		total,
		ratio,
		column_size
	};
	std::array<std::string, column_size> _heading
	{
		"Language",
		"FileCount",
		"Code",
		"Comments",
		"Blanks",
		"Total",
		"Ratio"
	};
	std::array<size_t, column_size> _cellSize 
	{
		_heading[language].size(),
		_heading[fileCount].size(),
		_heading[code].size(),
		_heading[comment].size(),
		_heading[blank].size(),
		_heading[total].size(),
		_heading[ratio].size()
	};

	std::array<std::string, column_size> _total;
	FileCountInfo _totalCount;
	std::unordered_map<LanguageId, FileCountInfo> _finalData;
	const std::vector<std::unique_ptr<CountInfo>>& _countInfoPtrs;
	std::string _rowSeperator;

	void setFinalData();
	void setCellSize();
	void printHeading();
	void printColumn(std::array<std::string, column_size>& column);
	void setRowSeperator();
	void printRowSeperator();
	void insertCountInfo(CountInfo* ci);
	void setTotalColumn();
	
public:
	Result(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs);
	void print();
};

#endif
