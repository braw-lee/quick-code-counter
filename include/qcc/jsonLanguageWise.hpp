#ifndef QCC_JSONLANGUAGEWISE_HPP
#define QCC_JSONLANGUAGEWISE_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>

void printJsonLanguageWise(const std::map<LanguageId, FileCountInfo>& data);

#endif
