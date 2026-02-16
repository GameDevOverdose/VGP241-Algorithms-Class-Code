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

////////////////////////////////   WEEK-5   //////////////////////////////////

void GraphTest()
{
	std::cout << "Graphs and Graph Traversal: \n\n";

	Graph<int> myGraph;
	Vector<int> graphData;

	for (int i = 0; i < 10; ++i)
	{
		graphData.PushBack(i);
	}

	for (int i = 0; i < graphData.Size(); ++i)
	{
		myGraph.AddItem(&graphData[i]);
	}

	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(1, 4);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(5, 9);

	myGraph.PrintGraph();

	Vector<const int*> connectionsDFS;
	Vector<const int*> connectionsBFS;

	myGraph.GetAllConnectionsDFS(0, connectionsDFS);
	myGraph.GetAllConnectionsBFS(0, connectionsBFS);

	std::cout << "\nConnections DFS: \n";

	for (int i = 0; i < connectionsDFS.Size(); i++)
	{
		std::cout << (*connectionsDFS[i]) << " ";
	}

	std::cout << "\n\nConnections BFS: \n";

	for (int i = 0; i < connectionsBFS.Size(); i++)
	{
		std::cout << (*connectionsBFS[i]) << " ";
	}

	Vector <const int*> pathDFS;
	Vector <const int*> pathBFS;

	std::cout << "\n\nPath from 0-9 (DFS): \n";
	myGraph.GetPathDFS(0, 9, pathDFS);

	for (int i = pathDFS.Size() - 1; i >= 0; --i)
	{
		std::cout << (*pathDFS[i]) << " ";
	}

	std::cout << "\n\nPath from 0-9 (BFS): \n";
	myGraph.GetPathBFS(0, 9, pathBFS);

	for (int i = pathBFS.Size() - 1; i >= 0; --i)
	{
		std::cout << (*pathBFS[i]) << " ";
	}

	std::cout << "\n\n";
}

