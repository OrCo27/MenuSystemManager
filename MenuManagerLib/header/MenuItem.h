#pragma once

#include "GeneralItem.h"
#include "Menu.h"
#include "IMenuUpdater.h"

class MenuItem : public GeneralItem
{
private:
	Menu* m_nextMenu;
	IMenuUpdater* m_menuUpdater;

public:
	MenuItem(Menu* currMenu, Menu* nextMenu, IMenuUpdater* menuUpdater);
	~MenuItem();

	std::string getSuffixName() const override;
	void click() override;
};