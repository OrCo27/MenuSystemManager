#pragma once

#include "Menu.h"
#include <iostream>

class IMenuUpdater
{
public:
	virtual ~IMenuUpdater() {}
	virtual void setCurrentMenu(Menu* menu) = 0;
};