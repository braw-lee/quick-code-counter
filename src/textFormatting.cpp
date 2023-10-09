#include "textFormatting.hpp"

std::string padBoth(const std::string &s) { return "| " + s + " |"; }

std::string padLeft(const std::string &s) { return "| " + s + " "; }

std::string padRight(const std::string &s) { return " " + s + " |"; }

void fillCell(std::string &cell, size_t cellSize, bool alignLeft) {
  size_t currCellSize = cell.size();
  while (currCellSize != cellSize) {
    if (alignLeft)
      cell += ' ';
    else
      cell.insert(0, 1, ' ');
    currCellSize = cell.size();
  }
}