void MapTest()
{
	// Create a city object
	// Add all the cities to a vector
	// Add the cities to the graph and link where applicable
	// Print all the connections
	// Find paths between cities

	// Store all of the cities
	Vector<std::string> cities;

	cities.PushBack("Vancouver");			// 0
	cities.PushBack("Burnaby");				// 1
	cities.PushBack("North_Vancouver");		// 2
	cities.PushBack("Delta");				// 3
	cities.PushBack("Richmond");			// 4
	cities.PushBack("New_West");			// 5
	cities.PushBack("Coquitlam");			// 6
	cities.PushBack("Victoria");			// 7
	cities.PushBack("Nanaimo");				// 8
	cities.PushBack("Quiznel");				// 9
	cities.PushBack("Langley");				// 10
	cities.PushBack("Abbotsford");			// 11
	cities.PushBack("Maple_Ridge");			// 12
	cities.PushBack("Port_Coquitlam");		// 13
	cities.PushBack("Surrey");				// 14

	Graph<std::string> vancouverMap;

	// Add to graph
	for (int i = 0; i < cities.Size(); ++i)
	{
		vancouverMap.AddItem(&cities[i]);
	}

	// Link them
	vancouverMap.AddLink(0, 1);
	vancouverMap.AddLink(0, 2);
	vancouverMap.AddLink(0, 4);
	vancouverMap.AddLink(1, 2);
	vancouverMap.AddLink(1, 14);
	vancouverMap.AddLink(1, 5);
	vancouverMap.AddLink(1, 6);
	vancouverMap.AddLink(3, 4);
	vancouverMap.AddLink(3, 14);
	vancouverMap.AddLink(4, 14);
	vancouverMap.AddLink(4, 5);
	vancouverMap.AddLink(5, 14);
	vancouverMap.AddLink(6, 13);
	vancouverMap.AddLink(6, 12);
	vancouverMap.AddLink(7, 9);
	vancouverMap.AddLink(8, 9);
	vancouverMap.AddLink(10, 14);
	vancouverMap.AddLink(10, 11);
	vancouverMap.AddLink(11, 12);

	std::cout << "Connected Cities of Greater Vancouver: \n\n";

	vancouverMap.PrintGraph();

	int startingIndex = 0;

	Vector<const std::string*> connectionsDFS;
	Vector<const std::string*> connectionsBFS;

	vancouverMap.GetAllConnectionsDFS(startingIndex, connectionsDFS);
	vancouverMap.GetAllConnectionsBFS(startingIndex, connectionsBFS);

	std::cout << "\n\nCities Connected To " << cities[startingIndex] << " (DFS)\n";

	for (int i = 0; i < connectionsDFS.Size(); i++)
	{
		std::cout << (*connectionsDFS[i]) << " ";
	}

	std::cout << "\nCities Connected To " << cities[startingIndex] << " (BFS)\n";

	for (int i = 0; i < connectionsBFS.Size(); i++)
	{
		std::cout << (*connectionsBFS[i]) << " ";
	}

	int islandStartingIndex = 7;

	connectionsDFS.Clear();
	connectionsBFS.Clear();

	vancouverMap.GetAllConnectionsDFS(islandStartingIndex, connectionsDFS);
	vancouverMap.GetAllConnectionsBFS(islandStartingIndex, connectionsBFS);

	std::cout << "\nCities Connected To " << cities[islandStartingIndex] << " (DFS)\n";

	for (int i = 0; i < connectionsDFS.Size(); i++)
	{
		std::cout << (*connectionsDFS[i]) << " ";
	}

	std::cout << "\n\nCities Connected To " << cities[islandStartingIndex] << " (BFS)\n";

	for (int i = 0; i < connectionsBFS.Size(); i++)
	{
		std::cout << (*connectionsBFS[i]) << " ";
	}

	int startIndex = 0;
	int endIndex = 7;

	Vector<const std::string*> cityRoute;

	std::cout << "\n\nGetting Path From " << cities[startIndex] << " to " << cities[endIndex] << " (DFS)\n";

	if (vancouverMap.GetPathDFS(startIndex, endIndex, cityRoute))
	{
		for (int i = cityRoute.Size() - 1; i >= 0; --i)
		{
			std::cout << (*cityRoute[i]) << " ";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Path was not found\n";
	}

	cityRoute.Clear();

	std::cout << "\nGetting Path From " << cities[startIndex] << " to " << cities[endIndex] << " (BFS)\n";

	if (vancouverMap.GetPathBFS(startIndex, endIndex, cityRoute))
	{
		for (int i = cityRoute.Size() - 1; i >= 0; --i)
		{
			std::cout << (*cityRoute[i]) << " ";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Path was not found\n";
	}

	std::cout << "\n\n";

}

struct Tile
{
	int x = 0;
	int y = 0;

	//Used after doing pathfinding
	bool isInPath = false;
	
	void Draw() const
	{
		if (isInPath)
		{
			std::cout << "[0] ";
		}
		else
		{
			std::cout << "[ ] ";
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Tile& t)
	{
		os << t.x << "_" << t.y;
		return os;
	}
};

void ClearTileMap(Vector<Tile>& tileMap)
{
	for (int i = 0; i < tileMap.Size(); i++)
	{
		tileMap[i].isInPath = false;
	}
}

void DrawTileMap(int width, int height, const Vector<Tile>& tileMap)
{
	//Draw the map with number outlines
	//Need extra line to display coordinates
	//Draw top row indices
	std::cout << "\n    ";

	for (int w = 0; w < width; ++w)
	{
		if (w <= 9)
		{
			std::cout << "0" << w << "  ";
		}
		else
		{
			std::cout << w << "  ";
		}
	}

	std::cout << "\n";

	for (int h = 0; h < height; ++h)
	{
		if (h <= 9)
		{
			std::cout << "0" << h << " ";
		}
		else
		{
			std::cout << h << " ";
		}

		for (int w = 0; w < width; ++w)
		{
			int index = w + (h * width);
			tileMap[index].Draw();
		}

		std::cout << "\n";
	}
}

void TileMapTest()
{
	Vector<Tile> tileMap;
	Graph<Tile> tileMapGraph;

	std::string input;

	bool isDone = false;

	int width = 0;
	int height = 0;

	std::cout << "Enter Map Width (1-99): ";
	std::cin >> width;

	std::cout << "Enter Map Height (1-99): ";
	std::cin >> height;

	tileMapGraph.Terminate();
	tileMap.Clear();

	tileMap.Resize(width * height);

	//Add the tile to the graph like a navmesh
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = x + (y * width);

			tileMap[index].x = x;
			tileMap[index].y = y;
		}
	}
	//Adding all the tiles to the graph
	for (int i = 0; i < tileMap.Size(); ++i)
	{
		tileMapGraph.AddItem(&tileMap[i]);
	}

	//Set up links
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int currentIndex = x + (y * width);

			if (x + 1 < width)
			{
				int rightIndex = (x + 1) + (y * width);
				tileMapGraph.AddLink(currentIndex, rightIndex);
			}

			if (y + 1 < height)
			{
				int downIndex = x + ((y + 1) * width);
				tileMapGraph.AddLink(currentIndex, downIndex);
			}
		}
	}

	while (!isDone)
	{
		system("cls");
		std::cout << "Tile Map:\n";
		ClearTileMap(tileMap);
		DrawTileMap(width, height, tileMap);

		int startX = 0;
		int startY = 0;
		int endX = 0;
		int endY = 0;

		std::cout << "\nEnter Start X: ";
		std::cin >> startX;

		std::cout << "Enter Start Y: ";
		std::cin >> startY;

		std::cout << "Enter End X: ";
		std::cin >> endX;

		std::cout << "Enter End Y: ";
		std::cin >> endY;

		system("cls");

		if (startX > width || endX > width || startY > height || endY > height)
		{
			break;
		}

		std::cout << "Path from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ") (DFS): \n\n";

		int startIndex = startX + (startY * width);
		int endIndex = endX + (endY * width);

		Vector<const Tile*> path;

		if (tileMapGraph.GetPathDFS(startIndex, endIndex, path))
		{
			for (int i = 0; i < path.Size(); ++i)
			{
				int index = path[i]->x + (path[i]->y * width);
				tileMap[index].isInPath = true;
			}
		}

		DrawTileMap(width, height, tileMap);

		std::cout << "\nNext (BFS): ";
		std::cin >> input;

		if (input == "no")
		{
			break;
		}

		std::cout << "\nPath from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ") (BFS): \n\n";

		path.Clear();
		ClearTileMap(tileMap);

		if (tileMapGraph.GetPathBFS(startIndex, endIndex, path))
		{
			for (int i = 0; i < path.Size(); ++i)
			{
				int index = path[i]->x + (path[i]->y * width);
				tileMap[index].isInPath = true;
			}
		}

		DrawTileMap(width, height, tileMap);

		std::cout << "\nRetry: ";
		std::cin >> input;

		if (input == "no")
		{
			break;
		}
	}
}

