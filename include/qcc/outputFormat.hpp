#ifndef OUTPUT_FORMAT_HPP
#define OUTPUT_FORMAT_HPP

#include <string_view>

enum class OutputFormat
{
	table,
	json,
	csv
};

constexpr OutputFormat stringToOutput(std::string_view s) noexcept
{
	if(s == "json")
		return OutputFormat::json;
	if(s == "csv")
		return OutputFormat::csv;
	return OutputFormat::table;
}

#endif