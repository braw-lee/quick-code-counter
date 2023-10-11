#ifndef QCC_JSONVERBOSE_HPP
#define QCC_JSONVERBOSE_HPP

#include "countInfo.hpp"

#include <memory>
#include <string>
#include <vector>

std::string getJsonVerbose(const std::vector<std::unique_ptr<CountInfo>> &cip);

#endif
