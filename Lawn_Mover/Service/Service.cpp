#include "../Business_Logic/provaCandida.h"
#include <iostream>
#include "../Business_Logic/IResourcesReader.h"
#include"ConfigurationReader.h"


int main()
{
	/*auto resources = std::vector<IResource>();

	provaCandida test = provaCandida();*/

	auto reader = ConfigurationReader();
	auto conf = reader.loadConfiguration("C://Lawn_Mover//Lawn_Mover//Tests//Manual_Test//Configuration_examples//Configuration.json");


    std::cout << "Hello World!\n";
}

