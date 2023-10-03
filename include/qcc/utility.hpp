#ifndef QCC_UTILITY_HPP
#define QCC_UTILITY_HPP

#include "languageWiseData.hpp"

#include <string>
#include <string_view>

struct StringPair
{
	std::string start;
	std::string end;
};

enum class LanguageWiseCellName
{
	language,
	fileCount,
	code,
	comment,
	blank,
	total,
	ratio,
	column_size
};

enum class VerboseCellName
{
	file,
	language,
	code,
	comment,
	blank,
	total,
	column_size
};

//ease of conversion of scoped enum to intergers
constexpr auto operator+(LanguageWiseCellName a) noexcept
{
    return static_cast<std::underlying_type_t<LanguageWiseCellName>>(a);
}

constexpr auto operator+(VerboseCellName a) noexcept
{
    return static_cast<std::underlying_type_t<VerboseCellName>>(a);
}
#endif
