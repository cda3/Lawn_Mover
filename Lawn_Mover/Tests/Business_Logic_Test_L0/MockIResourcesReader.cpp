#include "pch.h"
#include "MockIResourcesReader.h"

MockIResourcesReader::MockIResourcesReader(std::vector<IResource*> resources)
{
	_resources = resources;
}

std::vector<IResource*> MockIResourcesReader::read()
{
	isReadCalled = true;
	return _resources;
}
