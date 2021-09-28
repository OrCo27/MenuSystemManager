#pragma once

#include "IExternalDevice.h"

class IKeyBoard : public IExternalDevice
{
public:
	virtual ~IKeyBoard() {}
	virtual char readKey() const = 0;
	virtual void setup() = 0;
};