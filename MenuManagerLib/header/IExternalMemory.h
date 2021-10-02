#pragma once

#include <iostream>

template <class T>
class IExternalMemory
{
public:
	virtual ~IExternalMemory() {}
	
	/* Save the current state into your class member */
	virtual void save(const T& state) = 0;

	/* Get the current state */
	virtual T getState() = 0;
};