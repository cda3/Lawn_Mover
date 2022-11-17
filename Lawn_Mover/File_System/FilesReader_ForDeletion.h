#pragma once
#include "../File_System/FilesReader.h"
#include "Date.h"
#include <vector>
#include <regex>

class __declspec(dllexport) FilesReader_ForDeletion : public FilesReader
{
public:
	FilesReader_ForDeletion(std::string folderPath, std::string fileFilter);

private:
	void addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result);
	
};

