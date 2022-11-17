#pragma once
#include "../Business_Logic/IResource.h"
#include <ctime>
#include <string>
#include <chrono>
#include <ratio>
#include <stdio.h>

using namespace std::chrono;

class __declspec(dllexport) ResourceFile : public IResource
{
public:
	ResourceFile(int year, int month, int day, std::string filePath);
	bool isOld(int days) override;

protected:
	std::string _filePath;
	std::time_t _creationDate;
	int numberOfMonthsSinceJanuary(int month);
	int numberOfYearsSince1900(int year);

private:
	int fileLifeTimeInDays(system_clock::duration d);
	system_clock::duration fileLifeTimeDuration();
};

