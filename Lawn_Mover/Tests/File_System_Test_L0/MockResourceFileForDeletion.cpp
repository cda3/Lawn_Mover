#include "pch.h"
#include "MockResourceFileForDeletion.h"

MockResourceFileForDeletion::MockResourceFileForDeletion(int year, int month, int day, std::string filePath, int deletedResult) : Resource_File_ForDeletion(year, month, day, filePath)
{
	_deletedResult = deletedResult;
}

int MockResourceFileForDeletion::removeFile()
{
	isDisposeCalled = true;
	return _deletedResult;
}
