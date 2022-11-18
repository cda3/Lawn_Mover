#pragma once
#include "../../File_System/Resource_File_ForHistory.h"


class MockResourceFileForHistory : public Resource_File_ForHistory
{
public:
	MockResourceFileForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder, bool moveResult, bool isFilePresentInHistoryFolder);
	bool isDisposeCalled = false;
	bool isFileRenamed = false;

protected:
	bool moveFile() override;

private:
	bool _moveResult;
	bool _isFilePresentInHistoryFolder;
};

