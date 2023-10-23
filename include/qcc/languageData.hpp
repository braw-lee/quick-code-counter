#ifndef QCC_LANGUAGEDATA_HPP
#define QCC_LANGUAGEDATA_HPP

#include "commentInfo.hpp"
#include "languageId.hpp"

#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace fs = std::filesystem;

class LanguageData {
public:
  LanguageId getIdentifier(const fs::path &filePath) const;
  std::shared_ptr<CommentInfo> getCommentInfo(LanguageId id) const;

private:
  CommentInfo cStyle{
      {"//"},
      {{"/*", "*/"}},
  };
  CommentInfo shellStyle{{"#"}, {}};
  CommentInfo htmlStyle{{}, {{"<!--", "-->"}}};
  CommentInfo noCommentStyle{{}, {}};
  // map file extensions to language
  const std::unordered_map<std::string, LanguageId> _extensionMap{
      {"asm", LanguageId::assembly},    {"s", LanguageId::assembly},
      {"inc", LanguageId::assembly},    {"wla", LanguageId::assembly},
      {"SRC", LanguageId::assembly},

      {"sh", LanguageId::bourne_shell},

      {"cs", LanguageId::c_sharp},      {"csx", LanguageId::c_sharp},

      {"h", LanguageId::c_header},

      {"c", LanguageId::c_source},

      {"H", LanguageId::cpp_header},    {"hh", LanguageId::cpp_header},
      {"hpp", LanguageId::cpp_header},  {"hxx", LanguageId::cpp_header},
      {"h++", LanguageId::cpp_header},

      {"C", LanguageId::cpp_source},    {"cc", LanguageId::cpp_source},
      {"cpp", LanguageId::cpp_source},  {"cxx", LanguageId::cpp_source},
      {"c++", LanguageId::cpp_source},

      {"cmake", LanguageId::cmake},

      {"css", LanguageId::css},

      {"go", LanguageId::go},

      {"hs", LanguageId::haskell},      {"lhs", LanguageId::haskell},

      {"html", LanguageId::html},       {"htm", LanguageId::html},

      {"java", LanguageId::java},

      {"js", LanguageId::javascript},   {"mjs", LanguageId::javascript},

      {"json", LanguageId::json},

      {"md", LanguageId::markdown},     {"markdown", LanguageId::markdown},

      {"py", LanguageId::python},

      {"zig", LanguageId::zig},         {"zir", LanguageId::zig}};

  // map unique file names to language
  const std::unordered_map<std::string, LanguageId> _fileNameMap{
      {"CMakeLists.txt", LanguageId::cmake},
      {".gitignore", LanguageId::git},
      {".gitattributes", LanguageId::git},
      {".gitmodules", LanguageId::git},
      {"Makefile", LanguageId::make_file},
      {"makefile", LanguageId::make_file},
      {"GNUmakefile", LanguageId::make_file}};

  // map shebangs to language
  const std::unordered_map<std::string, LanguageId> _shebangMap{
      {"sh", LanguageId::bourne_shell},
      {"bash", LanguageId::bourne_shell},
      {"python", LanguageId::python},
      {"python2", LanguageId::python},
      {"python3", LanguageId::python}};

  // map language to commentInfo
  const std::unordered_map<LanguageId, CommentInfo> _languageMap{
      {LanguageId::assembly, {{";"}, {}}},
      {LanguageId::bourne_shell, shellStyle},
      {LanguageId::c_sharp, cStyle},
      {LanguageId::c_header, cStyle},
      {LanguageId::c_source, cStyle},
      {LanguageId::cpp_header, cStyle},
      {LanguageId::cpp_source, cStyle},
      {LanguageId::cmake, {{"#"}, {{"#[[", "]]"}}}},
      {LanguageId::css, cStyle},
      {LanguageId::git, shellStyle},
      {LanguageId::go, cStyle},
      {LanguageId::haskell, {{"-- "}, {{"{-", "-}"}}}},
      {LanguageId::html, htmlStyle},
      {LanguageId::java, cStyle},
      {LanguageId::javascript, cStyle},
      {LanguageId::json, noCommentStyle},
      {LanguageId::make_file, shellStyle},
      {LanguageId::markdown, noCommentStyle},
      {LanguageId::python, {{"#"}, {{"'''", "'''"}, {R"(""")", R"(""")"}}}},
      {LanguageId::zig, {{"//"}, {}}}};

  std::string getShebang(const fs::path &filePath) const;
};

#endif
