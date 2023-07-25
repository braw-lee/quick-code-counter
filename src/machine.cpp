#include "../include/qcc/machine.hpp"
#include "../include/qcc/directoryIterator.hpp"

#include <cxxopts.hpp>
#include <filesystem>
#include <vector>
#include <iostream>

int Machine::run(int argc, char** argv)
{
	UserInput input = parse(argc,argv);
	auto filePaths = directoryIterator(input.targetDirectory,input.ignoreThem,input.ignoreHidden);
	for(auto i : filePaths)
		std::cout<<'\n'<<i.generic_string();
	return 0;
}

UserInput Machine::parse(int argc, char** argv)
{
	cxxopts::Options options("qcc","quick-code-counter : Tool to count lines of code in a project");
	options.add_options()
		("ignore-hidden","Flag to ignore hidden files and directories",cxxopts::value<bool>()->implicit_value("true")->default_value("false"))
		("p,path","Pass path of target directory",cxxopts::value<fs::path>()->default_value("./"))
		("ignore-them","Pass comma-seperated names of file and directory names that should be ignored",cxxopts::value<std::vector<std::string>>()->default_value("{}"))
		("h,help","Print usage")
		;
	auto result = options.parse(argc,argv);

	if(result.count("help"))
	{
		std::cout<<options.help()<<"\n";
		exit(0);
	}
	
	bool ignoreHidden = result["ignore-hidden"].as<bool>();
	std::vector<std::string> ignoreThem = result["ignore-them"].as<std::vector<std::string>>();
	fs::path targetDirectory = result["path"].as<fs::path>();
	
	return {ignoreHidden,targetDirectory,ignoreThem,};
}
