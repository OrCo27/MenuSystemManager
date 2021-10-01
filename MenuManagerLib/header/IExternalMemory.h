#pragma once

#include <iostream>

template <class T>
class IExternalMemory
{
public:
	virtual ~IExternalMemory() {}
	virtual void save(const T& state) = 0;
	virtual T getState() = 0;
};