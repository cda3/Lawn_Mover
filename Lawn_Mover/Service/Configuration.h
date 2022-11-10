#pragma once
#include "../Business_Logic/DisposeOldResources.h"
#include <vector>

class Configuration
{
public:
	std::vector<DisposeOldResources> disposers;
	int runtime;
	int parallelismLevel;
};

