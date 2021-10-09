#pragma once

#include "GeneralItem.h"
#include "IOperationItem.h"

class OperationItem : public GeneralItem
{
private:
	IOperationItem* m_operation;

public:
	OperationItem(const std::string& itemName, IOperationItem* operation);
	~OperationItem();
	void click() override;
};