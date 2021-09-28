#pragma once

#include <iostream>
#include <vector>
#include "GeneralItem.h"
#include "IStateSelection.h"
#include "IExternalMemory.h"

using std::vector;

class StateSelectionItem : public GeneralItem, public IStateSelection
{
private:
	vector<std::string> m_statesList;
	int m_currStateNum;
	IExternalMemory* m_externalMemory;

public:
	StateSelectionItem(const std::string& itemName);
	StateSelectionItem(const std::string& itemName, IExternalMemory* externalMemory);
	~StateSelectionItem();
	std::string getSuffixName() const override;
	IStateSelection& addState(const std::string& state) override;
	std::string getCurrentState() const;
	int getTotalStatesCount() const;
	void click() override;
};