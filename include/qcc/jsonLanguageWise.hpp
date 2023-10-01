#ifndef JLW_HPP
#define JLW_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>

void printJsonLanguageWise(const std::map<LanguageId, FileCountInfo>& data);

#endif
