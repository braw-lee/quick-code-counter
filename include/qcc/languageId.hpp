#ifndef QCC_LANGUAGEID_HPP
#define QCC_LANGUAGEID_HPP

#include <ostream>
#include <string_view>

enum class LanguageId
{
	bourne_shell,
	c_header,
	c_source,
	cpp_header,
	cpp_source,
	cmake,
	css,
	git,
	go,
	html,
	java,
	javascript,
	json,
	make_file,
	markdown,
	python,
	unknown,
	total
};

constexpr std::string_view idToString(LanguageId id)
{
	switch(id)
	{
		case LanguageId::bourne_shell : return "Bourne_Shell";
		case LanguageId::c_header : return "C_Header";
		case LanguageId::c_source : return "C_Source";
		case LanguageId::cpp_header : return "C++_Header";
		case LanguageId::cpp_source : return "C++_Source";
		case LanguageId::cmake : return "CMake";
		case LanguageId::css : return "CSS";
		case LanguageId::git : return "Git_File";
		case LanguageId::go : return "Go";
		case LanguageId::html : return "HTML";
		case LanguageId::java : return "Java";
		case LanguageId::javascript : return "Javascript";
		case LanguageId::json : return "JSON";
		case LanguageId::make_file : return "Makefile";
		case LanguageId::markdown : return "Markdown";
		case LanguageId::python : return "Python";
		case LanguageId::unknown : return "Unknown";
		case LanguageId::total : return "Total";
		//should never happen
		default : return "Error";
	}
}

#endif
