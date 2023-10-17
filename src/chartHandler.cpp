#include "chartHandler.hpp"
#include "csvLanguageWise.hpp"
#include "fileCountInfo.hpp"
#include "languageId.hpp"
#include <fstream>
#include <string>

void ChartHandler::generateBarChart(
    const std::map<LanguageId, FileCountInfo> &data) {
  generateCsv(data);
  std::string command = "python3 " + _barChartScript + ' ' + _csvFile;
  system(command.c_str());
}

void ChartHandler::generatePieChart(
    const std::map<LanguageId, FileCountInfo> &data) {
  generateCsv(data);
  std::string command = "python3 " + _pieChartScript + ' ' + _csvFile;
  system(command.c_str());
}

void ChartHandler::generateCsv(
    const std::map<LanguageId, FileCountInfo> &data) {
  std::ofstream csvFile{_csvFile};
  csvFile << getCsvLanguageWise(data);
  csvFile.close();
}
