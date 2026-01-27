#pragma once

#include "Vector.h"
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void Initialize(int itemCount = 0);
	void AddItem(ItemType itemType);
	void DisplayInventory() const;

private:
	Vector<Item> mItems;
};