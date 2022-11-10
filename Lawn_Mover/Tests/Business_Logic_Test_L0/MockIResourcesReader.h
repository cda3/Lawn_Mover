#pragma once
#include "../../Business_Logic/IResourcesReader.h"

class MockIResourcesReader : public IResourcesReader
{
public:
	MockIResourcesReader(std::vector<std::shared_ptr<IResource>> resources);
	std::vector<std::shared_ptr<IResource>> read();
	bool isReadCalled = false;

private:
	std::vector<std::shared_ptr<IResource>> _resources;

};

