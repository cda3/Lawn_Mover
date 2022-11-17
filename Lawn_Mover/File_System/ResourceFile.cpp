#include "pch.h"
#include "ResourceFile.h"

ResourceFile::ResourceFile(int year, int month, int day, std::string filePath)
{
	std::tm timeinfo = std::tm();
	timeinfo.tm_year = numberOfYearsSince1900(year);
	timeinfo.tm_mon = numberOfMonthsSinceJanuary(month);
	timeinfo.tm_mday = day;
	_creationDate = std::mktime(&timeinfo);
	_filePath = filePath;
}

bool ResourceFile::isOld(int days)
{
	system_clock::duration d = fileLifeTimeDuration();
	return (fileLifeTimeInDays(d) > days);
}


int ResourceFile::numberOfMonthsSinceJanuary(int month)
{
	return month - 1;
}

int ResourceFile::numberOfYearsSince1900(int year)
{
	return year - 1900;
}

system_clock::duration ResourceFile::fileLifeTimeDuration()
{
	system_clock::time_point tp = system_clock::from_time_t(_creationDate);
	return system_clock::now() - tp;
}

int ResourceFile::fileLifeTimeInDays(system_clock::duration d) {
	typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
	days_type ndays = duration_cast<days_type> (d);
	return ndays.count();
}