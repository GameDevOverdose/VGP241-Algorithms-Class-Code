#include "Pickup.h"

Pickup::Pickup(PickupType pickupType, const Vector3& pos)
{
	mType = pickupType;
	mPosition = pos;

	switch (pickupType)
	{
	case PickupType::Invalid:
		mName = "Invalid Name";
		break;
	case PickupType::Health:
		mName = "Health Pack";
		break;
	case PickupType::Weapon:
		mName = "Weapon";
		break;
	case PickupType::Ammo:
		mName = "Ammunition";
		break;
	case PickupType::Coins:
		mName = "Coins";
		break;
	case PickupType::Upgrade:
		mName = "Upgrade";
		break;
	case PickupType::SpecialItem:
		mName = "Special Item";
		break;
	default:
		break;
	}
}

Pickup::~Pickup()
{

}