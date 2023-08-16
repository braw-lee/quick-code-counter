#ifndef TEXT_FORMATTING_HPP
#define TEXT_FORMATTING_HPP

#include <string>

std::string padBoth(const std::string& s);
std::string padLeft(const std::string& s);
std::string padRight(const std::string& s);
void fillCell(std::string& cell, size_t cellSize, bool alignLeft);
#endif
