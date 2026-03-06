#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct Node
{
    int nodeIndex = -1;
    int weight = 0;
};

struct Edge
{
    int nodeIndex = -1;
    int linkedNodeIndex = -1;
    int weight = 0;
};

class DisjointSetUnion
{
public:
    DisjointSetUnion(int numNodes)
    {
        mParent.resize(numNodes);
        mRank.resize(numNodes, 0);

        for (int i = 0; i < numNodes; ++i)
        {
            mParent[i] = i;
        }
    }

    int FindParentIndex(int nodeIndex)
    {
        if (mParent[nodeIndex] != nodeIndex)
        {
            mParent[nodeIndex] = FindParentIndex(mParent[nodeIndex]);
        }

        return mParent[nodeIndex];
    }

    bool UniteEdges(int start, int end)
    {
        int rootStart = FindParentIndex(start);
        int rootEnd = FindParentIndex(end);

        if (rootStart == rootEnd)
        {
            return false;
        }

        if (mRank[rootStart] < mRank[rootEnd])
        {
            mParent[rootStart] = rootEnd;
        }
        else if (mRank[rootStart] > mRank[rootEnd])
        {
            mParent[rootEnd] = rootStart;
        }
        else
        {
            mParent[rootEnd] = rootStart;
            ++mRank[rootStart];
        }

        return true;
    }

private:
    std::vector<int> mParent;
    std::vector<int> mRank;
};

std::vector<Edge> KruskalAlgorithm(std::vector<Edge>& edges, int numNodes)
{
    std::cout << "\nKruskal's Algorithm:\n";
    int totalWeight = 0;

    std::vector<Edge> mst;
    DisjointSetUnion dsu(numNodes);

    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.weight < b.weight; });

    for (Edge& edge : edges)
    {
        if (dsu.UniteEdges(edge.nodeIndex, edge.linkedNodeIndex))
        {
            mst.push_back(edge);

            std::cout << edge.nodeIndex << "-" << edge.linkedNodeIndex << " ";
            totalWeight += edge.weight;

            if (mst.size() == numNodes - 1)
            {
                break;
            }
        }
    }

    std::cout << "\nTotal Tree Weight: " << totalWeight << "\n";

    return mst;
}

void AddEdge(std::vector<Edge>& edges, int nodeIndex, int linkedIndex, int weight)
{
    Edge newEdge;
    newEdge.nodeIndex = nodeIndex;
    newEdge.linkedNodeIndex = linkedIndex;
    newEdge.weight = weight;
    edges.push_back(newEdge);
}

void AddLink(std::vector<Node>& neighbors, int linkedIndex, int weight)
{
    auto iter = std::find_if(neighbors.begin(), neighbors.end(),
        [linkedIndex](const Node& n)
        {
            return n.nodeIndex == linkedIndex;
        });

    if (iter == neighbors.end())
    {
        Node newNeighbor;
        newNeighbor.nodeIndex = linkedIndex;
        newNeighbor.weight = weight;
        neighbors.push_back(newNeighbor);
    }
}

void AddLinkPair(std::vector<std::vector<Node>> adjList, int node, int linkedNeighbor, int weight)
{
    AddLink(adjList[node], linkedNeighbor, weight);
    AddLink(adjList[linkedNeighbor], node, weight);
}

void DepthFirstSearch(const std::vector<std::vector<Node>>& adjList, int startNode)
{
    int totalWeight = 0;

    std::vector<int> key;
    std::vector<bool> visited;
    visited.resize(adjList.size(), false);
    key.resize(adjList.size(), INT_MAX);

    key[startNode] = 0;

    std::cout << "\nDFS:\n";
    std::stack<int> process;
    process.push(startNode);

    while (!process.empty())
    {
        int nodeIndex = process.top();
        process.pop();

        if (!visited[nodeIndex])
        {
            visited[nodeIndex] = true;
            totalWeight += key[nodeIndex];

            std::cout << nodeIndex << " ";

            for (int i = 0; i < adjList[nodeIndex].size(); ++i)
            {
                const Node& node = adjList[nodeIndex][i];

                if (!visited[node.nodeIndex])
                {
                    key[node.nodeIndex] = node.weight;
                    process.push(node.nodeIndex);
                }
            }
        }
    }
    std::cout << "\nTotal Tree Weight: " << totalWeight << "\n";
}

