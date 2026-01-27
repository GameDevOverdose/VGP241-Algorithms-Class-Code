#pragma once

#include <string>

#include "Vector3.h"

//Switched all the enums to enum class because the variable names were clashing with those of other enums in the project
enum class PickupType {
	Invalid = -1,
	Health,
	Weapon,
	Ammo,
	Coins,
	Upgrade,
	SpecialItem,
	Size
};

class Pickup
{
public:
	Pickup(PickupType pickupType, const Vector3& pos);
	~Pickup();

	PickupType GetType() const { return mType; }
	const std::string& GetName() const { return mName; }
	const Vector3& GetPosition() const { return mPosition; }

private:
	PickupType mType;
	std::string mName;
	Vector3 mPosition;
};