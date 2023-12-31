#include "tableVerbose.hpp"
#include "languageId.hpp"
#include "textFormatting.hpp"
#include "utility.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using enum VerboseCellName;

TableVerbose::TableVerbose(
    const std::vector<std::unique_ptr<CountInfo>> &countInfoPtrs)
    : _countInfoPtrs{countInfoPtrs},
      _heading{
          "File", "Language", "Code", "Comments", "Blanks", "Total",
      },
      _cellSize{
          _heading[+file].size(),  _heading[+language].size(),
          _heading[+code].size(),  _heading[+comment].size(),
          _heading[+blank].size(), _heading[+total].size(),
      } {
  setCellSize();
  setRowSeperator();
}

void TableVerbose::print() {
  printHeading();
  printRowSeperator();

  for (auto &ptr : _countInfoPtrs) {
    std::array<std::string, +column_size> cellString{
        ptr->_filePath.generic_string(),
        std::string(idToString(ptr->_languageIdentifier)),
        std::to_string(ptr->_lineInfo.code),
        std::to_string(ptr->_lineInfo.comments),
        std::to_string(ptr->_lineInfo.blanks),
        std::to_string(ptr->_lineInfo.total),
    };
    printColumn(cellString);
  }
  std::cout << '\n';
}

void TableVerbose::setCellSize() {
  for (auto &ptr : _countInfoPtrs) {
    _cellSize[+file] =
        std::max(_cellSize[+file], ptr->_filePath.generic_string().size());
    _cellSize[+language] = std::max(
        _cellSize[+language], idToString(ptr->_languageIdentifier).size());
    _cellSize[+code] =
        std::max(_cellSize[+code], std::to_string(ptr->_lineInfo.code).size());
    _cellSize[+comment] = std::max(
        _cellSize[+comment], std::to_string(ptr->_lineInfo.comments).size());
    _cellSize[+blank] = std::max(_cellSize[+blank],
                                 std::to_string(ptr->_lineInfo.blanks).size());
    _cellSize[+total] = std::max(_cellSize[+total],
                                 std::to_string(ptr->_lineInfo.total).size());
  }
}

void TableVerbose::setRowSeperator() {
  // cell_padding + left_cell_seperator + last_right_seperator
  size_t rowSize{(+column_size) * 2 + (+column_size) + 1};
  for (auto it : _cellSize)
    rowSize += it;
  _rowSeperator = std::string(rowSize, '-');
}

void TableVerbose::printRowSeperator() { std::cout << '\n' << _rowSeperator; }

void TableVerbose::printHeading() {
  for (size_t i = 0; i < _heading.size(); i++) {
    fillCell(_heading[i], _cellSize[i], true);
    if (i == 0)
      std::cout << padBoth(_heading[i]);
    else
      std::cout << padRight(_heading[i]);
  }
}

void TableVerbose::printColumn(std::array<std::string, +column_size> &column) {
  std::cout << '\n';
  for (size_t i = 0; i < column.size(); i++) {
    bool alignLeft = false;
    if (i == +language || i == +file)
      alignLeft = true;
    fillCell(column[i], _cellSize[i], alignLeft);
    if (i == 0)
      std::cout << padBoth(column[i]);
    else
      std::cout << padRight(column[i]);
  }
}