void BreadthFirstSearch(const std::vector<std::vector<Node>>& adjList, int startNode)
{
    int totalWeight = 0;

    std::vector<int> key;
    std::vector<bool> visited;
    visited.resize(adjList.size(), false);
    key.resize(adjList.size(), INT_MAX);

    key[startNode] = 0;

    std::cout << "\nBFS:\n";
    std::queue<int> process;
    process.push(startNode);

    while (!process.empty())
    {
        int nodeIndex = process.front();
        process.pop();

        if (!visited[nodeIndex])
        {
            visited[nodeIndex] = true;
            totalWeight += key[nodeIndex];

            std::cout << nodeIndex << " ";

            for (int i = 0; i < adjList[nodeIndex].size(); ++i)
            {
                const Node& node = adjList[nodeIndex][i];

                if (!visited[node.nodeIndex])
                {
                    key[node.nodeIndex] = node.weight;
                    process.push(node.nodeIndex);
                }
            }
        }
    }
    std::cout << "\nTotal Tree Weight: " << totalWeight << "\n";
}

struct CompareWeight
{
    bool operator()(const Node& a, const Node& b)
    {
        return b.weight < a.weight;
    }
};

void PrimsAlgorithm(const std::vector<std::vector<Node>>& adjList, int startNode)
{
    int totalWeight = 0;

    std::vector<int> key;
    std::vector<bool> visited;
    key.resize(adjList.size(), INT_MAX);
    visited.resize(adjList.size(), false);

    std::cout << "\nPrims Algorithm:\n";
    std::priority_queue<Node, std::vector<Node>, CompareWeight> process;

    key[startNode] = 0;
    process.push({ startNode, 0 });

    while (!process.empty())
    {
        Node node = process.top();
        process.pop();

        if (!visited[node.nodeIndex])
        {
            visited[node.nodeIndex] = true;
            totalWeight += key[node.nodeIndex];

            std::cout << node.nodeIndex << " ";

            for (int i = 0; i < adjList[node.nodeIndex].size(); ++i)
            {
                const Node& neighbor = adjList[node.nodeIndex][i];

                if (!visited[neighbor.nodeIndex] && neighbor.weight < key[neighbor.nodeIndex])
                {
                    key[neighbor.nodeIndex] = neighbor.weight;
                    process.push({ neighbor.nodeIndex, key[neighbor.nodeIndex] });
                }
            }
        }
    }
    std::cout << "\nTotal Tree Weight: " << totalWeight << "\n";
}

int main()
{
    std::cout << "Graph Traversal:\n";

    std::vector<std::vector<Node>> adjacencyList;
    // a, b, c, d, e
    // 0, 1, 2, 3, 4 (index in the list)
    adjacencyList.resize(5);
    AddLinkPair(adjacencyList, 0, 3, 2);
    AddLinkPair(adjacencyList, 0, 1, 9);
    AddLinkPair(adjacencyList, 0, 2, 5);
    AddLinkPair(adjacencyList, 1, 3, 6);
    AddLinkPair(adjacencyList, 1, 4, 5);
    AddLinkPair(adjacencyList, 2, 3, 4);
    AddLinkPair(adjacencyList, 2, 4, 5);
    AddLinkPair(adjacencyList, 3, 4, 4);

    DepthFirstSearch(adjacencyList, 4);
    BreadthFirstSearch(adjacencyList, 4);
    PrimsAlgorithm(adjacencyList, 4);

    std::vector<Edge> edges;
    AddEdge(edges, 0, 1, 9);
    AddEdge(edges, 0, 2, 5);
    AddEdge(edges, 0, 3, 2);
    AddEdge(edges, 1, 3, 6);
    AddEdge(edges, 1, 4, 5);
    AddEdge(edges, 2, 3, 4);
    AddEdge(edges, 2, 4, 5);
    AddEdge(edges, 3, 4, 4);

    std::vector<Edge> mst = KruskalAlgorithm(edges, adjacencyList.size());

    std::vector<bool> isAdded(adjacencyList.size(), false);

    std::cout << "\nPrinting MST:\n";

    for (Edge& edge : mst)
    {
        if (!isAdded[edge.nodeIndex])
        {
            std::cout << edge.nodeIndex << " ";
            isAdded[edge.nodeIndex] = true;
        }
        if (!isAdded[edge.linkedNodeIndex])
        {
            std::cout << edge.linkedNodeIndex << " ";
            isAdded[edge.linkedNodeIndex] = true;
        }
    }

    std::cout << "\n";
}