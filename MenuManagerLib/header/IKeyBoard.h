#pragma once

#include "IExternalDevice.h"

class IKeyBoard : public IExternalDevice
{
public:
	virtual ~IKeyBoard() {}

	/*
		Read the current pressed key.
		This method can be blocking operation
	*/
	virtual char readKey() const = 0;

	/* Setup and initialize the connection of an external keyboard */
	virtual void setup() = 0;
};