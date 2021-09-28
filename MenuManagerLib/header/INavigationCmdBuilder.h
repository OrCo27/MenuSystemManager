#pragma once

enum class E_NAV_CMD
{
	UP = 0,
	DOWN,
	BACK,
	ENTER
};

class INavigationCmdBuilder
{
public:
	virtual ~INavigationCmdBuilder() {}
	virtual INavigationCmdBuilder* registerKeyToCmd(char key, E_NAV_CMD cmd) = 0;
};