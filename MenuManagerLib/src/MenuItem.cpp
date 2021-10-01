#include "MenuItem.h"

MenuItem::MenuItem(Menu* currMenu, Menu* nextMenu, IMenuUpdater* menuUpdater)
	: GeneralItem(nextMenu->getMenuName()), m_nextMenu(nextMenu), m_menuUpdater(menuUpdater)
{
	nextMenu->setParentMenu(currMenu);
}

MenuItem::~MenuItem() = default;

std::string MenuItem::getSuffixName() const
{
	return "->";
}

void MenuItem::click()
{
	m_menuUpdater->setCurrentMenu(m_nextMenu);
}