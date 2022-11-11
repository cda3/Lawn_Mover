#pragma once
#include "DisposeOldResources.h"
#include <vector>

class Cleaner2
{
private:
	std::vector<DisposeOldResources> _disposers;

public:
	void Clean();
	Cleaner2(std::vector<DisposeOldResources> disposers);
};

