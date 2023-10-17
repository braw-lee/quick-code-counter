#ifndef QCC_CHARTHANDLER_HPP
#define QCC_CHARTHANDLER_HPP

#include "fileCountInfo.hpp"
#include "languageId.hpp"
#include "gtest/gtest.h"
#include <filesystem>
#include <map>

class ChartHandler {
public:
  static void generatePieChart(const std::map<LanguageId, FileCountInfo> &data);
  static void generateBarChart(const std::map<LanguageId, FileCountInfo> &data);

private:
  static inline const std::string _barChartScript =
      fs::path(PROJECT_DIR) / "pythonScripts/generateBarChart.py";
  static inline std::string _pieChartScript =
      fs::path(PROJECT_DIR) / "pythonScripts/generatePieChart.py";
  static inline std::string _csvFile =
      fs::path(PROJECT_DIR) / "generatedFiles/qcc_generated_data.csv";

  static void generateCsv(const std::map<LanguageId, FileCountInfo> &data);
};

#endif
