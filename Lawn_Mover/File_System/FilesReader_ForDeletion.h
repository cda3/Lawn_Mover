#pragma once
#include "../Business_Logic/IResourcesReader.h"
#include "Date.h"
#include <vector>
#include <regex>

class __declspec(dllexport) FilesReader_ForDeletion : public IResourcesReader
{
public:
	FilesReader_ForDeletion(std::string folderPath, std::string fileFilter);
	std::vector<std::shared_ptr<IResource>> read() override;

private:
	std::string _folderPath;
	struct stat readFileInfo(std::string filePath);
	Date creationDate(struct stat fileInfo);
	std::string _fileFilter;
	void addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result);
	bool isFileNameMatchingRegex(std::string &filename, std::regex& regex);
};

