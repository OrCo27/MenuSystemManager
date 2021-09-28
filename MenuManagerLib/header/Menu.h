#pragma once

#include <iostream>
#include <vector>
#include "GeneralItem.h"

using std::vector;
using std::shared_ptr;

class Menu
{
private:
	vector<shared_ptr<GeneralItem>> m_itemsList;
	std::string m_menuName;
	Menu* m_parentMenu;
	
public:
	Menu(const std::string& menuName);
	Menu(const std::string& menuName, Menu* parentMenu);
	~Menu();

	GeneralItem* addItem(GeneralItem* item);
	Menu* getParentMenu();
	void setParentMenu(Menu* parentMenu);
	std::string getMenuName() const;
	GeneralItem* getItem(int itemNum);
	int getTotalItemsCount() const;
};