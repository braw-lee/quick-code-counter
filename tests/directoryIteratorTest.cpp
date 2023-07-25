#include "../include/qcc/directoryIterator.hpp"

#include <algorithm>
#include <filesystem>
#include <gtest/gtest.h>
#include <string>
#include <vector>

class DirectoryIteratorTest : public::testing::Test
{
protected:
	std::string  pathToTestsDir = TEST_DIR;
	std::vector<fs::path> _expectedAns;
	std::vector<fs::path> _calculatedAns;
	fs::path _targetPath;
	std::vector<std::string> _ignoreThem;
	bool _ignoreHidden;
	
	void set(const fs::path&& targetPath, const std::vector<std::string>&& ignoreThem, const bool ignoreHidden)
	{
		_targetPath = targetPath;
		_ignoreThem = ignoreThem;
		_ignoreHidden = ignoreHidden;
	}

	void calculateAns()
	{
		_calculatedAns = directoryIterator(_targetPath, _ignoreThem, _ignoreHidden);
		//expectedAns can be in different order , so we sort both vectors and then compare
		std::sort(_calculatedAns.begin(), _calculatedAns.end());
	}
};

TEST_F(DirectoryIteratorTest, emptyDir)
{
	set(pathToTestsDir + "dirForTest/emptyDir",{},true);
	calculateAns();
	EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, invalidPath)
{
	set(pathToTestsDir + "dirForTest/doestExist",{},true);
	calculateAns();
	EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, pathToFile)
{
	set(pathToTestsDir + "dirForTest/file1.cpp", {}, false);
	calculateAns();
	_expectedAns = {_targetPath};
	EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, allFiles)
{
	set(pathToTestsDir + "dirForTest",{},false);
	calculateAns();
	_expectedAns = {
		pathToTestsDir + "dirForTest/file1.cpp",
		pathToTestsDir + "dirForTest/file2.cpp",
		pathToTestsDir + "dirForTest/.file3.cpp",
		pathToTestsDir + "dirForTest/dir1/file1.cpp",
		pathToTestsDir + "dirForTest/dir1/file2.cpp",
		pathToTestsDir + "dirForTest/dir1/.file3.cpp",
		pathToTestsDir + "dirForTest/.hiddenDir/file1.cpp",
		pathToTestsDir + "dirForTest/.hiddenDir/file2.cpp",
		pathToTestsDir + "dirForTest/.hiddenDir/.file3.cpp"
	};
	std::sort(_expectedAns.begin(), _expectedAns.end());
	EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, ignoreHiddenFiles)
{
	set(pathToTestsDir + "dirForTest",{},true);
	calculateAns();
	_expectedAns = {
		pathToTestsDir + "dirForTest/file1.cpp",
		pathToTestsDir + "dirForTest/file2.cpp",
		pathToTestsDir + "dirForTest/dir1/file1.cpp",
		pathToTestsDir + "dirForTest/dir1/file2.cpp",
	};
	std::sort(_expectedAns.begin(), _expectedAns.end());
	EXPECT_EQ(_expectedAns, _calculatedAns);
}

TEST_F(DirectoryIteratorTest, ignoreSpecificFiles)
{
	set(pathToTestsDir + "dirForTest",{"file1.cpp","dir1"},false);
	calculateAns();
	_expectedAns = {
		pathToTestsDir + "dirForTest/file2.cpp",
		pathToTestsDir + "dirForTest/.file3.cpp",
		pathToTestsDir + "dirForTest/.hiddenDir/file2.cpp",
		pathToTestsDir + "dirForTest/.hiddenDir/.file3.cpp"
	};
	std::sort(_expectedAns.begin(), _expectedAns.end());
	EXPECT_EQ(_expectedAns, _calculatedAns);
}
