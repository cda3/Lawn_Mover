#include "pch.h"
#include "MockIResourcesReader.h"

MockIResourcesReader::MockIResourcesReader(std::vector<std::shared_ptr<IResource>> resources)
{
	_resources = resources;
}

std::vector<std::shared_ptr<IResource>> MockIResourcesReader::read()
{
	isReadCalled = true;
	return _resources;
}
