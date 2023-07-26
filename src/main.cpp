#include "../include/qcc/machine.hpp"
#include "../include/qcc/timer.hpp"
#include "../include/qcc/language.hpp"
#include "../include/qcc/languageData.hpp"
#include "../include/qcc/fileInfo.hpp"
#include "../include/qcc/counter.hpp"

#include <fstream>
#include <iostream>
#include <memory>

void print(LineInfo li)
{
	std::cout<<"\nBlanks : "<<li.blanks;
	std::cout<<"\nComments : "<<li.comments;
	std::cout<<"\nCode : "<<li.code;
	std::cout<<"\nTotal : "<<li.total;
}

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
	auto ans = c.count();
	print(ans->_lineInfo);
	std::cout<<"\n"<<t.elapsed();
}
