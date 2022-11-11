#pragma once
#include "DisposeOldResources.h"
#include <vector>

class Cleaner
{
private:
	std::vector<DisposeOldResources> _disposers;

public:
	void Clean();
	Cleaner(std::vector<DisposeOldResources> disposers);
};

