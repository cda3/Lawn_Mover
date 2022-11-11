#include "pch.h"
#include "Cleaner.h"

void Cleaner::Clean()
{
	for (int i = 0; i < _disposers.size(); ++i)
		_disposers[i].execute();
}

Cleaner::Cleaner(std::vector<DisposeOldResources> disposers)
{
	_disposers = disposers;
}
