#ifndef COUNT_INFO_HPP
#define COUNT_INFO_HPP

#include "lineInfo.hpp"
#include "language.hpp"

#include <memory>
#include <string>

struct CountInfo
{
	std::string _languageIdentifier;
	LineInfo _lineInfo;

	CountInfo(std::string language);
};

#endif