////////////////////////////////   WEEK-7   //////////////////////////////////

void UnorderedMapTest()
{
	UnorderedMap<std::string, int> myCarPrices;

	myCarPrices.Insert("Ford", 10000);
	myCarPrices.Insert("Chevy", 25000);
	myCarPrices["Dodge"] = 30000;
	myCarPrices["BMW"] = 100000;

	std::cout << "Price of Ford " << myCarPrices["Ford"] << "\n";
	std::cout << "Price of Chevy " << myCarPrices["Chevy"] << "\n";
	std::cout << "Price of Dodge " << myCarPrices["Dodge"] << "\n";
	std::cout << "Price of BMW " << myCarPrices["BMW"] << "\n";

	std::cout << "Number of Cars " << myCarPrices.Count() << "\n";

	myCarPrices.Remove("Ford");

	std::cout << "Has Ford " << myCarPrices.Has("Ford") << "\n";
	std::cout << "Number of Cars " << myCarPrices.Count() << "\n";
	std::cout << "Price of Ford " << myCarPrices["Ford"] << "\n";
	std::cout << "Number of Cars " << myCarPrices.Count() << "\n";

	std::cout << "Hash Values: \n";

	std::cout << "RAT: " << Globals::HashFunction("RAT") << "\n";
	std::cout << "TAR: " << Globals::HashFunction("TAR") << "\n";
	std::cout << "Ford: " << Globals::HashFunction("Ford") << "\n";
	std::cout << "Chevy: " << Globals::HashFunction("Chevy") << "\n";
	std::cout << "Dodge: " << Globals::HashFunction("Dodge") << "\n";
}