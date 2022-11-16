#include "pch.h"
#include "Resource_File_ForHistory.h"
#include <stdio.h>
#include <iostream>

Resource_File_ForHistory::Resource_File_ForHistory(int year, int month, int day, std::string filePath, std::string destinationFolder)
{
	std::tm timeinfo = std::tm();
	timeinfo.tm_year = numberOfYearsSince1900(year);
	timeinfo.tm_mon = numberOfMonthsSinceJanuary(month);
	timeinfo.tm_mday = day;
	_creationDate = std::mktime(&timeinfo);
	_filePath = filePath;
	_destinationFolder = destinationFolder;
}


bool Resource_File_ForHistory::isOld(int days)
{
	system_clock::duration d = fileLifeTimeDuration();
	return (fileLifeTimeInDays(d) > days);
}

void Resource_File_ForHistory::dispose()
{
	auto result = moveFile();
	if (result == 0) {
		std::cout << "File " << _filePath.c_str() << " already moved from another Lawn Mover instance" << std::endl;
	}
}

int Resource_File_ForHistory::numberOfMonthsSinceJanuary(int month)
{
	return month - 1;
}

int Resource_File_ForHistory::numberOfYearsSince1900(int year)
{
	return year - 1900;
}

system_clock::duration Resource_File_ForHistory::fileLifeTimeDuration()
{
	system_clock::time_point tp = system_clock::from_time_t(_creationDate);
	return system_clock::now() - tp;
}

int Resource_File_ForHistory::fileLifeTimeInDays(system_clock::duration d) {
	typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
	days_type ndays = duration_cast<days_type> (d);
	return ndays.count();
}

bool Resource_File_ForHistory::moveFile() {
	std::wstring _destinationFolderTemp = std::wstring(_destinationFolder.begin(), _destinationFolder.end());
	std::wstring _filePathTemp = std::wstring(_filePath.begin(), _filePath.end());
	return MoveFile(_filePathTemp.c_str(), _destinationFolderTemp.c_str());
}