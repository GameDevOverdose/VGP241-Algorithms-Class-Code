#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"

#include "InventoryA2.h"

InventoryA2::InventoryA2()
{
}

InventoryA2::~InventoryA2()
{
}

void InventoryA2::Initialize(int itemCount)
{
	mItems.Clear();

	//Not a system that would be used in a real game, but good enough for demonstration and populating the inventory
	for (int i = 0; i < itemCount; ++i)
	{
		int randomItemTypeIndex = rand() % ((int)ItemType::Size);
		ItemType itemToAddType = static_cast<ItemType>(randomItemTypeIndex);
		AddItem(itemToAddType);
	}
}

void InventoryA2::AddItem(ItemType itemType)
{
	int indexToUpdate = -1;

	for (int i = 0; i < mItems.Size(); i++)
	{
		if (mItems[i].GetType() == itemType)
		{
			indexToUpdate = i;
			break;
		}
	}

	if (indexToUpdate == -1)
	{
		//Just setting a random item value for assignment purposes
		Item itemToAdd(itemType, ((rand() % 11) - 5));
		mItems.PushBack(itemToAdd);
	}
	else
	{
		mItems[indexToUpdate].AddItem();
	}
}

void InventoryA2::DisplayInventory() const
{
	PriorityQueue<Item> sortedItems;

	for (int i = 0; i < mItems.Size(); i++)
	{
		Item item = mItems[i];
		sortedItems.Push(item);
	}

	std::cout << "\nInventory Items:\n";
	std::cout << "----------------\n\n";
	for (std::size_t i = 0; i < mItems.Size(); ++i)
	{
		std::string inventoryString = std::string("Item ") + std::to_string(i + 1) + ": " + sortedItems.Top().GetName();


		std::cout << std::left << std::setw(29) << inventoryString << " [" << sortedItems.Top().GetCount() << "]" << "\n";
		sortedItems.Pop();
	}
}