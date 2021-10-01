#pragma once

#include <iostream>

class IKeyEnterRegisterBuilder
{
public:
	virtual ~IKeyEnterRegisterBuilder() {}
	virtual void registerEnterKey(char key) = 0;
};


class IKeyBackRegisterBuilder
{
public:
	virtual ~IKeyBackRegisterBuilder() {}
	virtual IKeyEnterRegisterBuilder& registerBackKey(char key) = 0;
};


class IKeyDownRegisterBuilder
{
public:
	virtual ~IKeyDownRegisterBuilder() {}
	virtual IKeyBackRegisterBuilder& registerDownKey(char key) = 0;
};


class IKeyUpRegisterBuilder
{
public:
	virtual ~IKeyUpRegisterBuilder() {}
	virtual IKeyDownRegisterBuilder& registerUpKey(char key) = 0;
};