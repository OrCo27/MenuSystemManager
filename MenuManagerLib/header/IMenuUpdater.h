#pragma once

#include "Menu.h"

class IMenuUpdater
{
public:
	virtual ~IMenuUpdater() {}
	virtual void setCurrentMenu(Menu* menu) = 0;
};