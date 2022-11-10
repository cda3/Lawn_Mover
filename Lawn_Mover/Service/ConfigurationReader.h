#pragma once
#include"Configuration.h"

class ConfigurationReader
{
public:
	Configuration loadConfiguration(std::string configurationFilePath);
};

