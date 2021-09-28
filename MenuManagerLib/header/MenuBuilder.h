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

class MenuBuilder : public IMenuItemsBuilder, public IKeyUpRegisterBuilder,
	public IKeyDownRegisterBuilder, public IKeyBackRegisterBuilder, public IKeyEnterRegisterBuilder
{
private:
	const IKeyBoard& m_keyboard;
	const IScreen& m_screen;
	shared_ptr<MenuManager> m_menuMgr;
	shared_ptr<Navigation> m_nav;

public:
	MenuBuilder(const IKeyBoard& keyboard, const IScreen& screen);
	~MenuBuilder();

	void addMenuItem(Menu* currMenu, const std::string& itemName, Menu* nextMenu) override;
	void addOperationItem(Menu* currMenu, const std::string& itemName, IOperationItem* operation) override;
	IStateSelection& addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory* externalMemory) override;
	IStateSelection& addStateSelectionItem(Menu* currMenu, const std::string& itemName) override;
	Menu* addMenu(const std::string& menuName);
	IKeyDownRegisterBuilder& registerUpKey(char key) override;
	IKeyBackRegisterBuilder& registerDownKey(char key) override;
	IKeyEnterRegisterBuilder& registerBackKey(char key) override;
	void registerEnterKey(char key) override;

	void setInitialMenu(Menu* menu);
	shared_ptr<Navigation> getInstance();
};