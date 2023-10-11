#ifndef QCC_BARCHART_HPP
#define QCC_BARCHART_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>

void generateBarChart(const std::map<LanguageId, FileCountInfo> &data);

#endif
