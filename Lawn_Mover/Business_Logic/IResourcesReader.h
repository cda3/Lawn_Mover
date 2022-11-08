#pragma once
#include "IResource.h" 
#include<vector>

class IResourcesReader
{
public:
	virtual std::vector<IResource*> read() = 0;
};

