#pragma once

class IExternalDevice
{
public:
	virtual ~IExternalDevice() {}
	virtual void setup() = 0;
};