#include "ConfigurationReader.h"
#include "../File_System/FilesReader.h"

#include <fstream>
#include<iostream>
#include<sstream>
#include<istream>
#include <memory>

Configuration ConfigurationReader::prepareConfiguration(std::string configurationFilePath) {
	auto conf = loadConfigurationFromFile(configurationFilePath);
	std::shared_ptr<Cleaner> configurations(new Cleaner(disposersFactory(conf.folders)));
	return Configuration(configurations, conf.runtime, conf.parallelismLevel);
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
	auto x = data["Managed_folders"][i];
	ManagedFolder folder;
	folder.daysForOldness = x["Number_of_days_that_define_an_old_file"].get<int>();
	folder.enable = x["Configuration_enabled"].get<bool>();
	auto fileManagement = x["Old_file_management"];
	folder.managementInstruction.insert({ "Type", fileManagement["Type"].get<std::string>() });
	if (fileManagement["Type"].get<std::string>() == "HistoryWithFolder")
		folder.managementInstruction.insert({ "History_folder", fileManagement["History_folder"].get<std::string>() });
	folder.path = x["Folder_path"].get<std::string>();
	folder.useSubfolder = x["Iterative_search_into_sub_folders"].get<bool>();
	addFileFilter(x, folder);
	return folder;
}

void ConfigurationReader::addFileFilter(json::value_type &x, ManagedFolder &folder)
{
	auto y = x["File_Filter"];
	if (!(y.is_null()) && !(y.empty()))
		folder.fileFilter = y.get<std::string>();
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
	std::shared_ptr<FilesReader>  r(new FilesReader(folder.path, folder.fileFilter));
	return DisposeOldResources(folder.daysForOldness, r);
}

std::vector<DisposeOldResources> ConfigurationReader::disposersFactory(std::vector<ManagedFolder> folders) {
	std::vector<DisposeOldResources> disposers;
	for (int i = 0; i < folders.size(); ++i)
		if (folders[i].enable) 
			disposers.push_back(disposerFactory(folders[i]));
	return disposers;
}