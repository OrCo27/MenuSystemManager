#include "MenuBuilder.h"

MenuBuilder::MenuBuilder(const IKeyBoard& keyboard, const IScreen& screen)
	: m_keyboard(keyboard), m_screen(screen)
{
	m_menuMgr = shared_ptr<MenuManager>(new MenuManager(screen));
	m_nav = shared_ptr<Navigation>(new Navigation(keyboard, m_menuMgr));
}

MenuBuilder::~MenuBuilder() = default;

Menu* MenuBuilder::addMenu(const std::string& menuName)
{
	return m_menuMgr->addMenu(new Menu(menuName));
}

void MenuBuilder::addMenuItem(Menu* currMenu, const std::string& itemName, Menu* nextMenu)
{
	currMenu->addItem(new MenuItem(itemName, currMenu, nextMenu, m_menuMgr.get()));
}

void MenuBuilder::addOperationItem(Menu* currMenu, const std::string& itemName, IOperationItem* operation)
{
	currMenu->addItem(new OperationItem(itemName, operation));
}

IStateSelection& MenuBuilder::addStateSelectionItem(Menu* currMenu, const std::string& itemName, IExternalMemory* externalMemory)
{
	return *(StateSelectionItem*)currMenu->addItem(new StateSelectionItem(itemName, externalMemory));
}

IStateSelection& MenuBuilder::addStateSelectionItem(Menu* currMenu, const std::string& itemName)
{
	return addStateSelectionItem(currMenu, itemName, nullptr);
}

void MenuBuilder::setInitialMenu(Menu* menu)
{
	if (menu)
	{
		m_menuMgr->setCurrentMenu(menu);
	}
}

IKeyDownRegisterBuilder& MenuBuilder::registerUpKey(char key)
{
	m_nav->registerKeyToCmd(key, E_NAV_CMD::UP);
	return *this;
}

IKeyBackRegisterBuilder& MenuBuilder::registerDownKey(char key)
{
	m_nav->registerKeyToCmd(key, E_NAV_CMD::DOWN);
	return *this;
}

IKeyEnterRegisterBuilder& MenuBuilder::registerBackKey(char key)
{
	m_nav->registerKeyToCmd(key, E_NAV_CMD::BACK);
	return *this;
}

void MenuBuilder::registerEnterKey(char key)
{
	m_nav->registerKeyToCmd(key, E_NAV_CMD::ENTER);
}

shared_ptr<Navigation> MenuBuilder::getInstance()
{
	return m_nav;
}