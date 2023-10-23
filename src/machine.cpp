#include "machine.hpp"
#include "chartHandler.hpp"
#include "countInfo.hpp"
#include "counter.hpp"
#include "csvLanguageWise.hpp"
#include "csvVerbose.hpp"
#include "directoryIterator.hpp"
#include "jsonLanguageWise.hpp"
#include "jsonVerbose.hpp"
#include "languageData.hpp"
#include "languageId.hpp"
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
  // parse user input
  UserInput input = parse(argc, argv);
  // get all file paths recursively
  auto filePaths = directoryIterator(input.targetDirectory, input.ignoreThem,
                                     input.includeHidden);
  // make FileInfo objects of all file paths
  std::vector<std::unique_ptr<FileInfo>> files;
  files.reserve(filePaths.size());
  std::transform(filePaths.begin(), filePaths.end(), std::back_inserter(files),
                 [](fs::path &filePath) -> std::unique_ptr<FileInfo> {
                   return std::make_unique<FileInfo>(filePath);
                 });
  std::vector<std::unique_ptr<CountInfo>> countInfoPtrs;
  Counter worker;
  for (auto &file : files) {
    // process the file using a `Counter` object if LanguageId::unknown files
    // are to be processed OR LanguageId is not LanguageId::unknown
    if (input.includeUnknown == true ||
        file->_languageIdentifier != LanguageId::unknown) {
      countInfoPtrs.push_back(std::move(worker.count(file.get())));
    }
  }
  // generate output based on choice passed by user
  generateOutput(input.outputFormat, countInfoPtrs);
  return 0;
}

UserInput Machine::parse(int argc, char **argv) {
  cxxopts::Options options(
      "qcc", "quick-code-counter : Tool to count lines of code in a project");
  options.add_options()(
      "a,all", "Do not ignore entries starting with .",
      cxxopts::value<bool>()->implicit_value("true")->default_value("false"))(
      "u,unknown", "Do not ignore files whose language couldn't be recognized",
      cxxopts::value<bool>()->implicit_value("true")->default_value("false"))(
      "p,path", "Pass path of target directory",
      cxxopts::value<fs::path>()->default_value("./"))(
      "e,exclude",
      "Pass comma-seperated names of file and directory names that should "
      "be "
      "ignored",
      cxxopts::value<std::vector<std::string>>()->default_value("{}"))(
      "o,output-format",
      "Set output format\nOptions : \n{table, vtable, "
      "json, vjson, csv, vcsv, "
      "bar, pie}\nOptions prefixed with `v` produces verbose output, i.e file "
      "by file",
      cxxopts::value<std::string>()->default_value("table"))("h,help",
                                                             "Print usage");
  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    std::cout << options.help() << "\n";
    exit(0);
  }
  bool ignoreHidden = result["all"].as<bool>();
  bool ignoreUnknown = result["unknown"].as<bool>();
  std::vector<std::string> ignoreThem =
      result["exclude"].as<std::vector<std::string>>();
  fs::path targetDirectory = result["path"].as<fs::path>();
  OutputFormat outFormat =
      stringToOutput(result["output-format"].as<std::string>());

  return {ignoreHidden, ignoreUnknown, targetDirectory, ignoreThem, outFormat};
}

void Machine::generateOutput(
    OutputFormat of, std::vector<std::unique_ptr<CountInfo>> &countInfoPtrs) {
  // use switch case to choose the correct output format
  switch (of) {
  case OutputFormat::vtable: {
    TableVerbose output{countInfoPtrs};
    output.print();
    break;
  }
  case OutputFormat::vjson: {
    std::cout << getJsonVerbose(countInfoPtrs);
    break;
  }
  case OutputFormat::vcsv: {
    std::cout << getCsvVerbose(countInfoPtrs);
    break;
  }
  default: {
    // will need language-wise-data if output format is non verbose
    LanguageWiseData languageWiseData{countInfoPtrs};
    switch (of) {
    case OutputFormat::table: {
      TableLanguageWise output(languageWiseData.getData());
      output.print();
      break;
    }
    case OutputFormat::json: {
      std::cout << getJsonLanguageWise(languageWiseData.getData());
      break;
    }
    case OutputFormat::csv: {
      std::cout << getCsvLanguageWise(languageWiseData.getData());
      break;
    }
    case OutputFormat::bar: {
      ChartHandler::generateBarChart(languageWiseData.getData());
      break;
    }
    case OutputFormat::pie: {
      ChartHandler::generatePieChart(languageWiseData.getData());
      break;
    }
    default:
      std::cerr << "Should never execute";
      break;
    }
    break;
  }
  }
}
