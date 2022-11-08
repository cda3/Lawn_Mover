#pragma once
#include "../../Business_Logic/IResourcesReader.h"

class MockIResourcesReader : public IResourcesReader
{
public:
	MockIResourcesReader(std::vector<IResource*> resources);
	std::vector<IResource*> read();
	bool isReadCalled = false;

private:
	std::vector<IResource*> _resources;

};

