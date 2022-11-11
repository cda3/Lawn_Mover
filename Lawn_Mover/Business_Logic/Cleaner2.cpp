#include "pch.h"
#include "Cleaner2.h"

void Cleaner2::Clean()
{
	for (int i = 0; i < _disposers.size(); ++i)
		_disposers[i].execute();
}

Cleaner2::Cleaner2(std::vector<DisposeOldResources> disposers)
{
	_disposers = disposers;
}
