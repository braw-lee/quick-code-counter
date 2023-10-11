#include "csvLanguageWise.hpp"
#include "languageWiseData.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <thread>

void generateBarChart(const std::map<LanguageId, FileCountInfo> &data) {
  std::ofstream csvFile{fs::path(PROJECT_DIR) /
                        "generatedFiles/qcc_generated_data.csv"};
  csvFile << getCsvLanguageWise(data);
  csvFile.close();
  std::string pathToPythonScript =
      fs::path(PROJECT_DIR) / "pythonScripts/generateBarChart.py";
  std::string pathToCsvFile =
      fs::path(PROJECT_DIR) / "generatedFiles/qcc_generated_data.csv";
  std::string command = "python3 " + pathToPythonScript + ' ' + pathToCsvFile;
  system(command.c_str());
}
