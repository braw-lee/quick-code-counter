#include "jsonVerbose.hpp"
#include "languageId.hpp"

#include <nlohmann/json.hpp>
#include <iostream>

void printJsonVerbose(const std::vector<std::unique_ptr<CountInfo>>& cip)
{
	nlohmann::json j;
	for(auto& it : cip)
	{
		j.push_back
		({
		 {"File", it->_filePath},
		 {"Language", idToString(it->_languageIdentifier)},
		 {"LOC", it->_lineInfo.code},
		 {"Comments", it->_lineInfo.comments},
		 {"Blanks", it->_lineInfo.blanks},
		 {"Total", it->_lineInfo.total}
		});
	}
	std::cout << j.dump(4);
}
