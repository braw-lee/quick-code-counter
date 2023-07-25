#ifndef LANGUAGE_DATA_HPP
#define LANGUAGE_DATA_HPP

#include "language.hpp"

#include <memory>
#include <unordered_map>
#include <string>

class LanguageData
{
private:
	const std::unordered_map<std::string,std::string> _extensionMap
	{
		{"cpp","c++ source"},
		{"cxx","c++ source"},
		{"py","python"}
	};
	const std::unordered_map<std::string,Language> _languageMap
	{
		{"c++ source",			//identifier
			{
				{"//"},			//single line comments
				{{"/*","*/"}},	//multiline comments
				{{"\"","\""}}	//quotes
			}
		},
		{"python",
			{
				{"#"},
				{
					{"'''","'''"},
					{"\"\"\"","\"\"\""}
				},
				{{"\"","\""}}
			}
		}
	};
public:
	std::shared_ptr<Language> getLanguage(std::string&& extension);
};

#endif
