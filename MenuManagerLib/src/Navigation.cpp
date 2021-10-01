#include "Navigation.h"

Navigation::Navigation(const IKeyBoard& keyboard, const shared_ptr<IMenuNavigation>& menuNavigation)
	: m_keyboard(keyboard), m_menuNavigation(menuNavigation)
{

}

Navigation::~Navigation() = default;

INavigationCmdBuilder* Navigation::registerKeyToCmd(char key, E_NAV_CMD cmd)
{
	m_keyToCommand.insert({ key , cmd});
	return this;
}

void Navigation::navigate()
{
	static bool firstTime(true);

	// print menu for the first time
	if (firstTime)
	{
		m_menuNavigation->printMenu();
		firstTime = false;
	}

	char keyPressed = m_keyboard.readKey();
	if (m_keyToCommand.find(keyPressed) == m_keyToCommand.end()) 
	{
		// command not found for current key, do nothing
		return;
	}
	else 
	{
		// command found, perform the operation by the command pressed 
		switch (m_keyToCommand[keyPressed])
		{
		case E_NAV_CMD::UP:
			m_menuNavigation->navigatePrevItem();
			break;

		case E_NAV_CMD::DOWN:
			m_menuNavigation->navigateNextItem();
			break;

		case E_NAV_CMD::BACK:
			m_menuNavigation->moveToPrevMenu();
			break;

		case E_NAV_CMD::ENTER:
			m_menuNavigation->clickCurrentItem();
			break;
		}

		m_menuNavigation->printMenu();
	}
}