#pragma once
#include "../File_System/FilesReader.h"
#include "Date.h"
#include <vector>
#include <regex>

class __declspec(dllexport) FilesReader_ForHistory : public FilesReader
{
public:
	FilesReader_ForHistory(std::string folderPath, std::string fileFilter, std::string destinationPath);

private:
	std::string _destinationFolderPath;
	void addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result);

};

