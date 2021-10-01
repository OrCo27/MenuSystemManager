#pragma once

#include <iostream>

template <class T>
class IStateSelection 
{
public:
	virtual ~IStateSelection() {}

	virtual IStateSelection<T>& addState(const T& state) = 0;
};