#include "Assignment-3.h"

#include "PickupManager.h"

void Assignment3()
{
	int numberOfPickups = 100;
	int positionalRange = 100;

	Vector3 player(rand() % positionalRange, rand() % positionalRange, rand() % positionalRange);
	float allAttractRange = 10.0f;
	float healthAttractRange = 50.0f;

	std::cout << "Player Position: (" << player.x << ", " << player.y << ", " << player.z << ")\n\n";

	for (int i = 0; i < numberOfPickups; i++)
	{
		PickupType randomItemType = (PickupType)(rand() % ((int)PickupType::Size));
		Vector3 randomPosition(rand() % positionalRange, rand() % positionalRange, rand() % positionalRange);

		PickupManager::Get().AddItem(randomItemType, randomPosition);
	}

	//NOTE: THE FIRST ONE DOESN'T ALWAYS PRINT SINCE 10 IS TOO SMALL OF A RANGE MOST TIMES
	//(CAN EITHER INCREASE THE ALL ATTRACT RANGE OR DECREASE THE POSITIONAL RANGE)
	
	//(1) Get closest pickups to player
	std::cout << "Closest Pickups to Player" << " (Range " << allAttractRange << "):" << "\n\n";

	PickupManager::Get().ObtainPickupsInRange(player, allAttractRange, PickupType::Size);

	//(2) Get only Health pickups in range
	std::cout << "\nHealth Pickups near Player" << " (Range " << healthAttractRange << "):" << "\n\n";

	PickupManager::Get().ObtainPickupsInRange(player, healthAttractRange, PickupType::Health);

	//(3) Find the closest pickup
	std::cout << "\nPickup nearest to the Player: ";
	
	PickupManager::Get().GetClosestPickup(player);
}