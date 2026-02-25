#include "Assignment-5.h"
#include "InventoryA5.h"

void PopulateKeyNames(Vector <std::string>& keyNames)
{
	keyNames.PushBack("Red Key");
	keyNames.PushBack("Blue Key");
	keyNames.PushBack("Green Key");
	keyNames.PushBack("Yellow Key");
	keyNames.PushBack("Purple Key");
	keyNames.PushBack("Orange Key");
	keyNames.PushBack("Silver Key");
	keyNames.PushBack("Golden Key");
	keyNames.PushBack("Bronze Key");
	keyNames.PushBack("Crystal Key");
	keyNames.PushBack("Shadow Key");
	keyNames.PushBack("Flame Key");
	keyNames.PushBack("Frost Key");
	keyNames.PushBack("Storm Key");
	keyNames.PushBack("Earth Key");
	keyNames.PushBack("Wind Key");
	keyNames.PushBack("Ocean Key");
	keyNames.PushBack("Obsidian Key");
	keyNames.PushBack("Ivory Key");
	keyNames.PushBack("Emerald Key");
}

void PrintAllKeys(InventoryA5* inventory)
{
	Vector<KeyItem> allKeys;
	inventory->ObtainAllKeys(allKeys);

	std::cout << "----------------------------\n";

	for (int i = 0; i < allKeys.Size(); ++i)
	{
		allKeys[i].Print(true);
		std::cout << "\n";
	}

	std::cout << "----------------------------\n";
}

void Assignment5()
{
	InventoryA5* inventory = InventoryA5::Get();
	Vector <std::string> keyNames;

	inventory->ClearInventory();

	PopulateKeyNames(keyNames);

	for (int i = 0; i < 100; ++i)
	{
		int randIndex = rand() % keyNames.Size();
		inventory->PickupKey(keyNames[randIndex], 1);
	}

	PrintAllKeys(inventory);

	std::string input;
	int doorsUnlockedCount = 0;
	int lockedDoorEncounteredCount = 0;

	// Clear if needed (just to test)
	//inventory->ClearInventory();

	while (input != "Exit" && input != "exit")
	{
		std::cout << "\nOpen Door, Pickup Key or Exit? [Open, Pickup, Exit]: ";
		std::cin >> input;

		system("cls");

		PrintAllKeys(inventory);
		std::cout << "\n";

		int randIndex = rand() % keyNames.Size();
		std::string keyName = keyNames[randIndex];

		if (input == "Open" || input == "open")
		{
			std::cout << "You arrived at a door, you need the " << keyName << "\n";

			if (inventory->HasKey(keyName))
			{
				std::cout << "You have the " << keyName << " and have unlocked the door.";
				inventory->UseKey(keyName, 1);

				doorsUnlockedCount++;
			}
			else
			{
				std::cout << "You don't have the " << keyName << " and the door remains locked.";

				lockedDoorEncounteredCount++;
			}
		}
		else if (input == "Pickup" || input == "pickup")
		{
			inventory->PickupKey(keyNames[randIndex], 1);
			std::cout << "You picked up " << keyName << ": ";
			inventory->GetKey(keyName).Print(false);
		}

		std::cout << "\n";
	}

	system("cls");

	std::cout << "\n\tENDING STATS:\n";

	PrintAllKeys(inventory);

	std::cout << "\nTotal doors unlocked: " << doorsUnlockedCount;
	std::cout << "\nLocked doors encountered: " << lockedDoorEncounteredCount;

	std::cout << "\n";
}