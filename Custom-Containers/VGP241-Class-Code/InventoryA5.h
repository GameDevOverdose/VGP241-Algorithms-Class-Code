#pragma once

#include <string>

#include "Map.h"
#include "KeyItem.h"

class InventoryA5
{
public:
	static InventoryA5* Get();

	void PickupKey(const std::string& keyName, int amount);

	void UseKey(const std::string& keyName, int amount);

	bool HasKey(const std::string& keyName) const;

	KeyItem GetKey(const std::string& keyName) const;

	void ObtainAllKeys(Vector <KeyItem>& outKeyItems) const;

	void ClearInventory();

private:
	Map <std::string, KeyItem> mKeys;
};