#ifndef QCC_MACHINE_HPP
#define QCC_MACHINE_HPP

#include "userInput.hpp"

class Machine {
public:
  UserInput parse(int argc, char **argv);
  int run(int argc, char **argv);
};

#endif
