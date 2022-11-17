#pragma once
#include "../../File_System/Resource_File_ForDeletion.h"

class MockResourceFileForDeletion : public Resource_File_ForDeletion
{
public:
	MockResourceFileForDeletion(int year, int month, int day, std::string filePath, int delatedResult);
	bool isDisposeCalled = false;

protected:
	int removeFile() override;

private:
	int _deletedResult;
};

