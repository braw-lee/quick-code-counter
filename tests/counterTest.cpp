#include "counter.hpp"
#include "lineInfo.hpp"
#include "gtest/gtest.h"

#include <algorithm>
#include <filesystem>
#include <memory>
#include <pstl/glue_execution_defs.h>
#include <vector>

class CounterTest : public ::testing::Test {
protected:
  Counter _worker;
  std::vector<fs::path> _filePaths;
  std::vector<LineInfo> _expectedAns;
  std::vector<LineInfo> _calculatedAns;

  void set(std::vector<fs::path> &&filePaths,
           std::vector<LineInfo> &&expectedAns) {
    std::for_each(filePaths.begin(), filePaths.end(), [](fs::path &p) -> void {
      p = fs::path(PROJECT_DIR) / "tests" / p;
    });
    _filePaths = filePaths;
    _expectedAns = expectedAns;
  }
  void calculateAns() {
    std::vector<std::unique_ptr<FileInfo>> files;
    std::transform(_filePaths.begin(), _filePaths.end(),
                   std::back_inserter(files),
                   [](fs::path &filePath) -> std::unique_ptr<FileInfo> {
                     return std::make_unique<FileInfo>(filePath);
                   });
    for (auto &file : files) {
      auto countInfo = _worker.count(file.get());
      _calculatedAns.push_back(countInfo->_lineInfo);
    }
  }
};

TEST_F(CounterTest, singleLineCommentTest) {
  set({"sampleFiles/singleLineSample.cpp"}, {{5, 1, 2, 8}});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(CounterTest, multilineCommentTest) {
  set({"sampleFiles/multilineSample.cpp"}, {{6, 6, 3, 15}});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(CounterTest, mixedCommentTest) {
  set({"sampleFiles/mixedSample1.cpp"}, {{4, 3, 0, 7}});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns);
}
