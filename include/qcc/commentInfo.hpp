#ifndef COMMENT_INFO_HPP
#define COMMENT_INFO_HPP

#include "utility.hpp"

#include <string>
#include <vector>

struct CommentInfo
{
	std::vector<std::string> singleLineComment;
	std::vector<StringPair> multiLineComment;
	//std::vector<StringPair> quotes;
};

#endif
