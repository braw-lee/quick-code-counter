#include "csvVerbose.hpp"

#include <string>
#include <iostream>

void printCsvVerbose(const std::vector<std::unique_ptr<CountInfo>>& cip)
{
	std::string s;
	for(auto& it : cip)
	{
		s += std::string{it->_filePath} + ',' +
			std::string{idToString(it->_languageIdentifier)} + ',' +
			std::to_string(it->_lineInfo.code) + ',' +
			std::to_string(it->_lineInfo.comments) + ',' +
			std::to_string(it->_lineInfo.blanks) + ',' +
			std::to_string(it->_lineInfo.total) + '\n';
	}
	std::cout << s;
}
