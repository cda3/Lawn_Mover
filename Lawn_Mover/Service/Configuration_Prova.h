#pragma once
#include <vector>
#include "../Business_Logic/DisposeOldResources.h"
#include "../Business_Logic/Cleaner2.h"
#include <memory>

class Configuration_Prova
{
public:	
	Configuration_Prova(std::shared_ptr<Cleaner2> businessLogic, int runTime, int parallelismLevel);
	std::shared_ptr<Cleaner2> BusinessLogic;
	int Runtime;
	int ParallelismLevel;
};

