#include "PickupManager.h"

PickupManager& PickupManager::Get()
{
	static PickupManager instance;
	return instance;
}

PickupManager::PickupManager()
{

}

PickupManager::~PickupManager()
{

}

void PickupManager::AddItem(PickupType pickupType, const Vector3& pos)
{
	Pickup* pickupToStore = new Pickup(pickupType, pos);
	Vector3 position = pos;

	mPickups.PushBack(pickupToStore);
	mPickupsTree.AddItem(&pickupToStore->GetPosition().x, pickupToStore);
}

const Pickup* PickupManager::GetClosestPickup(const Vector3& pos)
{
	mPickupsTree.BuildTree();

	const Pickup* nearestPickup = (const Pickup*)mPickupsTree.FindNearest(&pos.x);

	std::cout << nearestPickup->GetName() << "(" << nearestPickup->GetPosition().x << ", " << nearestPickup->GetPosition().y << ", " << nearestPickup->GetPosition().z << ")\n";

	return nearestPickup;
}

void PickupManager::ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType)
{
	mPickupsTree.BuildTree();

	Vector<const void*> pickupsInRange;

	Vector3 minRange (pos.x - range, pos.y - range, pos.z - range);
	Vector3 maxRange (pos.x + range, pos.y + range, pos.z + range);

	FilterPickup filterCallback;
	filterCallback.pickupType = pickupType;
	filterCallback.Center = pos;
	filterCallback.Radius = range;

	mPickupsTree.FindInRange(pickupsInRange, &minRange.x, &maxRange.x, filterCallback);

	int count = 1;

	for (Vector<const void*>::Iterator iter = pickupsInRange.Begin(); iter != pickupsInRange.End(); ++iter)
	{
		const Pickup* pickup = (const Pickup*)(*iter);
		std::cout << "Pickup in Range " << "(" << count << ")" << ": " << pickup->GetName() << "(" << pickup->GetPosition().x << ", " << pickup->GetPosition().y << ", " << pickup->GetPosition().z << ")\n";

		count++;
	}
}