#include "../include/qcc/languageData.hpp"
#include <memory>

std::string LanguageData::getIdentifier (std::string&& extension) const
{
	if(extension == "")
		return "Unknown";
	auto it = _extensionMap.find(extension);
	if(it == _extensionMap.end())
		return "Unknown";
	else
		return it->second;
}

std::shared_ptr<Language> LanguageData::getLanguage(const std::string& identifier) const
{
	if(identifier == "Unknown")
		return nullptr;
	auto ans = std::make_shared<Language> (_languageMap.at(identifier));
	return ans;
}
