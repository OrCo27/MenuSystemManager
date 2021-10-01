#pragma once

#include <vector>
#include "Menu.h"
#include "IMenuUpdater.h"
#include "IMenuNavigation.h"
#include "IScreen.h"

using std::vector;

class MenuManager : public IMenuUpdater, public IMenuNavigation
{
private:
	vector<shared_ptr<Menu>> m_menuList;
	Menu* m_currMenu;
	const IScreen& m_screen;
	int m_currItemNum;
	int m_startWindow;
	int m_endWindow;

	GeneralItem* getCurrentItem();
	std::string getFixedName(const std::string& prefix, const std::string& itemName, const std::string& suffix);
	void printMenuName();
	void printMenuItem(int itemNum, int rowScreen);

public:
	MenuManager(const IScreen& screen);
	MenuManager(Menu* initialMenu, const IScreen& screen);
	~MenuManager();

	Menu* addMenu(Menu* menu);
	void clickCurrentItem() override;
	void moveToPrevMenu() override;
	void navigateNextItem() override;
	void navigatePrevItem() override;
	void setCurrentMenu(Menu* menu) override;
	void printMenu() override;
};