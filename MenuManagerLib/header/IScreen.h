#pragma once

#include "IExternalDevice.h"

class IScreen : public IExternalDevice
{
public:
	virtual ~IScreen() {}

	/* Clear current display */
	virtual void clear() const = 0;

	/* Change the cursor to specific coordinate */
	virtual void setCursor(int row, int col) const = 0;

	/* Display the current text into the screen */
	virtual void display(const std::string& text) const = 0;

	/* Get the total columns limit of curren screen */
	virtual int getTotalCols() const = 0;

	/* Get the total rows limit of curren screen */
	virtual int getTotalRows() const = 0;

	/* Setup and initialize the connection of an external screen */
	virtual void setup() = 0;
};