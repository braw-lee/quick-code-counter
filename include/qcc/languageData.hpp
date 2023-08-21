#ifndef LANGUAGE_DATA_HPP
#define LANGUAGE_DATA_HPP

#include "language.hpp"
#include "languageId.hpp"

#include <memory>
#include <unordered_map>
#include <string>

class LanguageData
{
private:
	const std::unordered_map<std::string,LanguageId> _extensionMap
	{
		{"h", LanguageId::c_header},
		
		{"c", LanguageId::c_source},
		
		{"hh", LanguageId::cpp_header},
		{"hpp", LanguageId::cpp_header},
		{"hxx", LanguageId::cpp_header},

		{"cc", LanguageId::cpp_source},
		{"cpp", LanguageId::cpp_source},
		{"cxx", LanguageId::cpp_source},
		{"c++", LanguageId::cpp_source},
		
		{"cmake", LanguageId::cmake},

		{"css", LanguageId::css},

		{"html", LanguageId::html},
		{"htm", LanguageId::html},

		{"js", LanguageId::javascript},
		{"mjs", LanguageId:: javascript},

		{"json", LanguageId::json},

		{"md", LanguageId::markdown},
		{"markdown", LanguageId::markdown},
	
		{"py", LanguageId::python}
	};
	const std::unordered_map<LanguageId,Language> _languageMap
	{
		{	LanguageId::c_header,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	LanguageId::c_source,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	LanguageId::cpp_header,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	LanguageId::cpp_source,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{	LanguageId::cmake,
			{
				{"#"},
				{},
				{{"\"","\""}}
			}
		},
		{	LanguageId::css,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{
			LanguageId::html,
			{
				{},
				{{"<!--","-->"}},
				{{"\"","\""}, {"'","'"}}
			}
		},
		{
			LanguageId::javascript,
			{
				{"//"},
				{{"/*","*/"}},
				{{"\"","\""}}
			}
		},
		{
			LanguageId::json,
			{
				{},
				{},
				{}
			}
		},
		{
			LanguageId::markdown,
			{
				{},
				{},
				{}
			}
		},
		{	LanguageId::python,
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
	LanguageId getIdentifier (std::string&& extension) const;
	std::shared_ptr<Language> getLanguage(LanguageId id) const;
};

#endif
