#ifndef RESULT_HPP
#define RESULT_HPP

#include "fileCountInfo.hpp"
#include "countInfo.hpp"

#include <memory>
#include <string_view>
#include <unordered_map>
#include <string>

struct Result
{
	std::unordered_map<std::string, FileCountInfo> _finalData;
	void insertCountInfo(CountInfo* ci);
	void print();
};
std::string padBoth(const std::string& s);
std::string padLeft(const std::string& s);
std::string padRight(const std::string& s);

#endif
