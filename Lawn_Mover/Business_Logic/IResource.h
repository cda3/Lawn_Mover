#pragma once
class IResource
{
public:
	virtual bool isOld(int days) = 0;
	virtual void dispose() = 0;
};

