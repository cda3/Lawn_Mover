#include "pch.h"
#include "FilesReader_ForHistory.h"
#include "Resource_File_ForHistory.h"
#include <filesystem>
#include <sys/stat.h>


FilesReader_ForHistory::FilesReader_ForHistory(std::string folderPath, std::string fileFilter, std::string destinationFolder)
{
	_originFolderPath = folderPath;
	_fileFilter = fileFilter;
	_destinationFolderPath = destinationFolder;

}

std::vector<std::shared_ptr<IResource>> FilesReader_ForHistory::read()
{
	std::vector<std::shared_ptr<IResource>> result;
	for (auto& file : std::filesystem::directory_iterator(_originFolderPath)) {
		if (file.is_regular_file()) {
			auto filePath = (file.path()).string();
			auto filename = filePath.substr(filePath.find_last_of("/\\") + 1);
			auto regex = std::regex(_fileFilter, std::regex_constants::ECMAScript | std::regex_constants::icase);
			if (_fileFilter.empty() || isFileNameMatchingRegex(filename, regex))
				addFile(filePath, result);
		}
	}
	return result;
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

bool FilesReader_ForHistory::isFileNameMatchingRegex(std::string &filename, std::regex& regex)
{
	return std::regex_search(filename, regex);
}

struct stat FilesReader_ForHistory::readFileInfo(std::string filePath) {
	struct stat fileInfo;
	stat(filePath.c_str(), &fileInfo);
	return fileInfo;
}

Date FilesReader_ForHistory::creationDate(struct stat fileInfo) {
	struct tm newtime;
	localtime_s(&newtime, &fileInfo.st_ctime);
	auto year = newtime.tm_year + 1900;
	auto month = newtime.tm_mon + 1;
	auto day = newtime.tm_mday;
	return Date(year, month, day);
}