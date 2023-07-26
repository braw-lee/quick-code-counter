#include "../include/qcc/languageData.hpp"
#include <memory>

std::string LanguageData::getIdentifier(std::string&& extension)
{
	if(extension == "")
		return "No extension";
	auto it = _extensionMap.find(extension);
	if(it == _extensionMap.end())
		return "Unknown";
	else
		return it->second;
}

std::shared_ptr<Language> LanguageData::getLanguage(const std::string& identifier)
{
	if(identifier == "Unknown" || identifier == "No extension")
		return nullptr;
	auto ans = std::make_shared<Language> (_languageMap.at(identifier));
	return ans;
}
