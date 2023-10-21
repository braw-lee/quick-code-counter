#include "languageData.hpp"
#include "languageId.hpp"
#include "gtest/gtest.h"

#include <filesystem>
#include <vector>

class GetLanguageIdTest : public ::testing::Test {
protected:
  LanguageData _langData;
  std::vector<fs::path> _filePaths;
  std::vector<LanguageId> _expectedAns;
  std::vector<LanguageId> _calculatedAns;

  void set(std::vector<fs::path> &&filePaths,
           std::vector<LanguageId> &&expectedAns) {
    _filePaths = filePaths;
    _expectedAns = expectedAns;
  }
  void calculateAns() {
    for (auto &path : _filePaths) {
      _calculatedAns.push_back(_langData.getIdentifier(path));
    }
  }
};

TEST_F(GetLanguageIdTest, FileExtension) {
  set({"file.sh",       "file.h",   "file.c",   "file.hh",   "file.hpp",
       "file.hxx",      "file.cc",  "file.cpp", "file.cxx",  "file.c++",
       "file.cmake",    "file.css", "file.go",  "file.html", "file.htm",
       "file.java",     "file.js",  "file.mjs", "file.json", "file.md",
       "file.markdown", "file.py"},

      {LanguageId::bourne_shell, LanguageId::c_header,   LanguageId::c_source,
       LanguageId::cpp_header,   LanguageId::cpp_header, LanguageId::cpp_header,
       LanguageId::cpp_source,   LanguageId::cpp_source, LanguageId::cpp_source,
       LanguageId::cpp_source,   LanguageId::cmake,      LanguageId::css,
       LanguageId::go,           LanguageId::html,       LanguageId::html,
       LanguageId::java,         LanguageId::javascript, LanguageId::javascript,
       LanguageId::json,         LanguageId::markdown,   LanguageId::markdown,
       LanguageId::python});
  calculateAns();
  EXPECT_EQ(_calculatedAns, _expectedAns);
}

TEST_F(GetLanguageIdTest, UniqueNames) {
  set({"CMakeLists.txt", ".gitignore", ".gitattributes", ".gitmodules",
       "Makefile", "GNUmakefile", "makefile"},
      {LanguageId::cmake, LanguageId::git, LanguageId::git, LanguageId::git,
       LanguageId::make_file, LanguageId::make_file, LanguageId::make_file});
  calculateAns();
  EXPECT_EQ(_calculatedAns, _expectedAns);
}
