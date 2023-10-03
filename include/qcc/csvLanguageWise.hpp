#ifndef CSV_LANGUGAGE_WISE_HPP
#define CSV_LANGUGAGE_WISE_HPP

#include "languageId.hpp"
#include "fileCountInfo.hpp"

#include <map>

void printCsvLanguageWise(const std::map<LanguageId, FileCountInfo>& data);

#endif
