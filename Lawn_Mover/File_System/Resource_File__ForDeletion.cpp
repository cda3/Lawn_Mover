#include "pch.h"
#include "Resource_File_ForDeletion.h"
#include <stdio.h>
#include <iostream>


Resource_File_ForDeletion::Resource_File_ForDeletion(int year, int month, int day, std::string filePath) : ResourceFile(year, month, day, filePath)
{
}

void Resource_File_ForDeletion::dispose()
{
	auto result = removeFile();
	if (result != 0) {
		std::cout << "File " << _filePath.c_str() << " already removed from another Lawn Mover instance" << std::endl;
	}
}

int Resource_File_ForDeletion::removeFile() {
	return remove(_filePath.c_str());
}