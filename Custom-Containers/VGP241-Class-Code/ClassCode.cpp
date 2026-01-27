#include "ClassCode.h"

////////////////////////////////   WEEK-1   //////////////////////////////////

void CustomContainersTest()
{
	Array <int, 5> myInts(0);

	std::cout << "Array:\n";
	for (std::size_t i = 0; i < myInts.Size(); ++i)
	{
		myInts[i] = i + 1;
		std::cout << "Value at " << i << " is: " << myInts[i] << "\n";
	}

	Vector <int> myVector;

	myVector.Reserve(10);

	std::cout << "\nVector:\n";
	for (std::size_t i = 0; i < 10; ++i)
	{
		myVector.PushBack(i + 1);
		std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
	}

	myVector.Resize(5);

	std::cout << "\nVector Resize:\n";
	for (std::size_t i = 0; i < myVector.Size(); ++i)
	{
		std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
	}
}

////////////////////////////////   WEEK-2   //////////////////////////////////

void IteratorTest()
{
	Array<int, 10> myInts;

	for (int i = 0; i < 10; ++i)
	{
		myInts[i] = rand() % 100;
	}

	for (Array<int, 10>::Iterator iter = myInts.Begin(); iter != myInts.End(); ++iter)
	{
		std::cout << "Array Value: " << *iter << "\n";
	}

	std::sort(myInts.Begin(), myInts.End());
	std::cout << "\n";

	for (Array<int, 10>::Iterator iter = myInts.Begin(); iter != myInts.End(); ++iter)
	{
		std::cout << "Sorted Array Value: " << *iter << "\n";
	}
}

void PriorityQueueTest()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	PriorityQueue<int> priorityQueue;

	for (int i = 0; i < 20; i++)
	{
		int value = rand() % 100;
		priorityQueue.Push(value);
		std::cout << "Pushed Value: " << value << "\n";
	}

	std::cout << "\n";

	while (!priorityQueue.Empty())
	{
		std::cout << "Sorted Value: " << priorityQueue.Top() << "\n";
		priorityQueue.Pop();
	}
}

////////////////////////////////   WEEK-3   //////////////////////////////////

enum class ItemType
{
	IT_HEALTH,
	IT_WELLNESS,
	IT_MONEY,
	IT_COUNT
};

struct sItem
{
	std::string name;
	ItemType itemType;
	Vector2 position;
};

struct FilterByType
{
	ItemType itemType;

	bool operator()(const void* data)
	{
		const sItem* item = (const sItem*)data;
		return item->itemType == itemType;
	}
};

void KDTreeTest()
{
	Vector<sItem> items;

	KDTree<float, 2> itemLocations;
	int maxItems = 100;
	items.Resize(maxItems);

	for (int i = 0; i < maxItems; ++i)
	{
		items[i].name = "Item Name" + std::to_string(i);
		items[i].itemType = (ItemType)(i % ((int)ItemType::IT_COUNT));

		switch (items[i].itemType)
		{
		case ItemType::IT_HEALTH: items[i].name += " (Health)"; break;
		case ItemType::IT_WELLNESS: items[i].name += " (Wellness)"; break;
		case ItemType::IT_MONEY: items[i].name += " (Money)"; break;
		default:
			break;
		}

		items[i].position = { (float)(rand() % 501), (float)(rand() % 501) };

		itemLocations.AddItem(&items[i].position.x, &items[i]);
	}

	//Must build tree first
	itemLocations.BuildTree();

	Vector2 minRange = { 200.0f, 200.0f };
	Vector2 maxRange = { 300.0f, 300.0f };
	Vector<const void*> itemsInRange;

	FilterByType filterCallback;
	filterCallback.itemType = ItemType::IT_MONEY;

	itemLocations.FindInRange(itemsInRange, &minRange.x, &maxRange.x, filterCallback);

	for (Vector<const void*>::Iterator iter = itemsInRange.Begin(); iter != itemsInRange.End(); ++iter)
	{
		const sItem* item = (const sItem*)(*iter);
		std::cout << "Item in Range: " << item->name << "(" << item->position.x << ", " << item->position.y << ")\n";
	}

	std::cout << "\n\n";

	Vector2 targetPos = { 450.0f, 210.0f };
	const sItem* foundTarget = (const sItem*)itemLocations.FindNearest(&targetPos.x);
	std::cout << "Closest Target: " << foundTarget->name << "(" << foundTarget->position.x << ", " << foundTarget->position.y << ")\n";
}