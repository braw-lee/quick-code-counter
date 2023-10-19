#ifndef QCC_MACHINE_HPP
#define QCC_MACHINE_HPP

#include "countInfo.hpp"
#include "outputFormat.hpp"
#include "userInput.hpp"
#include <memory>
#include <vector>

class Machine {
public:
  int run(int argc, char **argv);

private:
  UserInput parse(int argc, char **argv);
  void generateOutput(OutputFormat of,
                      std::vector<std::unique_ptr<CountInfo>> &countInfoPtrs);
};

#endif
