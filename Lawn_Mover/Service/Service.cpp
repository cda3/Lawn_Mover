#include "../Business_Logic/provaCandida.h"
#include <iostream>
#include "../Business_Logic/IResourcesReader.h"
#include"ConfigurationReader.h"


int main()
{
	auto reader = ConfigurationReader();
	auto conf = reader.prepareConfiguration("C://Lawn_Mover//Lawn_Mover//Tests//Manual_Test//Configuration_examples//Configuration.json");
	conf.BusinessLogic->Clean();
	/*for (int i = 0; i < conf.disposers.size(); ++i) {
		conf.disposers[i].execute();
	}*/

    std::cout << "Hello World!\n";
}

