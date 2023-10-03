#include "tableLanguageWise.hpp"
#include "countInfo.hpp"
#include "fileCountInfo.hpp"
#include "languageId.hpp"
#include "textFormatting.hpp"
#include "utility.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

using enum LanguageWiseCellName;

TableLanguageWise::TableLanguageWise(
    const std::map<LanguageId, FileCountInfo> &finalData)
    : _finalData{finalData}, _heading{"Language", "FileCount", "Code",
                                      "Comments", "Blanks",    "Total",
                                      "Ratio"},
      _cellSize{_heading[+language].size(), _heading[+fileCount].size(),
                _heading[+code].size(),     _heading[+comment].size(),
                _heading[+blank].size(),    _heading[+total].size(),
                _heading[+ratio].size()} {
  setCellSize();
  setRowSeperator();
}

void TableLanguageWise::print() {
  printHeading();
  printRowSeperator();
  for (auto &it : _finalData) {
    std::array<std::string, +column_size> cellString{
        std::string(idToString(it.first)),
        std::to_string(it.second._fileCount),
        std::to_string(it.second._lineInfo.code),
        std::to_string(it.second._lineInfo.comments),
        std::to_string(it.second._lineInfo.blanks),
        std::to_string(it.second._lineInfo.total),
        std::to_string(100.0 * it.second._lineInfo.total /
                       _finalData.at(LanguageId::total)._lineInfo.total)};
    printColumn(cellString);
  }
  std::cout << '\n';
}

void TableLanguageWise::setCellSize() {
  using enum LanguageWiseCellName;
  for (auto &it : _finalData) {
    _cellSize[+language] =
        std::max(_cellSize[+language], idToString(it.first).size());
    _cellSize[+fileCount] = std::max(
        _cellSize[+fileCount], std::to_string(it.second._fileCount).size());
    _cellSize[+code] = std::max(
        _cellSize[+code], std::to_string(it.second._lineInfo.code).size());
    _cellSize[+comment] =
        std::max(_cellSize[+comment],
                 std::to_string(it.second._lineInfo.comments).size());
    _cellSize[+blank] = std::max(
        _cellSize[+blank], std::to_string(it.second._lineInfo.blanks).size());
    _cellSize[+total] = std::max(
        _cellSize[+total], std::to_string(it.second._lineInfo.total).size());
    _cellSize[+ratio] = std::max(
        _cellSize[+ratio],
        std::to_string(100.0 * it.second._lineInfo.total /
                       _finalData.at(LanguageId::total)._lineInfo.total)
            .size());
  }
}

void TableLanguageWise::printHeading() {
  for (size_t i = 0; i < _heading.size(); i++) {
    fillCell(_heading[i], _cellSize[i], true);
    if (i == 0)
      std::cout << padBoth(_heading[i]);
    else
      std::cout << padRight(_heading[i]);
  }
}

void TableLanguageWise::printColumn(
    std::array<std::string, +column_size> &column) {
  std::cout << '\n';
  for (size_t i = 0; i < column.size(); i++) {
    bool alignLeft = false;
    if (i == +language)
      alignLeft = true;
    fillCell(column[i], _cellSize[i], alignLeft);
    if (i == 0)
      std::cout << padBoth(column[i]);
    else
      std::cout << padRight(column[i]);
  }
}

void TableLanguageWise::setRowSeperator() {
  // cell_padding + left_cell_seperator + last_right_seperator
  size_t rowSize{(+column_size) * 2 + (+column_size) + 1};
  for (auto it : _cellSize)
    rowSize += it;
  _rowSeperator = std::string(rowSize, '-');
}

void TableLanguageWise::printRowSeperator() {
  std::cout << '\n' << _rowSeperator;
}
