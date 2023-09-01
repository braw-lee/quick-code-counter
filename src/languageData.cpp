#include "../include/qcc/languageData.hpp"

#include <cctype>
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <string_view>
#include <cassert>
#include <unordered_map>

std::string getExtension(const fs::path& filePath)
{
	return filePath.has_extension() ? filePath.extension().generic_string().substr(1) : "";
}

LanguageId LanguageData::getIdentifier (const fs::path& filePath) const
{
	std::unordered_map<std::string, LanguageId>::const_iterator it;
	
	//return languageId if we identify the extension
	std::string extension = getExtension(filePath);
	if(extension != "")
	{
		it = _extensionMap.find(extension);
		if(it != _extensionMap.end())
			return it->second;
	}
	//return languageId if we identify the file name
	it = _fileNameMap.find(filePath.filename().generic_string());
	if(it != _fileNameMap.end())
		return it->second;
	//return languageId if we identify the shebang interpreter
	auto shebang = getShebang(filePath);
	if(shebang != "")
	{
		it = _shebangMap.find(shebang);
		if(it != _shebangMap.end())
			return it->second;
	}
	//return default id if the file could not be identified
	return LanguageId::unknown;
}

std::shared_ptr<CommentInfo> LanguageData::getCommentInfo(LanguageId identifier) const
{
	if(identifier == LanguageId::unknown)
		return nullptr;
	auto ans = std::make_shared<CommentInfo> (_languageMap.at(identifier));
	return ans;
}

std::string LanguageData::getShebang(const fs::path& filePath) const
{
	//get first line of the file
	auto fileHandle = std::ifstream(filePath);
	std::string firstLine;
	std::getline(fileHandle, firstLine);
	//shebang files start with "#!", return if otherwise
	if(firstLine[0] != '#' || firstLine[1] != '!')
		return "";

	size_t pathStart{2};
	size_t pathEnd{firstLine.size()};
	
	for(size_t i=2; i<firstLine.size(); i++)
		if(!std::isspace(firstLine[i]))
		{
			pathStart = i;
			break;
		}
	for(size_t i=pathStart + 1; i<firstLine.size(); i++)
		if(std::isspace(firstLine[i]))
		{
			pathEnd = i;
			break;
		}
	assert(pathStart < pathEnd);
	fs::path interpreterPath = firstLine.substr(pathStart, pathEnd - pathStart);
	if(interpreterPath.filename() == "env")
	{
		//search for interpreter name that comes after the path
		for(size_t i=pathEnd; i<firstLine.size(); i++)
			if(!std::isspace(firstLine[i]))
				return firstLine.substr(i);
	}
	else
		return interpreterPath.filename().generic_string();
	return "";
}
