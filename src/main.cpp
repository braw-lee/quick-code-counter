#include "../include/qcc/machine.hpp"

#include <fstream>
#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
	Machine myMachine;
	myMachine.run(argc, argv);
}
