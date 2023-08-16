#include "../include/qcc/directoryIterator.hpp"

#include <filesystem>
#include <string_view>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>

std::vector<fs::path> directoryIterator(fs::path& targetDirectory, std::vector<std::string>& ignoreThem, bool includeHidden)
{
	//return empty array if invalid path
	if(!fs::exists(targetDirectory))
	{
		//std::cerr<<"\nInvalid path\n";
		return {};
	}

	//if path is to a file, return single file path
	else if(!fs::is_directory(targetDirectory))
		return {targetDirectory};

	std::vector<fs::path> result;
	for(auto it=fs::recursive_directory_iterator(targetDirectory); it != fs::recursive_directory_iterator(); it++)
	{
		//if the flag is off, ignore the file or directory
		if(!includeHidden)
		{
			if(it->path().filename().generic_string()[0] == '.')
			{
				//ignore directory
				if(it->is_directory())
					it.disable_recursion_pending();
				//ignore file
				continue;
			}
		}
		//if found in ignoreThem, ignore the file or directory
		if(std::find(ignoreThem.begin(), ignoreThem.end(), it->path().filename()) != ignoreThem.end())
		{
			if(it->is_directory())
				it.disable_recursion_pending();
			continue;
		}
		else
		{
			if(!it->is_directory())
				result.push_back(std::move(it->path()));
		}		
	}
	//return the vector of fs::path of found files
	return result;
}
