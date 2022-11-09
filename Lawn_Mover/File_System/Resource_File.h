#pragma once
#include "../Business_Logic/IResource.h"
#include <ctime>
#include <string>
#include <chrono>
#include <ratio>
using namespace std::chrono;

class __declspec(dllexport) Resource_File : public IResource
{
public:
	Resource_File(int year, int month, int day,  std::string filePath);
	bool isOld(int days);
	void dispose();

protected:
	virtual int removeFile();

private:
	std::string _filePath;
	std::time_t _creationDate;
	int numberOfMonthsSinceJanuary(int month);
	int numberOfYearsSince1900(int year);
	int fileLifeTimeInDays(system_clock::duration d);
	system_clock::duration fileLifeTimeDuration();
};

