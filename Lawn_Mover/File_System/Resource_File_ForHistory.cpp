#include "pch.h"
#include "Resource_File_ForHistory.h"
#include <stdio.h>
#include <iostream>
#include <filesystem>

Resource_File_ForHistory::Resource_File_ForHistory(int year, int month, int day, std::string filePath, std::string destinationFile) : ResourceFile(year, month, day, filePath)
{
	_destinationFile = destinationFile;
}

void Resource_File_ForHistory::dispose()
{
	checkDestinationFileName();
	auto result = moveFile();
	if (result == 0) {
		std::cout << "File " << _filePath.c_str() << " has already been moved from another Lawn Mover Instance" << std::endl;
	}
}

bool Resource_File_ForHistory::moveFile() {
	std::wstring _destinationFileTemp = std::wstring(_destinationFile.begin(), _destinationFile.end());
	std::wstring _filePathTemp = std::wstring(_filePath.begin(), _filePath.end());
	return MoveFile(_filePathTemp.c_str(), _destinationFileTemp.c_str());
}

void Resource_File_ForHistory::checkDestinationFileName() {
	if (std::filesystem::exists(_destinationFile)) {
		auto fileExtension = _destinationFile.substr(_destinationFile.find_last_of("."));
		auto fileNameWithoutExtension = _destinationFile.substr(0, _destinationFile.find_last_of("."));
		_destinationFile = fileNameWithoutExtension + "_1" + fileExtension;
		checkDestinationFileName();
	}
}