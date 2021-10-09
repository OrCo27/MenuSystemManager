#pragma once

class IKeyEnterRegisterBuilder
{
public:
	virtual ~IKeyEnterRegisterBuilder() {}

	/*
		Register a key for 'ENTER' operation for controlling the menu and clicking on current item selected
		for performing the relevant operation:
		- Menu Item: move to relevant menu page.
		- Operational Item: perform an custom action that registered to this item.
		- State Item: change the current state belongs to this item.
	*/
	virtual void registerEnterKey(char key) = 0;
};


class IKeyBackRegisterBuilder
{
public:
	virtual ~IKeyBackRegisterBuilder() {}

	/* Register a key for 'BACK' operation for controlling the menu and navigate to previous menu */
	virtual IKeyEnterRegisterBuilder& registerBackKey(char key) = 0;
};


class IKeyDownRegisterBuilder
{
public:
	virtual ~IKeyDownRegisterBuilder() {}

	/* Register a key for 'DOWN' operation for controlling the menu and navigate to lower item */
	virtual IKeyBackRegisterBuilder& registerDownKey(char key) = 0;
};


class IKeyUpRegisterBuilder
{
public:
	virtual ~IKeyUpRegisterBuilder() {}

	/* Register a key for 'UP' operation for controlling the menu and navigate to upper item */
	virtual IKeyDownRegisterBuilder& registerUpKey(char key) = 0;
};