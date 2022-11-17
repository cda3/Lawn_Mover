#pragma once
#include "../../File_System/Resource_File_ForHistory.h"


class MockResourceFIleForHistory : public Resource_File_ForHistory
{
public:
	MockResourceFIleForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder, int moveResult);
	bool isDisposeCalled = false;

protected:
	bool moveFile() override;

private:
	int _moveResult;

};

