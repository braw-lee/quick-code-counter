#ifndef TABLE_VERBOSE_HPP
#define TABLE_VERBOSE_HPP

#include "countInfo.hpp"
#include "utility.hpp"

#include <memory>

class TableVerbose
{
	std::array<std::string, +VerboseCellName::column_size> _heading;
	std::array<size_t, +VerboseCellName::column_size> _cellSize;
	const std::vector<std::unique_ptr<CountInfo>>& _countInfoPtrs;
	std::string _rowSeperator;

	void setCellSize();
	void setRowSeperator();
	void printRowSeperator();
	void printHeading();
	void printColumn(std::array<std::string, +VerboseCellName::column_size>& column);
public:
	TableVerbose(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs);
	void print();
};

#endif
