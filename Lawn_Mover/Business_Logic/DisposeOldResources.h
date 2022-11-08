#pragma once
#include<string>
#include"IResourcesReader.h"

class DisposeOldResources {
public:
	DisposeOldResources(int daysForOldResources, IResourcesReader* reader);
	void execute();

private:
	int _daysForOldResources;
	IResourcesReader *_reader;
	void checkSingleResource(IResource* resource);
	bool isResourceTooOld(IResource* resource);

};

