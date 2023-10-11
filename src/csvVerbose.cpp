#include "csvVerbose.hpp"

#include <iostream>
#include <string>

std::string getCsvVerbose(const std::vector<std::unique_ptr<CountInfo>> &cip) {
  std::string s{"file,language,code,comments,blanks,total\n"};
  for (auto &it : cip) {
    s += std::string{it->_filePath} + ',' +
         std::string{idToString(it->_languageIdentifier)} + ',' +
         std::to_string(it->_lineInfo.code) + ',' +
         std::to_string(it->_lineInfo.comments) + ',' +
         std::to_string(it->_lineInfo.blanks) + ',' +
         std::to_string(it->_lineInfo.total) + '\n';
  }
  return s;
}
