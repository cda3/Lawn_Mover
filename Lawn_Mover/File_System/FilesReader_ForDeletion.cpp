#include "pch.h"
#include "FilesReader_ForDeletion.h"
#include "Resource_File_ForDeletion.h"
#include <filesystem>
#include <sys/stat.h>


FilesReader_ForDeletion::FilesReader_ForDeletion(std::string folderPath, std::string fileFilter) : FilesReader(folderPath, fileFilter)
{
}

void FilesReader_ForDeletion::addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result)
{
	struct stat fileInfo = readFileInfo(filePath);
	auto fileCreationDate = creationDate(fileInfo);
	std::shared_ptr<Resource_File_ForDeletion> resource(new Resource_File_ForDeletion(fileCreationDate.Year, fileCreationDate.Month, fileCreationDate.Day, filePath));
	result.push_back(std::move(resource));
}
