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
private:
  CommentInfo cStyle{
      {"//"},
      {{"/*", "*/"}},
  };
  CommentInfo shellStyle{{"#"}, {}};
  CommentInfo htmlStyle{{}, {{"<!--", "-->"}}};
  CommentInfo noCommentStyle{{}, {}};
  const std::unordered_map<std::string, LanguageId> _extensionMap{
      {"sh", LanguageId::bourne_shell},

      {"h", LanguageId::c_header},

      {"c", LanguageId::c_source},

      {"hh", LanguageId::cpp_header},   {"hpp", LanguageId::cpp_header},
      {"hxx", LanguageId::cpp_header},

      {"cc", LanguageId::cpp_source},   {"cpp", LanguageId::cpp_source},
      {"cxx", LanguageId::cpp_source},  {"c++", LanguageId::cpp_source},

      {"cmake", LanguageId::cmake},

      {"css", LanguageId::css},

      {"go", LanguageId::go},

      {"html", LanguageId::html},       {"htm", LanguageId::html},

      {"java", LanguageId::java},

      {"js", LanguageId::javascript},   {"mjs", LanguageId::javascript},

      {"json", LanguageId::json},

      {"md", LanguageId::markdown},     {"markdown", LanguageId::markdown},

      {"py", LanguageId::python}};

  const std::unordered_map<std::string, LanguageId> _fileNameMap{
      {"CMakeLists.txt", LanguageId::cmake},
      {".gitignore", LanguageId::git},
      {".gitattributes", LanguageId::git},
      {".gitmodules", LanguageId::git},
      {"Makefile", LanguageId::make_file}};

  const std::unordered_map<std::string, LanguageId> _shebangMap{
      {"sh", LanguageId::bourne_shell},
      {"bash", LanguageId::bourne_shell},
      {"python", LanguageId::python},
      {"python2", LanguageId::python},
      {"python3", LanguageId::python}};

  const std::unordered_map<LanguageId, CommentInfo> _languageMap{
      {LanguageId::bourne_shell, shellStyle},
      {LanguageId::c_header, cStyle},
      {LanguageId::c_source, cStyle},
      {LanguageId::cpp_header, cStyle},
      {LanguageId::cpp_source, cStyle},
      {LanguageId::cmake, {{"#"}, {{"#[[", "]]"}}}},
      {LanguageId::css, cStyle},
      {LanguageId::git, shellStyle},
      {LanguageId::go, cStyle},
      {LanguageId::html, htmlStyle},
      {LanguageId::java, cStyle},
      {LanguageId::javascript, cStyle},
      {LanguageId::json, noCommentStyle},
      {LanguageId::make_file, shellStyle},
      {LanguageId::markdown, noCommentStyle},
      {LanguageId::python, {{"#"}, {{"'''", "'''"}, {R"(""")", R"(""")"}}}}};

public:
  LanguageId getIdentifier(const fs::path &filePath) const;
  std::shared_ptr<CommentInfo> getCommentInfo(LanguageId id) const;
  std::string getShebang(const fs::path &filePath) const;
};

#endif
