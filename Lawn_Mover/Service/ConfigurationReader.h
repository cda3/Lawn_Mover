#pragma once
#include"ConfigurationDTO.h"
#include <nlohmann/json.hpp>
#include "Configuration.h"

#include <fstream>
#include<iostream>
#include<sstream>
#include<istream>
#include <memory>

using json = nlohmann::json;

class ConfigurationReader
{
public:
	Configuration prepareConfiguration(std::string configurationFilePath);

private:
	ConfigurationDTO loadConfigurationFromFile(std::string configurationFilePath);
	ManagedFolder loadConfigurationForFolder(int i, json data);
	void addFileFilter(nlohmann::json_abi_v3_11_2::json::value_type &x, ManagedFolder &folder);
	std::vector<ManagedFolder> fillFolder(json data);
	json parseJsonFile(std::string path);
	DisposeOldResources disposerFactory(ManagedFolder folder);
	std::vector<DisposeOldResources> disposersFactory(std::vector<ManagedFolder> folders);
};

