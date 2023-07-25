#include "../include/qcc/machine.hpp"
#include "../include/qcc/timer.hpp"
#include "../include/qcc/language.hpp"
#include "../include/qcc/languageData.hpp"
#include "../include/qcc/fileInfo.hpp"
#include "../include/qcc/counter.hpp"

#include <fstream>
#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
	Timer t;
	Machine myMachine;
//	myMachine.run(argc, argv);
	auto data {std::make_shared<LanguageData>()};
	std::string rootDir = PROJECT_DIR;
	fs::path p {"src/main.cpp"};
	FileInfo fi{p, data};
	Counter c{&fi};
	c.count();
	fi.printLineInfo();
	std::cout<<"\n"<<t.elapsed();
}
