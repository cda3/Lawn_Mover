#pragma once
#include "../Business_Logic/IResourcesReader.h"
#include "Date.h"

class __declspec(dllexport) FilesReader : public IResourcesReader
{
public:
	FilesReader(std::string folderPath);
	std::vector<std::shared_ptr<IResource>> read() override;

private:
	std::string _folderPath;
	struct stat readFileInfo(std::string filePath);
	Date creationDate(struct stat fileInfo);
};

