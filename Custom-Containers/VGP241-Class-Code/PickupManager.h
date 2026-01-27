#pragma once

#include "Vector.h"
#include "KDTree.h"

#include "Pickup.h"

struct FilterPickup
{
	PickupType pickupType;
	Vector3 Center;
	float Radius;

	bool operator()(const void* data)
	{
		const Pickup* pickup = (const Pickup*)data;

		if (Center.DistanceSquared(pickup->GetPosition()) > (Radius * Radius)) { return false; }

		if (pickupType == PickupType::Size) { return true; }

		return pickup->GetType() == pickupType;
	}
};

class PickupManager
{
public:
	~PickupManager();

	static PickupManager& Get();

	void AddItem(PickupType pickupType, const Vector3& pos);
	const Pickup* GetClosestPickup(const Vector3& pos);
	void ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType);

private:
	PickupManager();

	Vector<Pickup*> mPickups;
	KDTree<float, 3> mPickupsTree;
};