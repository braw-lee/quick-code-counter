#include "../include/qcc/languageData.hpp"
#include <memory>

std::shared_ptr<Language> LanguageData::getLanguage(std::string&& extension)
{
	if(extension == "" || _extensionMap.count(extension) == 0)
		return nullptr;
	auto ans = std::make_shared<Language> (_languageMap.at(_extensionMap.at(extension)));
	return ans;
}
