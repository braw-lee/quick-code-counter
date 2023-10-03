#ifndef QCC_TABLELANGUAGEWISE_HPP
#define QCC_TABLELANGUAGEWISE_HPP

#include "countInfo.hpp"
#include "fileCountInfo.hpp"
#include "languageId.hpp"
#include "utility.hpp"

#include <array>
#include <map>
#include <memory>
#include <string>

class TableLanguageWise {
  std::array<std::string, +LanguageWiseCellName::column_size> _heading;
  std::array<size_t, +LanguageWiseCellName::column_size> _cellSize;

  const std::map<LanguageId, FileCountInfo> &_finalData;
  std::string _rowSeperator;

  void setCellSize();
  void printHeading();
  void printColumn(
      std::array<std::string, +LanguageWiseCellName::column_size> &column);
  void setRowSeperator();
  void printRowSeperator();

public:
  TableLanguageWise(const std::map<LanguageId, FileCountInfo> &finalData);
  void print();
};

#endif
