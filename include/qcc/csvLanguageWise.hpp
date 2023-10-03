#ifndef QCC_CSVLANGUAGEWISE_HPP
#define QCC_CSVLANGUAGEWISE_HPP

#include "languageId.hpp"
#include "fileCountInfo.hpp"

#include <map>

void printCsvLanguageWise(const std::map<LanguageId, FileCountInfo>& data);

#endif
