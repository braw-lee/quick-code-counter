#ifndef JSON_VERBOSE_HPP
#define JSON_VERBOSE_HPP

#include "countInfo.hpp"

#include <memory>
#include <vector>

void printJsonVerbose(const std::vector<std::unique_ptr<CountInfo>>& cip);

#endif
