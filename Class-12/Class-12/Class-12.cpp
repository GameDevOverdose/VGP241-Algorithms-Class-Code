#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>

std::chrono::system_clock::time_point gStartTime;

void StartAlgorithm()
{
	gStartTime = std::chrono::system_clock::now();
}

void PrintDuration()
{
	auto endTime = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime).count();
	std::cout << "Duration: " << duration << "\n";
}

int GetIndexLinear(const std::vector<int>& numbers, int target)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] > target)
		{
			break;
		}

		if (numbers[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int GetIndexBinary(const std::vector<int>& numbers, int target)
{
	int low = 0;
	int high = numbers.size() - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) / 2);

		if (numbers[mid] == target)
		{
			return mid;
		}

		if(numbers[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

void Exercise1Algorithm()
{
	std::cout << "Algorithm Analysis:\n\n";

	std::vector <int> numbers;
	int maxNumbers = 50;
	int minValue = -100;
	int maxValue = 100;

	for (int i = 0; i < maxNumbers; ++i)
	{
		int value = minValue + (rand() % ((maxValue + 1) - minValue));
		numbers.push_back(value);
		std::cout << value << " ";
	}

	std::cout << "\n\n";

	std::sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}

	std::cout << "\n\n";

	//int target = 3; // binary won
	//int target = -97; // linear won
	//int target = -17;
	int target = 10;

	StartAlgorithm();
	int linearIndex = GetIndexLinear(numbers, target);
	std::cout << "Target " << target << " is at index (linear): " << linearIndex << "\n";
	PrintDuration();

	StartAlgorithm();
	int binaryIndex = GetIndexBinary(numbers, target);
	std::cout << "\nTarget " << target << " is at index (binary): " << binaryIndex << "\n";
	PrintDuration();

	std::cout << "\n\n";
}

int FindMinDC(const std::vector<int>& numbers, int left, int right)
{
	if (left == right)
	{
		return numbers[left];
	}

	if (left + 1 == right)
	{
		return std::min(numbers[left], numbers[right]);
	}

	int mid = left + ((right - left) / 2);
	int minLeft = FindMinDC(numbers, left, mid);
	int minRight = FindMinDC(numbers, mid + 1, right);

	return std::min(minLeft, minRight);
}

int FindMinLinear(const std::vector<int>& numbers)
{
	int minValue = INT_MAX;

	for (int i = 0; i < numbers.size(); ++i)
	{
		minValue = std::min(minValue, numbers[i]);
	}

	return minValue;
}

void Exercise2DivideAndConquer()
{
	std::cout << "Divide and Conquer:\n\n";

	std::vector <int> numbers;
	int maxNumbers = 20;
	int minValue = 1;
	int maxValue = 100;

	for (int i = 0; i < maxNumbers; ++i)
	{
		int value = minValue + (rand() % ((maxValue + 1) - minValue));
		numbers.push_back(value);
		std::cout << value << " ";
	}

	std::cout << "\n\n";

	StartAlgorithm();
	int value = FindMinDC(numbers, 0, maxNumbers - 1);
	std::cout << "Min Number: " << value << "\n";
	PrintDuration();

	StartAlgorithm();
	value = FindMinLinear(numbers);
	std::cout << "\nMin Number: " << value << "\n";
	PrintDuration();

	std::cout << "\n\n";
}

struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;

	static float Distance(const Vector2& a, const Vector2& b)
	{
		Vector2 dist;
		dist.x = a.x - b.x;
		dist.y = a.y - b.y;

		return std::sqrt((dist.x * dist.x) + (dist.y * dist.y));
	}
};

struct Node
{
	std::string name;
	Vector2 position;

	void Print()
	{
		std::cout << name << " (" << position.x << ", " << position.y << ")\n";
	}
};

struct Edge
{
	int toIndex = -1;
	float weight = 0.0f;

	bool operator<(const Edge& rhs) const { return weight < rhs.weight; }
	bool operator<=(const Edge& rhs) const { return weight <= rhs.weight; }
	bool operator==(const Edge& rhs) const { return weight == rhs.weight; }
	bool operator>(const Edge& rhs) const { return weight > rhs.weight; }
	bool operator>=(const Edge& rhs) const { return weight >= rhs.weight; }
};

void AddNode(std::vector<Node>& nodes, const std::string& name, const Vector2& pos)
{
	Node node;
	node.name = name;
	node.position = pos;
	nodes.push_back(node);
}

void AddEdge(std::vector<std::vector<Edge>>& graph, const std::vector<Node>& nodes, int a, int b)
{
	const Node& aNode = nodes[a];
	const Node& bNode = nodes[b];

	const float distance = Vector2::Distance(aNode.position, bNode.position);
	graph[a].push_back({b, distance});
	graph[b].push_back({a, distance});
}

std::vector<float> Dijkstra(const std::vector<std::vector<Edge>>& graph, int startNode, std::vector <int>& parent)
{
	std::vector<float> dist;
	dist.resize(graph.size(), FLT_MAX);
	parent.resize(graph.size(), -1);
	std::priority_queue<Edge, std::vector<Edge>, std::greater<>> process;

	dist[startNode] = 0;
	parent[startNode] = -1;
	process.push({ startNode, 0.0f });

	while (!process.empty())
	{
		Edge edge = process.top();
		process.pop();

		int curNodeIndex = edge.toIndex;

		if (edge.weight > dist[curNodeIndex])
		{
			continue;
		}

		for (int i = 0; i < graph[curNodeIndex].size(); ++i)
		{
			const Edge toEdge = graph[curNodeIndex][i];

			int toNodeIndex = toEdge.toIndex;
			int toNodeWeight = toEdge.weight;

			if (dist[curNodeIndex] < FLT_MAX && dist[curNodeIndex] + toNodeWeight < dist[toNodeIndex])
			{
				dist[toNodeIndex] = dist[curNodeIndex] + toNodeWeight;
				parent[toNodeIndex] = curNodeIndex;
				process.push({ toNodeIndex, dist[toNodeIndex] });
			}
		}
	}

	return dist;
}

void Exercise3Dijkstra()
{
	std::cout << "Dijkstra Algorithm:\n\n";

	std::vector <Node> nodes;
	std::vector<std::vector<Edge>> graph;

	AddNode(nodes, "A", { 20.0f, 40.0f });
	AddNode(nodes, "B", { 50.0f, 20.0f });
	AddNode(nodes, "C", { 90.0f, 40.0f });
	AddNode(nodes, "D", { 60.0f, 80.0f });
	AddNode(nodes, "E", { 30.0f, 120.0f });
	AddNode(nodes, "F", { 100.0f, 110.0f });
	AddNode(nodes, "G", { 150.0f, 130.0f });
	AddNode(nodes, "H", { 160.0f, 90.0f });
	AddNode(nodes, "I", { 140.0f, 60.0f });
	AddNode(nodes, "J", { 180.0f, 30.0f });
	AddNode(nodes, "K", { 200.0f, 120.0f });
	AddNode(nodes, "L", { 220.0f, 70.0f });
	AddNode(nodes, "M", { 240.0f, 50.0f });

	graph.resize(nodes.size());

	for (int i = 0; i < nodes.size() - 1; ++i)
	{
		for (int j = i + 1; j < nodes.size(); ++j)
		{
			if (Vector2::Distance(nodes[i].position, nodes[j].position) < 75.0f)
			{
				AddEdge(graph, nodes, i, j);
			}
		}
	}

	std::vector <int> parent;
	int startNode = 0;
	std::vector<float> distToNodes = Dijkstra(graph, startNode, parent);

	for (int i = 0; i < distToNodes.size(); ++i)
	{
		std::cout << nodes[startNode].name << " dist to " << nodes[i].name << ": " << distToNodes[i] << "\n";
		int nodeIndex = i;

		while (nodeIndex != -1)
		{
			std::cout << nodes[nodeIndex].name;
			nodeIndex = parent[nodeIndex];

			if (nodeIndex != -1)
			{
				std::cout << "-";
			}
		}
		std::cout << "\n";
	}

	std::cout << "\n\n";
}

void Backtracking(int maxNumber, int maxCombinations, int startValue, std::vector<int>& combination, std::vector<std::vector<int>>& allCombos)
{
	if (combination.size() == maxCombinations)
	{
		allCombos.push_back(combination);
		return;
	}

	for (int i = startValue; i <= maxNumber; ++i)
	{
		combination.push_back(i);
		Backtracking(maxNumber, maxCombinations, i + 1, combination, allCombos);
		combination.pop_back();
	}
}

void Exercise4Backtracking()
{
	std::cout << "Backtrack Algorithm:\n\n";

	int maxNumber = 5;
	int maxCombos = 3;

	std::vector<std::vector<int>> allCombos;
	std::vector<int> combination;

	Backtracking(maxNumber, maxCombos, 1, combination, allCombos);

	for (int i = 0; i < allCombos.size(); ++i)
	{
		for (int j = 0; j < allCombos[i].size(); ++j)
		{
			std::cout << allCombos[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n\n";
}

int main()
{
	// Exercise1Algorithm();
	// Exercise2DivideAndConquer();
	// Exercise3Dijkstra();
	Exercise4Backtracking();
}