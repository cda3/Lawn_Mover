#pragma once
#include "C:\Lawn_Mover\Lawn_Mover\Business_Logic\IResource.h"
#include <ctime>
#include <string>
#include <chrono>
#include <ratio>
using namespace std::chrono;

class __declspec(dllexport) Resource_File_ForHistory : public IResource
{
public:
	Resource_File_ForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder);
	bool isOld(int days);
	void dispose();

protected:
	virtual bool moveFile();

private:
	std::string _filePath;
	std::string _destinationFolder;
	std::time_t _creationDate;
	int numberOfMonthsSinceJanuary(int month);
	int numberOfYearsSince1900(int year);
	int fileLifeTimeInDays(system_clock::duration d);
	system_clock::duration fileLifeTimeDuration();
};

