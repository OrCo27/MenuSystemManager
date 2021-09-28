#pragma once

#include "IExternalDevice.h"
#include <iostream>

class IScreen : public IExternalDevice
{
public:
	virtual ~IScreen() {}
	virtual void clear() const = 0;
	virtual void setCursor(int row, int col) const = 0;
	virtual void display(const std::string& text) const = 0;
	virtual int getTotalCols() const = 0;
	virtual int getTotalRows() const = 0;
	virtual void setup() = 0;
};