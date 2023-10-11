#ifndef QCC_JSONLANGUAGEWISE_HPP
#define QCC_JSONLANGUAGEWISE_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>
#include <string>

std::string
getJsonLanguageWise(const std::map<LanguageId, FileCountInfo> &data);

#endif
