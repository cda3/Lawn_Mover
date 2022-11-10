#include "pch.h"
#include "DisposeOldResources.h"


DisposeOldResources::DisposeOldResources(int daysForOldResources, IResourcesReader* reader)
{
	_daysForOldResources = daysForOldResources;
	_reader = reader;
}

void DisposeOldResources::execute()
{
	auto resources = _reader->read();
	for (auto it = resources.begin(); it != resources.end(); ++it)
		checkSingleResource(it->get());
}

void DisposeOldResources::checkSingleResource(IResource* resource)
{
	if (isResourceTooOld(resource))
		resource->dispose();
}

bool DisposeOldResources::isResourceTooOld(IResource* resource)
{
	return resource->isOld(_daysForOldResources);
}



