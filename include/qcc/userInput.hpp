#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

struct UserInput
{
	bool includeHidden;
	bool verbose;
	fs::path targetDirectory;
	std::vector<std::string> ignoreThem;
};

#endif
