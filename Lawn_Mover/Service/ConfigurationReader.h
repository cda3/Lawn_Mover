#pragma once
#include"ConfigurationDTO.h"
#include <nlohmann/json.hpp>
#include "Configuration.h"

using json = nlohmann::json;

class ConfigurationReader
{
public:
	Configuration prepareConfiguration(std::string configurationFilePath);

private:
	ConfigurationDTO loadConfigurationFromFile(std::string configurationFilePath);
	ManagedFolder loadConfigurationForFolder(int i, json data);
	std::vector<ManagedFolder> fillFolder(json data);
	json parseJsonFile(std::string path);
	DisposeOldResources disposerFactory(ManagedFolder folder);
	std::vector<DisposeOldResources> disposersFactory(std::vector<ManagedFolder> folders);
};

