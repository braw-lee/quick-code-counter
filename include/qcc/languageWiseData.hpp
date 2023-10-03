#ifndef QCC_LANGUAGEWISEDATA_HPP
#define QCC_LANGUAGEWISEDATA_HPP

#include "countInfo.hpp"
#include "fileCountInfo.hpp"
#include "languageId.hpp"

#include <map>
#include <memory>
#include <vector>

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
