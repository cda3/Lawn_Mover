#include <iostream>
#include  "../../File_System/Resource_File.h"
#include "../../File_System/FilesReader.h"

int main()
{
	FilesReader reader("C://Test//");
	auto x = reader.read();



	/*Resource_File exampleFile(2022, 11, 5, "C://Test//File1.txt");
	std::cout << exampleFile.isOld(1) << std::endl;
	std::cout << exampleFile.isOld(3) << std::endl;*/
	//exampleFile.dispose();


    std::cout << "Hello World!\n";
}

