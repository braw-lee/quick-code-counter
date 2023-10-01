#include "languageWiseData.hpp"

LanguageWiseData::LanguageWiseData(const std::vector<std::unique_ptr<CountInfo>>& cip)
	:_countInfoPtrs{cip}
{
	setData();
}

void LanguageWiseData::setData()
{
	for(auto& it : _countInfoPtrs)
		insertCountInfo(it.get());
}

void LanguageWiseData::insertCountInfo(CountInfo* ci)
{
	auto it = _data.find(ci->_languageIdentifier);
	if(it != _data.end())
	{
		it->second._lineInfo += ci->_lineInfo;
		it->second._fileCount++;
		_data[LanguageId::total]._lineInfo += ci->_lineInfo;
	}
	else
	{
		FileCountInfo temp(ci);
		_data[ci->_languageIdentifier] = temp;
		_data[LanguageId::total]._lineInfo += temp._lineInfo;
	}
	++_data[LanguageId::total]._fileCount;
}

const std::map<LanguageId, FileCountInfo>& LanguageWiseData::getData()
{
	return _data;
}
