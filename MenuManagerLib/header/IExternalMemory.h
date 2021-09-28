#pragma once

#include <iostream>

class IExternalMemory
{
public:
	virtual ~IExternalMemory() {}
	virtual void save(const std::string& state) = 0;
};