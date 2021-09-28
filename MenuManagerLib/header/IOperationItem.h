#pragma once

class IOperationItem
{
public:
	virtual ~IOperationItem() {}
	virtual void doAction() = 0;
};