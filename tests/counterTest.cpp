#include "counter.hpp"

#include <filesystem>
#include <gtest/gtest.h>
#include <memory>

class CounterTest : public ::testing::Test {
protected:
  Counter _worker;
  fs::path pathToTestsDir = fs::path(TEST_DIR);
  LineInfo _expectedAns;
  std::unique_ptr<CountInfo> _calculatedAns;
  fs::path _filePath;

  void set(fs::path &&filePath, LineInfo &&lineInfo) {
    _filePath = pathToTestsDir / filePath;
    _expectedAns = lineInfo;
  }
  void calculateAns() {
    FileInfo temp{_filePath};
    _calculatedAns = _worker.count(&temp);
  }
};

TEST_F(CounterTest, singleLineCommentTest) {
  set("sampleFiles/singleLineSample.cpp", {5, 1, 2, 8});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns.get()->_lineInfo);
}

TEST_F(CounterTest, multilineCommentTest) {
  set("sampleFiles/multilineSample.cpp", {6, 6, 3, 15});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns.get()->_lineInfo);
}

TEST_F(CounterTest, mixedCommentTest) {
  set("sampleFiles/mixedSample1.cpp", {4, 3, 0, 7});
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns.get()->_lineInfo);
}
