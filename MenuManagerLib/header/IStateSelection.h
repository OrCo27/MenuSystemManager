#pragma once

template <class T>
class IStateSelection 
{
public:
	virtual ~IStateSelection() {}

	/* Add a new state to the collection */
	virtual IStateSelection<T>& addState(const T& state) = 0;
};