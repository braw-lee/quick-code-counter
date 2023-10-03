#ifndef QCC_CSVVERBOSE_HPP
#define QCC_CSVVERBOSE_HPP

#include "countInfo.hpp"

#include <memory>
#include <vector>

void printCsvVerbose(const std::vector<std::unique_ptr<CountInfo>>& cip);

#endif
