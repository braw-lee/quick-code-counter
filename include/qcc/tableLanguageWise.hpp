#ifndef TLW_HPP
#define TLW_HPP

#include "fileCountInfo.hpp"
#include "countInfo.hpp"
#include "languageId.hpp"
#include "utility.hpp"

#include <map>
#include <array>
#include <memory>
#include <string>

class TableLanguageWise
{
	std::array<std::string, +LanguageWiseCellName::column_size> _heading;
	std::array<size_t, +LanguageWiseCellName::column_size> _cellSize;

	const std::map<LanguageId, FileCountInfo>& _finalData;
	std::string _rowSeperator;

	void setCellSize();
	void printHeading();
	void printColumn(std::array<std::string, +LanguageWiseCellName::column_size>& column);
	void setRowSeperator();
	void printRowSeperator();
public:
	TableLanguageWise(const std::map<LanguageId, FileCountInfo>& finalData);
	void print();
};

#endif
