#include "OperationItem.h"

OperationItem::OperationItem(const std::string& itemName, IOperationItem* operation)
	: GeneralItem(itemName), m_operation(operation)
{

}

OperationItem::~OperationItem() = default;

void OperationItem::click()
{
	if (m_operation)
	{
		m_operation->doAction();
	}
}