#pragma once

#include <map>
#include <iostream>
#include "INavigationCmdBuilder.h"
#include "IMenuNavigation.h"
#include "IKeyBoard.h"

using std::map;
using std::shared_ptr;

class Navigation : public INavigationCmdBuilder
{
private:
	map<char, E_NAV_CMD> m_keyToCommand;
	const IKeyBoard& m_keyboard;
	shared_ptr<IMenuNavigation> m_menuNavigation;

public:
	Navigation(const IKeyBoard& keyboard, const shared_ptr<IMenuNavigation>& menuNavigation);
	~Navigation();

	INavigationCmdBuilder* registerKeyToCmd(char key, E_NAV_CMD cmd) override;
	void nav();
};