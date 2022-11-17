#include "pch.h"
#include "MockResourceFIleForHistory.h"

MockResourceFIleForHistory::MockResourceFIleForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder, int moveResult) : Resource_File_ForHistory(year, month, day, filePath, destinationFolder)
{
	_moveResult = moveResult;
}

bool MockResourceFIleForHistory::moveFile()
{
	isDisposeCalled = true;
	return _moveResult;
}
