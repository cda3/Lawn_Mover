#include "pch.h"
#include "FilesReader.h"
#include <filesystem>
#include <sys/stat.h>

FilesReader::FilesReader(std::string folderPath, std::string fileFilter)
{
	_originFolderPath = folderPath;
	_fileFilter = fileFilter;
}

std::vector<std::shared_ptr<IResource>> FilesReader::read()
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

bool FilesReader::isFileNameMatchingRegex(std::string &filename, std::regex& regex)
{
	return std::regex_search(filename, regex);
}

struct stat FilesReader::readFileInfo(std::string filePath) {
	struct stat fileInfo;
	stat(filePath.c_str(), &fileInfo);
	return fileInfo;
}

Date FilesReader::creationDate(struct stat fileInfo) {
	struct tm newtime;
	localtime_s(&newtime, &fileInfo.st_ctime);
	auto year = newtime.tm_year + 1900;
	auto month = newtime.tm_mon + 1;
	auto day = newtime.tm_mday;
	return Date(year, month, day);
}