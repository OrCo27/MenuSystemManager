#pragma once

#include <iostream>

class IStateSelection 
{
public:
	virtual ~IStateSelection() {}
	virtual IStateSelection& addState(const std::string& state) = 0;
};