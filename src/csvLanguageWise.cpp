#include "csvLanguageWise.hpp"
#include "languageId.hpp"

#include <iostream>
#include <string>

void printCsvLanguageWise(const std::map<LanguageId, FileCountInfo> &data) {
  std::string s{"language,file count,code,comments,blanks,total,ratio\n"};
  for (auto &it : data) {
    s += std::string{idToString(it.first)} + ',' +
         std::to_string(it.second._fileCount) + ',' +
         std::to_string(it.second._lineInfo.code) + ',' +
         std::to_string(it.second._lineInfo.comments) + ',' +
         std::to_string(it.second._lineInfo.blanks) + ',' +
         std::to_string(it.second._lineInfo.total) + ',' +
         std::to_string(100.0 * it.second._lineInfo.total /
                        data.at(LanguageId::total)._lineInfo.total) +
         '\n';
  }
  std::cout << s;
}
