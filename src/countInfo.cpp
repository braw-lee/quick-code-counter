#include "../include/qcc/countInfo.hpp"

#include <memory>
#include <string>

CountInfo::CountInfo(fs::path filePath, LanguageId id)
	:_filePath{filePath},_languageIdentifier{id}
{
}
