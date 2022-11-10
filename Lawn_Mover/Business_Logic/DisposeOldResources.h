#pragma once
#include<string>
#include<memory>
#include"IResourcesReader.h"

class DisposeOldResources {
public:
	//auto resources = std::vector<std::shared_ptr<IResource>>();

	DisposeOldResources(int daysForOldResources, std::shared_ptr<IResourcesReader> reader);
	void execute();

private:
	int _daysForOldResources;
	std::shared_ptr<IResourcesReader> _reader;
	void checkSingleResource(IResource* resource);
	bool isResourceTooOld(IResource* resource);

};

