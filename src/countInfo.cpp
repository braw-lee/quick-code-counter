#include "countInfo.hpp"

CountInfo::CountInfo(const fs::path &filePath, const LanguageId id)
    : _filePath{filePath}, _languageIdentifier{id} {}
