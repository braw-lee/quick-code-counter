#ifndef QCC_JSONVERBOSE_HPP
#define QCC_JSONVERBOSE_HPP

#include "countInfo.hpp"

#include <memory>
#include <vector>

void printJsonVerbose(const std::vector<std::unique_ptr<CountInfo>> &cip);

#endif
