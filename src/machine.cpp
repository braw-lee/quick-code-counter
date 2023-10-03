#include "machine.hpp"
#include "countInfo.hpp"
#include "counter.hpp"
#include "csvLanguageWise.hpp"
#include "csvVerbose.hpp"
#include "directoryIterator.hpp"
#include "jsonLanguageWise.hpp"
#include "jsonVerbose.hpp"
#include "languageData.hpp"
#include "languageWiseData.hpp"
#include "outputFormat.hpp"
#include "tableLanguageWise.hpp"
#include "tableVerbose.hpp"
#include "userInput.hpp"
#include "utility.hpp"

#include <algorithm>
#include <cxxopts.hpp>
#include <filesystem>
#include <iostream>
#include <memory>
#include <vector>

int Machine::run(int argc, char **argv) {
  UserInput input = parse(argc, argv);
  auto filePaths = directoryIterator(input.targetDirectory, input.ignoreThem,
                                     input.includeHidden);
  std::vector<std::unique_ptr<FileInfo>> files;
  files.reserve(filePaths.size());
  std::transform(filePaths.begin(), filePaths.end(), std::back_inserter(files),
                 [](fs::path &filePath) -> std::unique_ptr<FileInfo> {
                   return std::make_unique<FileInfo>(filePath);
                 });
  std::vector<std::unique_ptr<CountInfo>> countInfoPtrs;

  Counter worker;
  for (auto &file : files) {
    auto ptr = worker.count(file.get());
    countInfoPtrs.push_back(std::move(ptr));
  }
  if (input.verbose == true) {
    if (input.out == OutputFormat::table) {
      TableVerbose output(countInfoPtrs);
      output.print();
    }
	else if (input.out == OutputFormat::json)
      printJsonVerbose(countInfoPtrs);
    else if (input.out == OutputFormat::csv)
      printCsvVerbose(countInfoPtrs);
  }
  else {
    LanguageWiseData temp(countInfoPtrs);
    if (input.out == OutputFormat::table) {
      TableLanguageWise output(temp.getData());
      output.print();
    } else if (input.out == OutputFormat::json)
      printJsonLanguageWise(temp.getData());
    else if (input.out == OutputFormat::csv)
      printCsvLanguageWise(temp.getData());
  }
  return 0;
}

UserInput Machine::parse(int argc, char **argv) {
  cxxopts::Options options(
      "qcc", "quick-code-counter : Tool to count lines of code in a project");
  options.add_options()(
      "a,all", "Do not ignore entries starting with .",
      cxxopts::value<bool>()->implicit_value("true")->default_value("false"))(
      "v,verbose", "Flag to get detailed output",
      cxxopts::value<bool>()->implicit_value("true")->default_value("false"))(
      "p,path", "Pass path of target directory",
      cxxopts::value<fs::path>()->default_value("./"))(
      "e,exclude",
      "Pass comma-seperated names of file and directory names that should be "
      "ignored",
      cxxopts::value<std::vector<std::string>>()->default_value("{}"))(
      "o,output-format",
      "Set output format\nOptions : {table, json, csv}\njson format :\ncsv "
      "format : language, file count, LOC, commnet, blanks, total, ratio\n",
      cxxopts::value<std::string>()->default_value("table"))("h,help",
                                                             "Print usage");
  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    std::cout << options.help() << "\n";
    exit(0);
  }
  bool ignoreHidden = result["all"].as<bool>();
  bool detailedOutput = result["verbose"].as<bool>();
  std::vector<std::string> ignoreThem =
      result["exclude"].as<std::vector<std::string>>();
  fs::path targetDirectory = result["path"].as<fs::path>();
  OutputFormat out = stringToOutput(result["output-format"].as<std::string>());

  return {ignoreHidden, detailedOutput, targetDirectory, ignoreThem, out};
}
