#include "StateSelectionItem.h"


StateSelectionItem::StateSelectionItem(const std::string& itemName)
	: StateSelectionItem(itemName, nullptr)
{

}
StateSelectionItem::StateSelectionItem(const std::string& itemName, IExternalMemory* externalMemory)
	: GeneralItem(itemName), m_currStateNum(0), m_externalMemory(externalMemory)
{

}

StateSelectionItem::~StateSelectionItem() = default;

IStateSelection& StateSelectionItem::addState(const std::string& state)
{
	m_statesList.push_back(state);

	// if there is an external memory, save it
	if (m_externalMemory)
	{
		m_externalMemory->save(std::move(getCurrentState()));
	}

	return *this;
}

int StateSelectionItem::getTotalStatesCount() const
{
	return m_statesList.size();
}

std::string StateSelectionItem::getCurrentState() const
{
	return m_statesList[m_currStateNum];
}

std::string StateSelectionItem::getSuffixName() const
{
	std::stringstream ss;

	ss << "  " << "<" << getCurrentState() << ">";

	return ss.str();
}

void StateSelectionItem::click()
{
	m_currStateNum = (m_currStateNum + 1) % getTotalStatesCount();

	// if there is an external memory, save it
	if (m_externalMemory)
	{
		m_externalMemory->save(std::move(getCurrentState()));
	}
}