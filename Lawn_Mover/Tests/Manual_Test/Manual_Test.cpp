#include <iostream>
#include  "../../File_System/Resource_File.h"
#include "../../File_System/FilesReader.h"
#include "Manual_Test.h"
#include "../../Business_Logic/DisposeOldResources.h"
#include "../../SQLServerConnector/CreateRepoSQLServer.h"
#include "Derived.h"

int main()
{
	Base* b = new Derived();

	std::shared_ptr<Base> sb(new Derived());// = std::make_shared<Derived>(new Derived());

	//b->print();

	sb->print();

	/*CreateRepoSQLServer creator = CreateRepoSQLServer();
	creator.addReport("");
*/


	//FilesReader reader("C://Test//");
	/*std::shared_ptr<FilesReader>  reader(new FilesReader("C://Test//"));

	DisposeOldResources  disposer(-1, reader);
	disposer.execute();
*/

	//fileReaderTest();



	/*Resource_File exampleFile(2022, 11, 5, "C://Test//File1.txt");
	std::cout << exampleFile.isOld(1) << std::endl;
	std::cout << exampleFile.isOld(3) << std::endl;*/
	//exampleFile.dispose();


    std::cout << "Hello World!\n";
}

void fileReaderTest()
{
	FilesReader reader("C://Test//", "");
	auto x = reader.read();
	for (auto it = std::begin(x); it != std::end(x); ++it) {
		if ((*it)->isOld(-1))
			(*it)->dispose();
	}
}

