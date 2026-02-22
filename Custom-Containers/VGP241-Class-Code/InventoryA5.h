#pragma once

#include <string>

#include "Map.h"
#include "KeyItem.h"

class Inventory
{
public:
	static Inventory* Get()
	{
		static Inventory sInstance;
		return &sInstance;
	}

	void PickupKey(const std::string& keyName, int amount)
	{
		std::string keysName;

		if (!mKeys.Has(keyName))
		{
			KeyItem newKeyItem("");

			//mKeys.Insert();
		}
	}

	void UseKey(const std::string& keyName, int amount)
	{

	}

private:
	Map <std::string, KeyItem> mKeys;
};