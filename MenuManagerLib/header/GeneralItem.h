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

	virtual std::string getItemName() const;
	virtual std::string getSuffixName() const;
	virtual void click() = 0;
};