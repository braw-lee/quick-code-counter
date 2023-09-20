#ifndef LINE_INFO_HPP
#define LINE_INFO_HPP

#include <cstddef>

struct LineInfo
{
	size_t code{};
	size_t comments{};
	size_t blanks{};
	size_t total{};
};

LineInfo operator+(const LineInfo& first, const LineInfo& second);
void operator+=(LineInfo& first, const LineInfo& second);
bool operator==(const LineInfo& first, const LineInfo& second);

#endif
