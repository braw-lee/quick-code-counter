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
    for (auto &path : _filePaths)
      path = fs::path(PROJECT_DIR) / path;
    _expectedAns = expectedAns;
  }
  void calculateAns() {
    for (auto &path : _filePaths) {
      _calculatedAns.push_back(_langData.getIdentifier(path));
    }
  }
};

TEST_F(GetLanguageIdTest, FileExtension) {
  set({"some/path/file.asm",
       "some/path/to/file.s",
       "some/path/file.inc",
       "some/path/to/file.wla",
       "some/path/file.SRC",

       "some/path/file.sh",

       "some/path/file.cs",
       "some/path/to/file.csx",

       "some/path/file.h",

       "some/path/file.c",

       "some/path/file.H",
       "some/path/to/file.hh",
       "some/path/file.hpp",
       "some/path/to/file.hxx",
       "some/path/file.h++",

       "some/path/file.C",
       "some/path/to/file.cc",
       "some/path/file.cpp",
       "some/path/to/file.cxx",
       "some/path/file.c++",

       "some/path/file.cmake",

       "some/path/file.css",

       "some/path/file.go",

       "some/path/file.hs",
       "some/path/to/file.lhs",

       "some/path/file.html",
       "some/path/to/file.htm",

       "some/path/file.java",

       "some/path/file.js",
       "some/path/to/file.mjs",

       "some/path/file.json",

       "some/path/file.md",
       "some/path/to/file.markdown",

       "some/path/to/file.py",

       "some/path/file.zig",
       "some/path/to/file.zir",

       "some/path/file.unknownextension",
       "some/path/to/file"},

      {LanguageId::assembly,     LanguageId::assembly,   LanguageId::assembly,
       LanguageId::assembly,     LanguageId::assembly,

       LanguageId::bourne_shell,

       LanguageId::c_sharp,      LanguageId::c_sharp,

       LanguageId::c_header,

       LanguageId::c_source,

       LanguageId::cpp_header,   LanguageId::cpp_header, LanguageId::cpp_header,
       LanguageId::cpp_header,   LanguageId::cpp_header,

       LanguageId::cpp_source,   LanguageId::cpp_source, LanguageId::cpp_source,
       LanguageId::cpp_source,   LanguageId::cpp_source,

       LanguageId::cmake,

       LanguageId::css,

       LanguageId::go,

       LanguageId::haskell,      LanguageId::haskell,

       LanguageId::html,         LanguageId::html,

       LanguageId::java,

       LanguageId::javascript,   LanguageId::javascript,

       LanguageId::json,

       LanguageId::markdown,     LanguageId::markdown,

       LanguageId::python,

       LanguageId::zig,          LanguageId::zig,

       LanguageId::unknown,      LanguageId::unknown});

  calculateAns();
  ASSERT_EQ(_calculatedAns.size(), _expectedAns.size());
  EXPECT_EQ(_calculatedAns, _expectedAns);
}

TEST_F(GetLanguageIdTest, UniqueNames) {
  set({"CMakeLists.txt", ".gitignore", ".gitattributes", ".gitmodules",
       "Makefile", "GNUmakefile", "makefile"},
      {LanguageId::cmake, LanguageId::git, LanguageId::git, LanguageId::git,
       LanguageId::make_file, LanguageId::make_file, LanguageId::make_file});
  calculateAns();
  ASSERT_EQ(_calculatedAns.size(), _expectedAns.size());
  EXPECT_EQ(_calculatedAns, _expectedAns);
}

TEST_F(GetLanguageIdTest, Shebang) {
  set({"tests/shebangTestFiles/file1", "tests/shebangTestFiles/file2",
       "tests/shebangTestFiles/file3", "tests/shebangTestFiles/file4"},
      {LanguageId::python, LanguageId::python, LanguageId::bourne_shell,
       LanguageId::bourne_shell});
  calculateAns();
  EXPECT_EQ(_calculatedAns, _expectedAns);
}
