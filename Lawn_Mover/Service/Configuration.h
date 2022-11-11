#pragma once
#include <vector>
#include "../Business_Logic/DisposeOldResources.h"
#include "../Business_Logic/Cleaner.h"
#include <memory>

class Configuration
{
public:	
	Configuration(std::shared_ptr<Cleaner> businessLogic, int runTime, int parallelismLevel);
	std::shared_ptr<Cleaner> BusinessLogic;
	int Runtime;
	int ParallelismLevel;
};

