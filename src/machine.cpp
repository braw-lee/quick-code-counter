#include "../include/qcc/machine.hpp"
#include "../include/qcc/directoryIterator.hpp"
#include "../include/qcc/countInfo.hpp"
#include "../include/qcc/counter.hpp"
#include "../include/qcc/languageData.hpp"
#include "../include/qcc/result.hpp"
#include "../include/qcc/verboseOutput.hpp"

#include <algorithm>
#include <cxxopts.hpp>
#include <filesystem>
#include <memory>
#include <vector>
#include <iostream>

int Machine::run(int argc, char** argv)
{
	UserInput input = parse(argc,argv);
	auto filePaths = directoryIterator(input.targetDirectory,input.ignoreThem,input.includeHidden);
	std::vector<std::unique_ptr<FileInfo>> files;
	LanguageData languageData;
	std::transform(filePaths.begin(), filePaths.end(), std::back_inserter(files), [languageData](fs::path& filePath)->std::unique_ptr<FileInfo>
			{
				auto file {std::make_unique<FileInfo>(filePath, languageData)};
				return file;
			});
	std::vector<std::unique_ptr<CountInfo>> countInfoPtrs;
	
	Counter worker;
	for(auto& file : files)
	{
		auto ptr = worker.count(std::move(file));
		countInfoPtrs.push_back(std::move(ptr));
	}
	if(input.verbose == true)
	{
		printVerboseOutput(countInfoPtrs);
		return 0;
	}
	else
	{
		Result res;
		for(auto& it : countInfoPtrs)
			res.insertCountInfo(it.get());
		res.print();
		return 0;
	}
}

UserInput Machine::parse(int argc, char** argv)
{
	cxxopts::Options options("qcc","quick-code-counter : Tool to count lines of code in a project");
	options.add_options()
		("a,all","Do not ignore entries starting with .",cxxopts::value<bool>()->implicit_value("true")->default_value("false"))
		("v,verbose","Flag to get detailed output", cxxopts::value<bool>()->implicit_value("true") ->default_value("false"))
		("p,path","Pass path of target directory",cxxopts::value<fs::path>()->default_value("./"))
		("e,exclude","Pass comma-seperated names of file and directory names that should be ignored",cxxopts::value<std::vector<std::string>>()->default_value("{}"))
		("h,help","Print usage")
		;
	auto result = options.parse(argc,argv);

	if(result.count("help"))
	{
		std::cout<<options.help()<<"\n";
		exit(0);
	}

	bool ignoreHidden = result["all"].as<bool>();
	bool detailedOutput = result["verbose"].as<bool>();
	std::vector<std::string> ignoreThem = result["exclude"].as<std::vector<std::string>>();
	fs::path targetDirectory = result["path"].as<fs::path>();
	
	return {ignoreHidden, detailedOutput, targetDirectory, ignoreThem,};
}
