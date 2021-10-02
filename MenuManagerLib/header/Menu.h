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

	/* Add general item to the collection items belongs to this menu */
	GeneralItem* addItem(GeneralItem* item);

	/* 
		Get the parent of this menu.
		When there is no parent, return nullptr 
	*/
	Menu* getParentMenu();

	/* Set a parent for current menu */
	void setParentMenu(Menu* parentMenu);

	/* Get the menu name which displayed on the screen */
	std::string getMenuName() const;

	/* 
		Get specific item object by index 
		itemNum - the index of the item relative to the collection
	*/
	GeneralItem* getItem(int itemNum);

	/* Get total items belongs to this menu */
	int getTotalItemsCount() const;
};