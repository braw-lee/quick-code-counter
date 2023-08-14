#include "../include/qcc/countInfo.hpp"

#include <memory>
#include <string>

CountInfo::CountInfo(fs::path filePath, std::string languageIdentifier)
	:_filePath{filePath},_languageIdentifier{languageIdentifier}
{
}
