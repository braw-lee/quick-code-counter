#ifndef RESULT_HPP
#define RESULT_HPP

#include "fileCountInfo.hpp"
#include "countInfo.hpp"
#include "languageId.hpp"

#include <memory>
#include <string_view>
#include <unordered_map>
#include <string>

struct Result
{
	std::unordered_map<LanguageId, FileCountInfo> _finalData;
	void insertCountInfo(CountInfo* ci);
	void print();
};

#endif
