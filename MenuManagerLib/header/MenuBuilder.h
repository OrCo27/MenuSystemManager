#pragma once

#include <iostream>
#include <vector>
#include "Menu.h"
#include "IScreen.h"
#include "IKeyBoard.h"
#include "IMenuBuilder.h"
#include "MenuManager.h"
#include "Navigation.h"
#include "MenuItem.h"
#include "OperationItem.h"
#include "StateSelectionItem.h"


using std::map;
using std::shared_ptr;

class MenuBuilder : public IKeyUpRegisterBuilder,
	public IKeyDownRegisterBuilder, public IKeyBackRegisterBuilder, public IKeyEnterRegisterBuilder
{
private:
	const IKeyBoard& m_keyboard;
	const IScreen& m_screen;
	shared_ptr<MenuManager> m_menuMgr;
	Navigation* m_nav;

public:
	MenuBuilder(const IKeyBoard& keyboard, const IScreen& screen);
	~MenuBuilder();

	/*
		Add new menu page
		menuName - The name of the menu displayed as title on menu page
	*/
	Menu* addMenu(const std::string& menuName);

	/*
		Add a new menu item into specific menu, which navigate to another menu page when selected
		currMenu - The menu page to which the item belongs
		nextMenu - The next menu that will navigating from this item
	*/
	void addMenuItem(Menu* currMenu, Menu* nextMenu);

	/*
		Add a new operation item into specific menu, which perform a custom operation when selected
		currMenu - The menu page to which the item belongs
		itemName - The name of this item, which display on the screen
		operation - The external operation that registered to this item and perform when this item clicked
	*/
	void addOperationItem(Menu* currMenu, const std::string& itemName, IOperationItem* operation);
	
	/*
		Add a new state selection item into specific menu, which allow storing and changing a state from collection of states
		currMenu - The menu page to which the item belongs
		itemName - The name of this item, which display on the screen
		externalMemory - The external memory object that will store the current state for future using
	*/
	template <typename T>
	IStateSelection<T>& addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory<T>* externalMemory);
	
	/*
	Add a new state selection item into specific menu, which allow storing and changing a state from collection of states
	currMenu - The menu page to which the item belongs
	itemName - The name of this item, which display on the screen
	*/
	template <typename T>
	IStateSelection<T>& addStateSelectionItem(Menu* currMenu, const std::string& itemName);

	/*
		Register a key for 'UP' operation for controlling the menu and navigate to upper item
	*/
	IKeyDownRegisterBuilder& registerUpKey(char key) override;

	/*
		Register a key for 'DOWN' operation for controlling the menu and navigate to lower item
	*/
	IKeyBackRegisterBuilder& registerDownKey(char key) override;

	/*
		Register a key for 'BACK' operation for controlling the menu and navigate to previous menu
	*/
	IKeyEnterRegisterBuilder& registerBackKey(char key) override;

	/*
		Register a key for 'ENTER' operation for controlling the menu and clicking on current item selected 
		for performing the relevant operation:
		- Menu Item: move to relevant menu page.
		- Operational Item: perform an custom action that registered to this item.
		- State Item: change the current state belongs to this item.
	*/
	void registerEnterKey(char key) override;

	/* 
		Set the menu page which displayed as the initial menu
	*/
	void setInitialMenu(Menu* menu);

	/*
		Get the final object after all building
	*/
	Navigation* getInstance();
};

template <typename T>
IStateSelection<T>& MenuBuilder::addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory<T>* externalMemory)
{
	return *static_cast<StateSelectionItem<T>*>(currMenu->addItem(new StateSelectionItem<T>(itemName, externalMemory)));
}

template <typename T>
IStateSelection<T>& MenuBuilder::addStateSelectionItem(Menu* currMenu, const std::string& itemName)
{
	return addStateSelectionItem<T>(currMenu, itemName, nullptr);
}