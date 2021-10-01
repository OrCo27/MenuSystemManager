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

	Menu* addMenu(const std::string& menuName);
	void addMenuItem(Menu* currMenu, Menu* nextMenu);
	void addOperationItem(Menu* currMenu, const std::string& itemName, IOperationItem* operation);
	
	template <typename T>
	IStateSelection<T>& addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory<T>* externalMemory);
	
	template <typename T>
	IStateSelection<T>& addStateSelectionItem(Menu* currMenu, const std::string& itemName);

	IKeyDownRegisterBuilder& registerUpKey(char key) override;
	IKeyBackRegisterBuilder& registerDownKey(char key) override;
	IKeyEnterRegisterBuilder& registerBackKey(char key) override;
	void registerEnterKey(char key) override;

	void setInitialMenu(Menu* menu);
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