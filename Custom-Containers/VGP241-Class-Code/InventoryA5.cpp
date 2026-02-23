#include "InventoryA5.h"

InventoryA5* InventoryA5::Get()
{
	static InventoryA5 sInstance;
	return &sInstance;
}

void InventoryA5::PickupKey(const std::string& keyName, int amount)
{
	if (!mKeys.Has(keyName))
	{
		KeyItem newKeyItem(keyName);
		mKeys.Insert(keyName, newKeyItem);
	}

	mKeys[keyName].Add(amount);
}

void InventoryA5::UseKey(const std::string& keyName, int amount)
{
	if (!mKeys.Has(keyName))
	{
		return;
	}

	if (mKeys[keyName].GetCount() - amount <= 0)
	{
		mKeys.Remove(keyName);
		return;
	}

	mKeys[keyName].Consume(amount);
}

bool InventoryA5::HasKey(const std::string& keyName) const
{
	return mKeys.Has(keyName);
}

KeyItem InventoryA5::GetKey(const std::string& keyName) const
{
	return mKeys[keyName];
}

void InventoryA5::ObtainAllKeys(Vector <KeyItem>& outKeyItems) const
{
	mKeys.ObtainValues(outKeyItems);
}

void InventoryA5::ClearInventory()
{
	mKeys.Clear();
}