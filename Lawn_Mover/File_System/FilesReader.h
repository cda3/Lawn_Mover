#pragma once
#include "../Business_Logic/IResourcesReader.h"

class __declspec(dllexport) FilesReader : public IResourcesReader
{
public:
	FilesReader(std::string folderPath);
	std::vector<IResource*> read() override;

private:
	std::string _folderPath;
};

