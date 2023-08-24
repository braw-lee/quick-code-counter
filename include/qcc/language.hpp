#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include "utility.hpp"

#include <string>
#include <vector>

struct Language
{
	std::vector<std::string> singleLineComment;
	std::vector<StringPair> multiLineComment;
	//std::vector<StringPair> quotes;
};

#endif
