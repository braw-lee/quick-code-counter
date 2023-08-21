#ifndef LANGUAGE_ID
#define LANGUAGE_ID

#include <ostream>
#include <string_view>

enum class LanguageId
{
	c_header,
	c_source,
	cpp_header,
	cpp_source,
	cmake,
	css,
	html,
	java,
	javascript,
	json,
	markdown,
	python,
	unknown
};

constexpr std::string_view idToString(LanguageId id)
{
	switch(id)
	{
		case LanguageId::c_header : return "C_Header";
		case LanguageId::c_source : return "C_Source";
		case LanguageId::cpp_header : return "C++_Header";
		case LanguageId::cpp_source : return "C++_Source";
		case LanguageId::cmake : return "CMake";
		case LanguageId::css : return "CSS";
		case LanguageId::html : return "HTML";
		case LanguageId::java : return "Java";
		case LanguageId::javascript : return "Javascript";
		case LanguageId::json : return "JSON";
		case LanguageId::markdown : return "Markdown";
		case LanguageId::python : return "Python";
		case LanguageId::unknown : return "Unknown";
		//should never happen
		default : return "Error";
	}
}

#endif
