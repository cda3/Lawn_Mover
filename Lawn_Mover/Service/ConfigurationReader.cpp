#include "ConfigurationReader.h"
#include "../File_System/FilesReader.h"

#include <fstream>
#include<iostream>

Configuration_Prova ConfigurationReader::prepareConfiguration(std::string configurationFilePath) {
	//Configuration result;
	auto conf = loadConfigurationFromFile(configurationFilePath);
	/*result.parallelismLevel = conf.parallelismLevel;
	result.runtime = conf.runtime;
	result.disposers = disposersFactory(conf.folders);
*/
	std::shared_ptr<Cleaner2> configurations(new Cleaner2(disposersFactory(conf.folders)));
	return Configuration_Prova(configurations, conf.runtime, conf.parallelismLevel);
	//return result;
}

ConfigurationDTO ConfigurationReader::loadConfigurationFromFile(std::string configurationFilePath)
{
	ConfigurationDTO result;
	json data = parseJsonFile(configurationFilePath);
	result.runtime = data["Service_runtime"].get<int>();
	result.parallelismLevel = data["Service_parallelism_level"].get<int>();
	result.folders = fillFolder(data);
	return result;
}

ManagedFolder ConfigurationReader::loadConfigurationForFolder (int i, json data) {
	auto x = data["Managed_folders"];
	ManagedFolder folder;
	folder.daysForOldness = x[i]["Number_of_days_that_define_an_old_file"].get<int>();
	folder.enable = x[i]["Configuration_enabled"].get<bool>();
	folder.managementInstruction.insert({ "Type", x[i]["Old_file_management"]["Type"].get<std::string>() });
	folder.path = x[i]["Folder_path"].get<std::string>();
	folder.useSubfolder = x[i]["Iterative_search_into_sub_folders"].get<bool>();
	return folder;
}

std::vector<ManagedFolder> ConfigurationReader::fillFolder(json data) {
	std::vector< ManagedFolder> folders;
	for (int i = 0; i < data["Managed_folders"].size(); ++i)
		folders.push_back(loadConfigurationForFolder(i, data));
	return folders;
}

json ConfigurationReader::parseJsonFile(std::string path) {
	std::ifstream f(path);
	return json::parse(f);
}

DisposeOldResources ConfigurationReader::disposerFactory(ManagedFolder folder) {
	std::shared_ptr<FilesReader>  r(new FilesReader(folder.path));
	return DisposeOldResources(folder.daysForOldness, r);
}

std::vector<DisposeOldResources> ConfigurationReader::disposersFactory(std::vector<ManagedFolder> folders) {
	std::vector<DisposeOldResources> disposers;
	for (int i = 0; i < folders.size(); ++i) 
		disposers.push_back(disposerFactory(folders[i]));
	return disposers;
}