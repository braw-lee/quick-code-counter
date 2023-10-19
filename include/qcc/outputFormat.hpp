#ifndef QCC_OUTPUTFORMAT_HPP
#define QCC_OUTPUTFORMAT_HPP

#include <string_view>

enum class OutputFormat { table, vtable, json, vjson, csv, vcsv, bar, pie };

constexpr OutputFormat stringToOutput(std::string_view s) noexcept {
  if (s == "vtable")
    return OutputFormat::vtable;
  if (s == "json")
    return OutputFormat::json;
  if (s == "vjson")
    return OutputFormat::vjson;
  if (s == "csv")
    return OutputFormat::csv;
  if (s == "vcsv")
    return OutputFormat::vcsv;
  if (s == "bar")
    return OutputFormat::bar;
  if (s == "pie")
    return OutputFormat::pie;
  // default OutputFormat is OutputFormat::table
  return OutputFormat::table;
}

#endif
