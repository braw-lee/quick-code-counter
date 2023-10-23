#ifndef QCC_LANGUAGEID_HPP
#define QCC_LANGUAGEID_HPP

#include <ostream>
#include <string_view>

enum class LanguageId {
  assembly,
  bourne_shell,
  c_sharp,
  c_header,
  c_source,
  cpp_header,
  cpp_source,
  cmake,
  css,
  git,
  go,
  haskell,
  html,
  java,
  javascript,
  json,
  make_file,
  markdown,
  python,
  zig, // 20 languages
  unknown,
  total
};

constexpr std::string_view idToString(LanguageId id) {
  switch (id) {
  case LanguageId::assembly:
    return "Assembly";
  case LanguageId::bourne_shell:
    return "Bourne_Shell";
  case LanguageId::c_sharp:
    return "C#";
  case LanguageId::c_header:
    return "C_Header";
  case LanguageId::c_source:
    return "C_Source";
  case LanguageId::cpp_header:
    return "C++_Header";
  case LanguageId::cpp_source:
    return "C++_Source";
  case LanguageId::cmake:
    return "CMake";
  case LanguageId::css:
    return "CSS";
  case LanguageId::git:
    return "Git_File";
  case LanguageId::go:
    return "Go";
  case LanguageId::haskell:
    return "Haskell";
  case LanguageId::html:
    return "HTML";
  case LanguageId::java:
    return "Java";
  case LanguageId::javascript:
    return "Javascript";
  case LanguageId::json:
    return "JSON";
  case LanguageId::make_file:
    return "Makefile";
  case LanguageId::markdown:
    return "Markdown";
  case LanguageId::python:
    return "Python";
  case LanguageId::zig:
    return "Zig";
  case LanguageId::unknown:
    return "Unknown";
  case LanguageId::total:
    return "Total";
  // should never happen
  default:
    return "Error";
  }
}

#endif
