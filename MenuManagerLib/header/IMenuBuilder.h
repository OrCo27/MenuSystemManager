#pragma once

#include <iostream>
#include "IExternalMemory.h"
#include "IOperationItem.h"
#include "IStateSelection.h"
#include "Menu.h"

class IMenuBuilder
{
public:
	virtual ~IMenuBuilder() {}
	virtual Menu* addMenu(Menu* menu) = 0;
};

class IMenuItemsBuilder
{
public:
	virtual ~IMenuItemsBuilder() {}
	virtual void addMenuItem(Menu* currMenu, const std::string& itemName, Menu* nextMenu) = 0;
	virtual void addOperationItem(Menu* currMenu, const std::string& itemName, IOperationItem* operation) = 0;
	virtual IStateSelection& addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory* externalMemory) = 0;
	virtual IStateSelection& addStateSelectionItem(Menu* currMenu, const std::string& itemName) = 0;
};

class IKeyEnterRegisterBuilder
{
public:
	virtual ~IKeyEnterRegisterBuilder() {}
	virtual void registerEnterKey(char key) = 0;
};


class IKeyBackRegisterBuilder
{
public:
	virtual ~IKeyBackRegisterBuilder() {}
	virtual IKeyEnterRegisterBuilder& registerBackKey(char key) = 0;
};


class IKeyDownRegisterBuilder
{
public:
	virtual ~IKeyDownRegisterBuilder() {}
	virtual IKeyBackRegisterBuilder& registerDownKey(char key) = 0;
};


class IKeyUpRegisterBuilder
{
public:
	virtual ~IKeyUpRegisterBuilder() {}
	virtual IKeyDownRegisterBuilder& registerUpKey(char key) = 0;
};