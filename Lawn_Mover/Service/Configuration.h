#pragma once
#include<string>
#include<map>
#include<vector>

class ManagedFolder {
public:
	bool enable;
	std::string path;
	int daysForOldness;
	bool useSubfolder;
	std::map<std::string, std::string> managementInstruction;
};

class Configuration
{
public:
	int runtime;
	int parallelismLevel;
	std::vector<ManagedFolder> folders;
};

