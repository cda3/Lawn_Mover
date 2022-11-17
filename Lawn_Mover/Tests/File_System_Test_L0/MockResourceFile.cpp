#include "pch.h"
#include "MockResourceFile.h"

MockResourceFile::MockResourceFile(int year, int month, int day, std::string filePath, int deletedResult) : Resource_File_ForDeletion(year, month, day, filePath)
{
	_deletedResult = deletedResult;
}

int MockResourceFile::removeFile()
{
	isDisposeCalled = true;
	return _deletedResult;
}
