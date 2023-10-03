#ifndef QCC_LINEINFO_HPP
#define QCC_LINEINFO_HPP

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
