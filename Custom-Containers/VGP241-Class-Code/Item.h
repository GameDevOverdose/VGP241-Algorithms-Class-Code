#pragma once

#include <string>

enum class ItemType
{
	SmallHealth = 0,
	MedHealth,
	LightningSpell,
	Grenade,
	Size
};

class Item
{
public:
	Item();
	Item(ItemType itemType, int value);
	~Item();

	bool operator<(const Item& other) const;
	bool operator>(const Item& other) const;

	void ConsumeItem();
	void AddItem();

	std::string GetName() const { return mName; }
	ItemType GetType() const { return mType; }
	int GetValue() const { return mValue; }
	int GetCount() const { return mCount; }

private:
	ItemType mType;
	std::string mName;

	int mValue;
	int mCount;
};