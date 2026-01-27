#include <iostream>
#include <iomanip>
#include "Item.h"

Item::Item()
	: mType(ItemType::SmallHealth)
	, mValue(0)
	, mCount(1)
	, mName("Default Item")
{
}

/*Not entirely sure why the assignment asks the value to be passed in,
  since it would make more sense to just assign it in the switch statement
  depending on what item it is.*/
Item::Item(ItemType itemType, int value)
	: mType(itemType)
	, mValue(value)
	, mCount(1)
{
	switch (mType)
	{
	case ItemType::SmallHealth:
		mName = "Small Health Potion";
		break;
	case ItemType::MedHealth:
		mName = "Medium Health Potion";
		break;
	case ItemType::LightningSpell:
		mName = "Lightning Spell";
		break;
	case ItemType::Grenade:
		mName = "Grenade";
		break;
	default:
		mName = "Unknown Item";
		break;
	}
}

Item::~Item()
{
}

bool Item::operator<(const Item& other) const
{
	return mCount < other.mCount;
}

bool Item::operator>(const Item& other) const
{
	return mCount > other.mCount;
}

void Item::ConsumeItem()
{
	if(mCount > 0)
	{
		--mCount;

		std::string consumedString = mName + " consumed. ";

		std::cout << std::left << std::setw(30) << consumedString << "[" << mCount << " left.]\n";
	}
	else
	{
		std::cout << "No " << mName << " left to consume.\n";
	}
}

void Item::AddItem()
{
	++mCount;

	std::string addedString = mName + " added.";

	//Not necessary at all, but makes the count more readable
	std::cout << std::right << std::setw(29) << addedString << " [" << mCount << "]\n";
}