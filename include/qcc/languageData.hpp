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
		{"h","c header"},
		
		{"c","c source"},
		
		{"hh","c++ header"},
		{"hpp","c++ header"},
		{"hxx","c++ header"},

		{"cc","c++ source"},
		{"cpp","c++ source"},
		{"cxx","c++ source"},
		{"c++","c++ source"},
		
		{"cmake","CMake"},

		{"css","CSS"},

		{"html","HTML"},
		{"htm","HTML"},

		{"js","javascript"},
		{"mjs", "javascript"},

		{"json","JSON"},

		{"md","markdown"},
		{"markdown","markdown"},
	
		{"py","python"}
	};
	const std::unordered_map<std::string,Language> _languageMap
	{
		{	"c header",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	"c source",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	"c++ header",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	"c++ source",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{
			"CMake",
			{
				{"#"},
				{},
				{{"\"","\""}}
			}
		},
		{	"CSS",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{
			"HTML",
			{
				{},
				{{"<!--","-->"}},
				{{"\"","\""}, {"'","'"}}
			}
		},
		{
			"javascript",
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{
			"JSON",
			{
				{},
				{},
				{}
			}
		},
		{
			"markdown",
			{
				{},
				{},
				{}
			}
		},
		{	"python",
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
	std::string getIdentifier(std::string&& extension);
	std::shared_ptr<Language> getLanguage(const std::string& extension);
};

#endif
