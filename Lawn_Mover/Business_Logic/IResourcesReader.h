#pragma once
#include "IResource.h" 
#include<vector>
#include <memory>

class IResourcesReader
{
public:
	virtual std::vector<std::shared_ptr<IResource>> read() = 0;
};

