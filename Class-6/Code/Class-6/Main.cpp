#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void DFSRecursive(const std::vector<std::vector<int>>& graph, std::stack<int> process, std::vector<bool>& visited)
{
	if (process.empty())
	{
		return;
	}

	int node = process.top();
	process.pop();

	if (!visited[node])
	{
		visited[node] = true;
		std::cout << node << " ";

		for (int i = 0; i < graph[node].size(); ++i)
		{
			if (!visited[graph[node][i]])
			{
				process.push(graph[node][i]);
			}
		}
	}

	DFSRecursive(graph, process, visited);
}

void DepthFirstSearchRecursive(const std::vector<std::vector<int>>& graph, int startNode)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "\nDFS Recursive: \n";

	std::stack<int> process;
	process.push(startNode);
	DFSRecursive(graph, process, visited);
}

void DepthFirstSearch(const std::vector <std::vector<int>>& graph, int startNode)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "\nDFS Search: \n";

	//Depth first uses stack LIFO
	std::stack<int> process;
	process.push(startNode);

	while (!process.empty())
	{
		int node = process.top();
		process.pop();

		if (!visited[node])
		{
			visited[node] = true;
			std::cout << node << " ";

			for (int i = 0; i < graph[node].size(); ++i)
			{
				if (!visited[graph[node][i]])
				{
					process.push(graph[node][i]);
				}
			}
		}
	}
}

void CheckNodeConnectionDFS(const std::vector<std::vector<int>>& graph, int startNode, int endNode)
{
	//Data to confirm if connection is made
	bool hasConnection = false;
	std::vector <int> connectedNodes;

	//DFS Data
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "Checking if these nodes connect (DFS): (" << startNode << ", " << endNode << ")\n";

	std::stack<int>process;
	process.push(startNode);

	while (!process.empty())
	{
		int node = process.top();
		process.pop();

		if (!visited[node])
		{
			visited[node] = true;
			connectedNodes.push_back(node);

			if (node == endNode)
			{
				hasConnection = true;
				break;
			}

			for (int i = 0; i < graph[node].size(); ++i)
			{
				if (!visited[graph[node][i]])
				{
					process.push(graph[node][i]);
				}
			}
		}
	}

	if (hasConnection)
	{
		std::cout << "Connection was made: \n";

		for (int i = 0; i < connectedNodes.size(); ++i)
		{
			std::cout << connectedNodes[i] << " ";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Links do not connect!\n";
	}
}

void BFSRecursive(const std::vector<std::vector<int>>& graph, std::queue<int>& process, std::vector<bool>& visited)
{
	if (process.empty())
	{
		return;
	}

	int node = process.front();
	process.pop();

	if (!visited[node])
	{
		visited[node] = true;
		std::cout << node << " ";

		for (int i = 0; i < graph[node].size(); ++i)
		{
			if (!visited[graph[node][i]])
			{
				process.push(graph[node][i]);
			}
		}
	}

	BFSRecursive(graph, process, visited);
}

void BreadthFirstSearchRecursive(const std::vector<std::vector<int>>& graph, int startNode)
{
	std::vector<bool> visited;
	visited.resize(graph.size());

	std::cout << "\nBreadth First Recursive: \n";

	std::queue<int> process;
	process.push(startNode);
	BFSRecursive(graph, process, visited);
}

void BreadthFirstSearch(const std::vector<std::vector<int>>& graph, int startNode)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "\nBreadth First Search: \n";

	//Breadth first uses queue FIFO
	std::queue<int> process;
	process.push(startNode);
	
	while (!process.empty())
	{
		int node = process.front();
		process.pop();

		if (!visited[node])
		{
			visited[node] = true;
			std::cout << node << " ";

			for (int i = 0; i < graph[node].size(); ++i)
			{
				if (!visited[graph[node][i]])
				{
					process.push(graph[node][i]);
				}
			}
		}
	}
}

void CheckNodeConnectionBFS(const std::vector <std::vector<int>>& graph, int startNode, int endNode)
{
	//Connection Check
	bool hasConnection = false;
	std::vector <int> connectedNodes;

	std::cout << "Checking if these nodes connect (BFS): (" << startNode << ", " << endNode << ")\n";

	//BFS Algorithm
	std::vector <bool> visited;
	visited.resize(graph.size(), false);

	std::queue<int> process;
	process.push(startNode);

	while (!process.empty())
	{
		int node = process.front();
		process.pop();

		if (!visited[node])
		{
			visited[node] = true;
			connectedNodes.push_back(node);

			if (node == endNode)
			{
				hasConnection = true;
				break;
			}
			
			for (int i = 0; i < graph[node].size(); i++)
			{
				if (!visited[graph[node][i]])
				{
					process.push(graph[node][i]);
				}
			}
		}
	}

	if (hasConnection)
	{
		std::cout << "Connection was made: \n";

		for (int i = 0; i < connectedNodes.size(); ++i)
		{
			std::cout << connectedNodes[i] << " ";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Links do not connect!\n";
	}
}

int main()
{
	std::cout << "Graph Traversal\n";

	int numNodes = 0;

	std::cout << "Input Number of Nodes: ";
	std::cin >> numNodes;

	//Store as an adjacency list
	std::vector <std::vector<int>> adjacencyList;
	adjacencyList.resize(numNodes);

	int inputStart = 0;
	int inputEnd = 0;

	std::cout << "\nBuilding Graph\n\n";

	while (true)
	{
		std::cout << "Enter Start Node Index: ";
		std::cin >> inputStart;

		if (inputStart < 0 || inputStart >= numNodes)
		{
			break;
		}

		std::cout << "Enter End Node Index: ";
		std::cin >> inputEnd;

		if (inputEnd < 0 || inputEnd >= numNodes)
		{
			break;
		}

		auto iter = std::find(adjacencyList[inputStart].begin(), adjacencyList[inputStart].end(), inputEnd);
		
		if (iter == adjacencyList[inputStart].end())
		{
			adjacencyList[inputStart].push_back(inputEnd);
		}

		iter = std::find(adjacencyList[inputEnd].begin(), adjacencyList[inputEnd].end(), inputStart);

		// If one way graph, exclude this, right now links go both ways
		if (iter == adjacencyList[inputEnd].end())
		{
			adjacencyList[inputEnd].push_back(inputStart);
		}
	}

	system("cls");

	std::cout << "Print out Adjacent List: \n";

	for (int s = 0; s < numNodes; ++s)
	{
		std::cout << s << ": { ";

		for (int e = 0; e < adjacencyList[s].size(); ++e)
		{
			std::cout << adjacencyList[s][e] << " ";
		}

		std::cout << "}\n";
	}

	int startNode = 0;

	std::cout << "\n\nEnter Node To Start: ";
	std::cin >> startNode;

	DepthFirstSearch(adjacencyList, startNode);
	DepthFirstSearchRecursive(adjacencyList, startNode);
	BreadthFirstSearch(adjacencyList, startNode);
	BreadthFirstSearchRecursive(adjacencyList, startNode);

	int endNode = 0;

	std::cout << "\n\nEnter Node To Check Connection: ";
	std::cin >> endNode;

	CheckNodeConnectionDFS(adjacencyList, startNode, endNode);
	CheckNodeConnectionBFS(adjacencyList, startNode, endNode);
}