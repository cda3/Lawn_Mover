#pragma once
#include "../File_System/ResourceFile.h"
#include <ctime>
#include <string>
#include <chrono>
#include <ratio>

class __declspec(dllexport) Resource_File_ForHistory : public ResourceFile
{
public:
	Resource_File_ForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder);
	void dispose() override;

protected:
	virtual bool moveFile();

private:
	std::string _destinationFolder;

};

