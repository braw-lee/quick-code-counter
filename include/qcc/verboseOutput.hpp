#ifndef VERBOSE_OUTPUT
#define VERBOSE_OUTPUT

#include "countInfo.hpp"

#include <memory>
#include <vector>

void printVerboseOutput(const std::vector<std::unique_ptr<CountInfo>>& countInfoPtrs);

#endif
