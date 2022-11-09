#include "pch.h"
#include "FilesReader.h"
#include "./Resource_File.h"
#include <filesystem>
#include <sys/stat.h>

FilesReader::FilesReader(std::string folderPath)
{
	_folderPath = folderPath;
}

std::vector<IResource*> FilesReader::read()
{
	auto result = std::vector<IResource*>();

	for (auto& file : std::filesystem::directory_iterator(_folderPath)) {
	//for (auto& file : std::filesystem::directory_iterator{_folderPath}) {
		
		//to extract
		struct stat fileInfo;
		auto o = (file.path()).string();
		const char * o2 = o.c_str();
		stat(o2, &fileInfo);//read the file
		
		//to extract
		struct tm newtime;
		localtime_s(&newtime, &fileInfo.st_ctime);
		
		auto year = newtime.tm_year + 1900;
		auto month = newtime.tm_mon + 1;
		auto day = newtime.tm_mday;
		Resource_File resource(year, month, day, o);
		result.push_back(&resource);
	}


	return result;
}
