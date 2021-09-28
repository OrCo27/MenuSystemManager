#include "Menu.h"

Menu::Menu(const std::string& menuName)
	: Menu(menuName, nullptr)
{

}

Menu::Menu(const std::string& menuName, Menu* parentMenu)
	: m_menuName(menuName), m_parentMenu(parentMenu)
{

}

Menu::~Menu() = default;

Menu* Menu::getParentMenu()
{
	return m_parentMenu;
}

void Menu::setParentMenu(Menu* parentMenu)
{
	m_parentMenu = parentMenu;
}

std::string Menu::getMenuName() const
{
	return m_menuName;
}

int Menu::getTotalItemsCount() const
{
	return m_itemsList.size();
}

GeneralItem* Menu::getItem(int itemNum)
{
	if (itemNum >= 0 && itemNum < getTotalItemsCount())
	{
		return m_itemsList[itemNum].get();
	}

	return nullptr;
}

GeneralItem* Menu::addItem(GeneralItem* item)
{
	m_itemsList.push_back(shared_ptr<GeneralItem>(item));
	return item;
}