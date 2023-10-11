#ifndef QCC_CSVLANGUAGEWISE_HPP
#define QCC_CSVLANGUAGEWISE_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>

std::string getCsvLanguageWise(const std::map<LanguageId, FileCountInfo> &data);

#endif
