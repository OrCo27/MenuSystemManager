#include "GeneralItem.h"

GeneralItem::GeneralItem(const std::string& itemName)
	: m_itemName(itemName)
{
}

std::string GeneralItem::getItemName() const
{
	return m_itemName;
}

std::string GeneralItem::getSuffixName() const
{
	return "";
}