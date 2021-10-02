#pragma once

#include <iostream>
#include "IScreen.h"


class ScreenStub : public IScreen
{
public:
	ScreenStub() {}
	~ScreenStub() = default;

	void clear() const override
	{
		system("cls");
	}

	void setCursor(int row, int col) const override
	{
	}

	void display(const std::string& text) const override
	{
		std::cout << text << std::endl;
	}

	int getTotalCols() const override
	{
		return 14;
	}

	int getTotalRows() const override
	{
		return 4;
	}

	void setup() override
	{
		// initializing screen here
	}
};