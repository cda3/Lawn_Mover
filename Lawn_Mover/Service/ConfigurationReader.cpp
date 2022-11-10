#include "ConfigurationReader.h"

#include <fstream>
#include<iostream>

#include <nlohmann/json.hpp>

Configuration ConfigurationReader::loadConfiguration(std::string configurationFilePath)
{
	Configuration result;
	using json = nlohmann::json;
	std::ifstream f(configurationFilePath);
	json data = json::parse(f);

	result.runtime = data["Service_runtime"].get<int>();
	result.parallelismLevel = data["Service_parallelism_level"].get<int>();

	auto x = data["Managed_folders"];
	std::vector< ManagedFolder> folders;
	for (int i = 0; i < x.size(); ++i) {
		ManagedFolder folder;
		folder.daysForOldness = x[i]["Number_of_days_that_define_an_old_file"].get<int>();
		folder.enable = x[i]["Configuration_enabled"].get<bool>();
		//auto s = x[i]["Old_file_management"]["Type"].get<std::string>();
		folder.managementInstruction.insert({ "Type", x[i]["Old_file_management"]["Type"].get<std::string>() });
		folder.path = x[i]["Folder_path"].get<std::string>();
		folder.useSubfolder = x[i]["Iterative_search_into_sub_folders"].get<bool>();
		folders.push_back(folder);
	}

	result.folders = folders;
	/*auto c = data["Service_runtime"].get<int>();
	auto s = data["prova"];
	auto in = data["Managed_folders"][0]["Folder_path"].get<std::string>();
	auto in2 = data["Managed_folders"];*/

	return result;
}
