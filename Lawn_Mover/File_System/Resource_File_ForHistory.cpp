#include "pch.h"
#include "Resource_File_ForHistory.h"
#include <stdio.h>
#include <iostream>

Resource_File_ForHistory::Resource_File_ForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder) : ResourceFile(year, month, day, filePath)
{
	_destinationFolder = destinationFolder;
}

void Resource_File_ForHistory::dispose()
{
	auto result = moveFile();
	if (result == 0) {
		std::cout << "File " << _filePath.c_str() << " has not been moved" << std::endl;
	}
}

bool Resource_File_ForHistory::moveFile() {
	std::wstring _destinationFolderTemp = std::wstring(_destinationFolder.begin(), _destinationFolder.end());
	std::wstring _filePathTemp = std::wstring(_filePath.begin(), _filePath.end());
	return MoveFile(_filePathTemp.c_str(), _destinationFolderTemp.c_str());
}