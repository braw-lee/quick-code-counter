#ifndef QCC_COUNTINFO_HPP
#define QCC_COUNTINFO_HPP

#include "languageId.hpp"
#include "lineInfo.hpp"

#include <filesystem>

namespace fs = std::filesystem;

struct CountInfo {
  const fs::path &_filePath;
  LanguageId _languageIdentifier;
  LineInfo _lineInfo;

  CountInfo(const fs::path &filePath, const LanguageId language);
};

#endif
