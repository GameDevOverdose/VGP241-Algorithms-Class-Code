#pragma once

#include "Vector.h"
#include "Item.h"

class InventoryA2
{
public:
	InventoryA2();
	~InventoryA2();

	void Initialize(int itemCount = 0);
	void AddItem(ItemType itemType);
	void DisplayInventory() const;

private:
	Vector<Item> mItems;
};