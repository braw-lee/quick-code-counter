#include "../include/qcc/languageData.hpp"

#include <filesystem>
#include <memory>
#include <string>
#include <string_view>

std::string getExtension(const fs::path& filePath)
{
	return filePath.has_extension() ? filePath.extension().generic_string().substr(1) : "";
}

LanguageId LanguageData::getIdentifier (const fs::path& filePath) const
{
	std::string extension = getExtension(filePath);
	auto it = _extensionMap.find(extension);
	if(it != _extensionMap.end())
		return it->second;
	it = _fileNameMap.find(filePath.filename().generic_string());
	if(it != _fileNameMap.end())
		return it->second;
	return LanguageId::unknown;
}

std::shared_ptr<CommentInfo> LanguageData::getCommentInfo(LanguageId identifier) const
{
	if(identifier == LanguageId::unknown)
		return nullptr;
	auto ans = std::make_shared<CommentInfo> (_languageMap.at(identifier));
	return ans;
}
