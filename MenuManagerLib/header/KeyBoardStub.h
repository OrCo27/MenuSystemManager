#pragma once

#include "IKeyBoard.h"
#include <iostream>
#include <conio.h>

class KeyBoardStub : public IKeyBoard
{
public:
	KeyBoardStub() {}
	~KeyBoardStub() = default;

	char readKey() const override
	{
		char ch = getch();
		return ch;
	}

	void setup() override
	{
		// initializing keyboard here
	}
};