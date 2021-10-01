#pragma once

#include <iostream>
#include <vector>
#include "GeneralItem.h"
#include "IStateSelection.h"
#include "IExternalMemory.h"

using std::vector;

template <class T>
class StateSelectionItem : public GeneralItem, public IStateSelection<T>
{
private:
	vector<T> m_statesList;
	int m_currStateNum;
	IExternalMemory<T>* m_externalMemory;

public:
	StateSelectionItem(const std::string& itemName);
	StateSelectionItem(const std::string& itemName, IExternalMemory<T>* externalMemory);
	~StateSelectionItem();
	std::string getSuffixName() const override;
	IStateSelection<T>& addState(const T& state) override;
	T getCurrentState() const;
	int getTotalStatesCount() const;
	void click() override;
};


template <typename T>
StateSelectionItem<T>::StateSelectionItem(const std::string& itemName)
	: StateSelectionItem(itemName, nullptr)
{

}

template <typename T>
StateSelectionItem<T>::StateSelectionItem(const std::string& itemName, IExternalMemory<T>* externalMemory)
	: GeneralItem(itemName), m_currStateNum(0), m_externalMemory(externalMemory)
{

}

template <typename T>
StateSelectionItem<T>::~StateSelectionItem() = default;

template <typename T>
IStateSelection<T>& StateSelectionItem<T>::addState(const T& state)
{
	m_statesList.push_back(state);

	// if there is an external memory, save default state
	if (m_externalMemory)
	{
		m_externalMemory->save(getCurrentState());
	}

	return *this;
}

template <typename T>
int StateSelectionItem<T>::getTotalStatesCount() const
{
	return m_statesList.size();
}

template <typename T>
T StateSelectionItem<T>::getCurrentState() const
{
	return m_statesList[m_currStateNum];
}

template <typename T>
std::string StateSelectionItem<T>::getSuffixName() const
{
	std::stringstream ss;

	ss << "<" << getCurrentState() << ">";

	return ss.str();
}

template <typename T>
void StateSelectionItem<T>::click()
{
	m_currStateNum = (m_currStateNum + 1) % getTotalStatesCount();

	// if there is an external memory, save it
	if (m_externalMemory)
	{
		m_externalMemory->save(getCurrentState());
	}
}