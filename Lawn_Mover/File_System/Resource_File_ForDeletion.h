#pragma once
#include "../File_System/ResourceFile.h"
#include <ctime>
#include <string>
#include <chrono>
#include <ratio>


class __declspec(dllexport) Resource_File_ForDeletion : public ResourceFile
{
public:
	Resource_File_ForDeletion(int year, int month, int day,  std::string filePath);
	void dispose() override;

protected:
	virtual int removeFile();
};

