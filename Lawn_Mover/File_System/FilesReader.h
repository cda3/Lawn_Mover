#pragma once
#include "../Business_Logic/IResourcesReader.h"
#include "Date.h"
#include <vector>
#include <regex>

class __declspec(dllexport) FilesReader : public IResourcesReader
{
public:
	FilesReader(std::string folderPath, std::string fileFilter);
	std::vector<std::shared_ptr<IResource>> read() override;

protected:
	std::string _originFolderPath;
	std::string _fileFilter;
	struct stat readFileInfo(std::string filePath);
	Date creationDate(struct stat fileInfo);
	virtual void addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result) = 0;

private:
	bool isFileNameMatchingRegex(std::string &filename, std::regex& regex);
};

