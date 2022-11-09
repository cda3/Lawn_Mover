#pragma once
#include "../../File_System/Resource_File.h"

class MockResourceFile : public Resource_File
{
public:
	MockResourceFile(int year, int month, int day, std::string filePath, int delatedResult);
	bool isDisposeCalled = false;

protected:
	int removeFile() override;

private:
	int _deletedResult;
};

