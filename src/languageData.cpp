#include "../include/qcc/languageData.hpp"

#include <memory>

LanguageId LanguageData::getIdentifier (std::string&& extension) const
{
	if(extension == "")
		return LanguageId::unknown;
	auto it = _extensionMap.find(extension);
	if(it == _extensionMap.end())
		return LanguageId::unknown;
	else
		return it->second;
}

std::shared_ptr<Language> LanguageData::getLanguage(LanguageId identifier) const
{
	if(identifier == LanguageId::unknown)
		return nullptr;
	auto ans = std::make_shared<Language> (_languageMap.at(identifier));
	return ans;
}
