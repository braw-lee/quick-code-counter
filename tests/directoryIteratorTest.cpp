#include "directoryIterator.hpp"
#include "gtest/gtest.h"

#include <algorithm>
#include <filesystem>
#include <string>
#include <vector>

class DirectoryIteratorTest : public ::testing::Test {
protected:
  std::vector<fs::path> _expectedAns;
  std::vector<fs::path> _calculatedAns;
  fs::path _targetPath;
  std::vector<std::string> _ignoreThem;
  bool _includeHidden;

  void setUserInput(const fs::path &&targetPath,
                    const std::vector<std::string> &&ignoreThem,
                    const bool includeHidden) {
    _targetPath = fs::path(PROJECT_DIR) / "tests" / targetPath;
    _ignoreThem = ignoreThem;
    _includeHidden = includeHidden;
  }

  void setExpectedAns(std::vector<fs::path> &&expectedAns) {
    for (auto &path : expectedAns)
      path = fs::path(PROJECT_DIR) / "tests" / path;
    std::sort(expectedAns.begin(), expectedAns.end());
    _expectedAns = expectedAns;
  }

  void calculateAns() {
    _calculatedAns =
        directoryIterator(_targetPath, _ignoreThem, _includeHidden);
    // expectedAns can be in different order , so we sort both vectors and then
    // compare
    std::sort(_calculatedAns.begin(), _calculatedAns.end());
  }
};

TEST_F(DirectoryIteratorTest, emptyDir) {
  setUserInput("dirForTest/emptyDir", {}, true);
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, invalidPath) {
  setUserInput("dirForTest/doestExist", {}, true);
  calculateAns();
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, pathToFile) {
  setUserInput("dirForTest/file1.cpp", {}, false);
  calculateAns();
  setExpectedAns({_targetPath});
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, pathToIgnoredFile) {
  setUserInput("dirForTest/file1.cpp", {"file1.cpp"}, false);
  calculateAns();
  setExpectedAns({});
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, allFiles) {
  setUserInput("dirForTest", {}, true);
  calculateAns();
  setExpectedAns(
      {"dirForTest/file1.cpp", "dirForTest/file2.cpp", "dirForTest/.file3.cpp",
       "dirForTest/dir1/file1.cpp", "dirForTest/dir1/file2.cpp",
       "dirForTest/dir1/.file3.cpp", "dirForTest/.hiddenDir/file1.cpp",
       "dirForTest/.hiddenDir/file2.cpp", "dirForTest/.hiddenDir/.file3.cpp"});
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, ignoreHiddenFiles) {
  setUserInput("dirForTest", {}, false);
  calculateAns();
  setExpectedAns({
      "dirForTest/file1.cpp",
      "dirForTest/file2.cpp",
      "dirForTest/dir1/file1.cpp",
      "dirForTest/dir1/file2.cpp",
  });
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, ignoreSpecificFiles) {
  setUserInput("dirForTest", {"file1.cpp", "dir1"}, true);
  calculateAns();
  setExpectedAns({"dirForTest/file2.cpp", "dirForTest/.file3.cpp",
                  "dirForTest/.hiddenDir/file2.cpp",
                  "dirForTest/.hiddenDir/.file3.cpp"});
  EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, ignorePatterns) {
  setUserInput("dirForTest", {"*.cpp"}, false);
  calculateAns();
  setExpectedAns({});
  EXPECT_EQ(_expectedAns, _calculatedAns);

  setUserInput("dirForTest", {"*1.c*"}, false);
  calculateAns();
  setExpectedAns({"dirForTest/file2.cpp", "dirForTest/dir1/file2.cpp"});
  EXPECT_EQ(_expectedAns, _calculatedAns);
}
