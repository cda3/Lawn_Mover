#include "pch.h"
#include "Resource_File.h"
#include <stdio.h>
#include <iostream>


Resource_File::Resource_File(int year, int month, int day, std::string filePath)
{
	std::tm timeinfo = std::tm();
	timeinfo.tm_year = numberOfYearsSince1900(year);
	timeinfo.tm_mon = numberOfMonthsSinceJanuary(month);
	timeinfo.tm_mday = day;     
	_creationDate = std::mktime(&timeinfo);
	_filePath = filePath;
}

bool Resource_File::isOld(int days)
{
	system_clock::duration d = fileLifeTimeDuration();
	return (fileLifeTimeInDays(d) > days);
}

void Resource_File::dispose()
{
	auto result = removeFile();
	if (result != 0) {
		std::cout << "File " << _filePath.c_str() << " already removed from another Lawn Mover instance" << std::endl;
	}
}

int Resource_File::numberOfMonthsSinceJanuary(int month)
{
	return month - 1;
}

int Resource_File::numberOfYearsSince1900(int year)
{
	return year - 1900;
}

system_clock::duration Resource_File::fileLifeTimeDuration() 
{
	system_clock::time_point tp = system_clock::from_time_t(_creationDate);
	return system_clock::now() - tp;
}

int Resource_File::fileLifeTimeInDays(system_clock::duration d) {
	typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
	days_type ndays = duration_cast<days_type> (d);
	return ndays.count();
}

int Resource_File::removeFile() {
	return remove(_filePath.c_str());
}