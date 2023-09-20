#include "../include/qcc/lineInfo.hpp"

LineInfo operator+(const LineInfo& first, const LineInfo& second)
{
	return{first.code + second.code, first.comments + second.comments ,first.blanks + second.blanks, first.total + second.total};
}

void operator+=(LineInfo& first, const LineInfo& second)
{
	first.blanks += second.blanks;
	first.code += second.code;
	first.comments += second.comments;
	first.total += second.total;
}

bool operator==(const LineInfo& first, const LineInfo& second)
{
	if(first.total != second.total || first.blanks != second.blanks || first.code != second.code || first.comments != second.comments)
		return false;
	else
		return true;
}
