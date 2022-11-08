#pragma once
#include "../../Business_Logic/IResource.h"

class MockResource : public IResource
{
public:
	MockResource(bool isOld);
	bool DisposedCalled = false;
	bool OldCalled = false;
	bool isOld(int days);
	void dispose();

private:
	bool _isOld;
};

