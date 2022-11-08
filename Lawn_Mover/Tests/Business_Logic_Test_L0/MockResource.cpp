#include "pch.h"
#include "MockResource.h"

MockResource::MockResource(bool isOld) 
{
	_isOld = isOld;
}

bool MockResource::isOld(int days) 
{
	OldCalled = true;
	return _isOld;
}

void MockResource::dispose()
{
	DisposedCalled = true;
}
