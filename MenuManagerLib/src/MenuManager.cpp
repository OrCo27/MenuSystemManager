#include "MenuManager.h"
#include <iomanip>


MenuManager::MenuManager(const IScreen& screen)
	: MenuManager(nullptr, screen)
{
}

MenuManager::MenuManager(Menu* initialMenu, const IScreen& screen)
	: m_screen(screen)
{
	setCurrentMenu(initialMenu);
}

MenuManager::~MenuManager() = default;

Menu* MenuManager::addMenu(Menu* menu)
{
	m_menuList.push_back(shared_ptr<Menu>(menu));
	return menu;
}

GeneralItem* MenuManager::getCurrentItem()
{
	return m_currMenu->getItem(m_currItemNum);
}

void MenuManager::clickCurrentItem()
{
	GeneralItem* currItem = getCurrentItem();
	if (currItem)
	{
		currItem->click();
	}
	else
	{
		// todo: report error
	}
}

void MenuManager::moveToPrevMenu()
{
	Menu* parentMenu = m_currMenu->getParentMenu();
	if (parentMenu)
	{
		setCurrentMenu(parentMenu);
	}
}

void MenuManager::navigateNextItem()
{
	// update current item to the next item in the menu
	if (m_currItemNum < m_currMenu->getTotalItemsCount() - 1)
	{
		m_currItemNum++;

		// move window if it outside the boundary
		if (m_currItemNum >= m_endWindow)
		{
			m_startWindow++;
			m_endWindow++;
		}
	}
}

void MenuManager::navigatePrevItem()
{
	// update current item to the prev item in the menu
	if (m_currItemNum > 0)
	{
		m_currItemNum--;

		// move window if it outside the boundary
		if (m_currItemNum < m_startWindow)
		{
			m_startWindow--;
			m_endWindow--;
		}
	}
}

void MenuManager::setCurrentMenu(Menu* menu)
{
	m_currItemNum = 0;
	m_currMenu = menu;

	m_startWindow = 0;
	m_endWindow = m_screen.getTotalRows() - 1; // -1 for skipping title
}

std::string MenuManager::getFixedName(const std::string& prefix, const std::string& itemName, const std::string& suffix)
{
	std::stringstream ss;
	std::string fixed_item_name;
	int row_width = m_screen.getTotalCols();
	int suffix_size = suffix.size() + 1; // add one for space
	int item_fixed_size = row_width - prefix.size() - suffix_size;
	int prefix_width = row_width - suffix_size;

	if (itemName.size() > item_fixed_size) // out of space
	{
		fixed_item_name = itemName.substr(0, item_fixed_size);
	}
	else
	{
		fixed_item_name = itemName;
	}

	ss << std::left << std::setfill(' ') << std::setw(prefix_width)
		<< prefix + fixed_item_name;

	ss << std::right << std::setfill(' ') << std::setw(suffix_size)
		<< suffix;

	return ss.str();
}

void MenuManager::printMenuName()
{
	std::stringstream suffix;
	std::string fixedTitle;
	int windowSize = m_endWindow - m_startWindow;
	int currentItem, totalItems;

	if (m_currMenu)
	{
		// show current item relative to all items only when there are more items than screen can display
		totalItems = m_currMenu->getTotalItemsCount();
		suffix << "[" << (m_currItemNum + 1) << "/" << totalItems << "]";

		fixedTitle = getFixedName("", m_currMenu->getMenuName(), suffix.str());

		// print on the first row
		m_screen.setCursor(0, 0);
		m_screen.display(fixedTitle);
	}
	else
	{
		// todo: report error
	}
}

void MenuManager::printMenuItem(int itemNum, int rowScreen)
{
	GeneralItem* item = m_currMenu->getItem(itemNum);
	std::stringstream ss;
	std::string fixedItemName;

	if (item)
	{
		// generate prefix
		ss << (m_currItemNum == itemNum ? ">" : " ");
		//ss << (itemNum + 1) << ". ";

		fixedItemName = getFixedName(ss.str(), item->getItemName(), item->getSuffixName());

		m_screen.setCursor(rowScreen, 0);
		m_screen.display(fixedItemName);
	}
	else
	{
		// todo: report error
	}
}

void MenuManager::printMenu()
{
	m_screen.clear();

	printMenuName();

	// ########### print menu items on current window scrolling ###########
	for (int i = m_startWindow, row = 0; i < m_endWindow && i < m_currMenu->getTotalItemsCount(); i++, row++)
	{
		// add 1 to row for skipping the title on the first row
		printMenuItem(i, row + 1); 
	}
}