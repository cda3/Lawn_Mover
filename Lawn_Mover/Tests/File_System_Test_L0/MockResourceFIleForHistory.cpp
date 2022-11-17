#include "pch.h"
#include "MockResourceFIleForHistory.h"

MockResourceFileForHistory::MockResourceFileForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder, int moveResult) : Resource_File_ForHistory(year, month, day, filePath, destinationFolder)
{
	_moveResult = moveResult;
}

bool MockResourceFileForHistory::moveFile()
{
	isDisposeCalled = true;
	return _moveResult;
}
