#ifndef QCC_OUTPUTFORMAT_HPP
#define QCC_OUTPUTFORMAT_HPP

#include <string_view>

enum class OutputFormat { table, json, csv, bar, pie };

constexpr OutputFormat stringToOutput(std::string_view s) noexcept {
  if (s == "json")
    return OutputFormat::json;
  if (s == "csv")
    return OutputFormat::csv;
  if (s == "bar")
    return OutputFormat::bar;
  if (s == "pie")
    return OutputFormat::pie;
  return OutputFormat::table;
}

#endif
