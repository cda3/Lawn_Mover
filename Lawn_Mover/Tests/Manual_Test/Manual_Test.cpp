#include <iostream>
#include  "../../File_System/Resource_File_ForDeletion.h"
#include "../../File_System/FilesReader_ForDeletion.h"
#include "Manual_Test.h"
#include "../../Business_Logic/DisposeOldResources.h"
#include "../../SQLServerConnector/CreateRepoSQLServer.h"
#include "Derived.h"
#include "../../File_System/FilesReader_ForHistory.h"
#include <Windows.h>


int main()
{
	/*std::wstring a = L"C://Test//1//Nuova immagine bitmap.bmp";
	std::wstring b = L"C://Test//History//Nuova immagine bitmap.bmp";
	MoveFile(a.c_str(), b.c_str());*/

	/*FilesReader_ForHistory reader("C://Test//", "", "C://Test//History//");
	auto x = reader.read();
	for (auto it = std::begin(x); it != std::end(x); ++it) {
		if ((*it)->isOld(-1))
			(*it)->dispose();
	}*/

	//Base* b = new Derived();

	//std::shared_ptr<Base> sb(new Derived());// = std::make_shared<Derived>(new Derived());

	////b->print();

	//sb->print();



	/*CreateRepoSQLServer creator = CreateRepoSQLServer();
	creator.addReport("");
*/


	//FilesReader reader("C://Test//");
	std::shared_ptr<FilesReader_ForDeletion>  reader(new FilesReader_ForDeletion("C://Test//", ""));
	DisposeOldResources  disposer(-1, reader);
	disposer.execute();


	//fileReaderTest();



	/*Resource_File exampleFile(2022, 11, 5, "C://Test//File1.txt");
	std::cout << exampleFile.isOld(1) << std::endl;
	std::cout << exampleFile.isOld(3) << std::endl;*/
	//exampleFile.dispose();


    std::cout << "Hello World!\n";
}

void fileReaderTest()
{
	FilesReader_ForDeletion reader("C://Test//", "");
	auto x = reader.read();
	for (auto it = std::begin(x); it != std::end(x); ++it) {
		if ((*it)->isOld(-1))
			(*it)->dispose();
	}
}

