#include "jsonVerbose.hpp"
#include "languageId.hpp"

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

std::string getJsonVerbose(const std::vector<std::unique_ptr<CountInfo>> &cip) {
  nlohmann::json j;
  for (auto &it : cip) {
    j.push_back({{"File", it->_filePath},
                 {"Language", idToString(it->_languageIdentifier)},
                 {"LOC", it->_lineInfo.code},
                 {"Comments", it->_lineInfo.comments},
                 {"Blanks", it->_lineInfo.blanks},
                 {"Total", it->_lineInfo.total}});
  }
  return j.dump(4);
}
