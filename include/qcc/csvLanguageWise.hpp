#ifndef QCC_CSVLANGUAGEWISE_HPP
#define QCC_CSVLANGUAGEWISE_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>

void printCsvLanguageWise(const std::map<LanguageId, FileCountInfo> &data);

#endif
