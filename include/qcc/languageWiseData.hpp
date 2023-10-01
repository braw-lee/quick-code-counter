#ifndef LWD_HPP
#define LWD_HPP

#include "countInfo.hpp"
#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <memory>
#include <vector>
#include <map>

class LanguageWiseData
{
private:
	std::map<LanguageId, FileCountInfo> _data;
	const std::vector<std::unique_ptr<CountInfo>>& _countInfoPtrs;
	
	void setData();
	void insertCountInfo(CountInfo* ci); 
public:
	LanguageWiseData(const std::vector<std::unique_ptr<CountInfo>>& cip);
	const std::map<LanguageId, FileCountInfo>& getData();
};

#endif
