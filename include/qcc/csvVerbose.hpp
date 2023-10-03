#ifndef CSV_VERBOSE_HPP
#define CSV_VERBOSE_HPP

#include "countInfo.hpp"

#include <vector>
#include <memory>

void printCsvVerbose(const std::vector<std::unique_ptr<CountInfo>>& cip);

#endif
