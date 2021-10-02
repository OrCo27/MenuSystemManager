#pragma once

#include <iostream>
#include <sstream>

class GeneralItem
{
protected:
	std::string m_itemName;

public:
	GeneralItem(const std::string& itemName);
	virtual ~GeneralItem() { };

	/*
		Get the item name for displaying on screen.
		Override it when you want to change the format of displaying
	*/
	virtual std::string getItemName() const;

	/*
		Get suffix for this item for displaying as suffix on screen.
		Override it when you want to change the format of displaying
	*/
	virtual std::string getSuffixName() const;

	/*
		Perform a custom action when this item clicked
	*/
	virtual void click() = 0;
};