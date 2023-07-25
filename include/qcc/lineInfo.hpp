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

#endif
