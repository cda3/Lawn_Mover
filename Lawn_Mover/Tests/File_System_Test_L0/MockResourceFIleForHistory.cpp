#include "pch.h"
#include "MockResourceFIleForHistory.h"

MockResourceFileForHistory::MockResourceFileForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder, bool moveResult, bool isFilePresentInHistoryFolder) : Resource_File_ForHistory(year, month, day, filePath, destinationFolder)
{
	_moveResult = moveResult;
	_isFilePresentInHistoryFolder = isFilePresentInHistoryFolder;
}

bool MockResourceFileForHistory::moveFile()
{
	isDisposeCalled = true;
	if (_isFilePresentInHistoryFolder)
		isFileRenamed = false;
	else
		isFileRenamed = true;
	return _moveResult;
}
