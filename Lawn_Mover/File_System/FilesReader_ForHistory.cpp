#include "pch.h"
#include "FilesReader_ForHistory.h"
#include "Resource_File_ForHistory.h"
#include <filesystem>
#include <sys/stat.h>


FilesReader_ForHistory::FilesReader_ForHistory(std::string folderPath, std::string fileFilter, std::string destinationFolder) : FilesReader(folderPath, fileFilter)
{
	_destinationFolderPath = destinationFolder;
}

void FilesReader_ForHistory::addFile(std::string &filePath, std::vector<std::shared_ptr<IResource>> &result)
{
	struct stat fileInfo = readFileInfo(filePath);
	auto fileCreationDate = creationDate(fileInfo);
	auto filename = filePath.substr(filePath.find_last_of("/\\") + 1);
	auto destination = _destinationFolderPath + filename;
	std::shared_ptr<Resource_File_ForHistory> resource(new Resource_File_ForHistory(fileCreationDate.Year, fileCreationDate.Month, fileCreationDate.Day, filePath, destination));
	result.push_back(std::move(resource));
}
