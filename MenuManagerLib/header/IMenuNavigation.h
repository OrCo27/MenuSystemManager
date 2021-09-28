#pragma once

class IMenuNavigation
{
public:
	virtual ~IMenuNavigation() {}
	virtual void clickCurrentItem() = 0;
	virtual void moveToPrevMenu() = 0;
	virtual void navigateNextItem() = 0;
	virtual void navigatePrevItem() = 0;
	virtual void printMenu() = 0;
};