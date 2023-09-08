#ifndef VERBOSE_RESULT_HPP
#define VERBOSE_RESULT_HPP

#include "countInfo.hpp"

#include <memory>
#include <vector>

class VerboseResult
{
	enum CellNames
	{
		file,
		language,
		code,
		comment,
		blank,
		total,
		column_size
	};

	std::array<std::string, column_size> _heading
	{
		"File",
		"Language",
		"Code",
		"Comments",
		"Blanks",
		"Total",
	};

	std::array<size_t, column_size> _cellSize
	{
		_heading[file].size(),
		_heading[language].size(),
		_heading[code].size(),
		_heading[comment].size(),
		_heading[blank].size(),
		_heading[total].size(),
	};
	const std::vector<std::unique_ptr<CountInfo>>& _countInfoPtrs;
	std::string _rowSeperator;

	void setCellSize();
	void setRowSeperator();
	void printRowSeperator();
	void printHeading();
	void printColumn(std::array<std::string, column_size>& column);
public:
	VerboseResult(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs);
	void print();
};

#endif
