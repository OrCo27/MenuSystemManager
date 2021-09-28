#include "MenuItem.h"

MenuItem::MenuItem(const std::string& itemName, Menu* currMenu, Menu* nextMenu, IMenuUpdater* menuUpdater)
	: GeneralItem(itemName), m_nextMenu(nextMenu), m_menuUpdater(menuUpdater)
{
	nextMenu->setParentMenu(currMenu);
}

MenuItem::~MenuItem() = default;

std::string MenuItem::getItemName() const
{
	std::stringstream ss;
	ss << "[" << m_itemName << "]";
	return ss.str();
}

std::string MenuItem::getSuffixName() const
{
	return "";
}

void MenuItem::click()
{
	m_menuUpdater->setCurrentMenu(m_nextMenu);
}