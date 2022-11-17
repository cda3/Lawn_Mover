#include "pch.h"
#include "Resource_File_ForDeletion.h"
#include <stdio.h>
#include <iostream>


Resource_File_ForDeletion::Resource_File_ForDeletion(int year, int month, int day, std::string filePath)
{
	std::tm timeinfo = std::tm();
	timeinfo.tm_year = numberOfYearsSince1900(year);
	timeinfo.tm_mon = numberOfMonthsSinceJanuary(month);
	timeinfo.tm_mday = day;     
	_creationDate = std::mktime(&timeinfo);
	_filePath = filePath;
}

bool Resource_File_ForDeletion::isOld(int days)
{
	system_clock::duration d = fileLifeTimeDuration();
	return (fileLifeTimeInDays(d) > days);
}

void Resource_File_ForDeletion::dispose()
{
	auto result = removeFile();
	if (result != 0) {
		std::cout << "File " << _filePath.c_str() << " already removed from another Lawn Mover instance" << std::endl;
	}
}

int Resource_File_ForDeletion::numberOfMonthsSinceJanuary(int month)
{
	return month - 1;
}

int Resource_File_ForDeletion::numberOfYearsSince1900(int year)
{
	return year - 1900;
}

system_clock::duration Resource_File_ForDeletion::fileLifeTimeDuration() 
{
	system_clock::time_point tp = system_clock::from_time_t(_creationDate);
	return system_clock::now() - tp;
}

int Resource_File_ForDeletion::fileLifeTimeInDays(system_clock::duration d) {
	typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
	days_type ndays = duration_cast<days_type> (d);
	return ndays.count();
}

int Resource_File_ForDeletion::removeFile() {
	return remove(_filePath.c_str());
}