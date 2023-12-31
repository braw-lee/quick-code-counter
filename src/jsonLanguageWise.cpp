#include "jsonLanguageWise.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

std::string
getJsonLanguageWise(const std::map<LanguageId, FileCountInfo> &data) {
  nlohmann::json j;
  for (auto &it : data) {
    j.push_back({{"Language", idToString(it.first)},
                 {"File count", it.second._fileCount},
                 {"LOC", it.second._lineInfo.code},
                 {"Comments", it.second._lineInfo.comments},
                 {"Blanks", it.second._lineInfo.blanks},
                 {"Total", it.second._lineInfo.total},
                 {"Ratio", 100.0 * it.second._lineInfo.total /
                               data.at(LanguageId::total)._lineInfo.total}});
  }
  return j.dump(4);
}
