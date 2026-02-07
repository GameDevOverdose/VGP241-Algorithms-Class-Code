#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <string>

//Create a function that has a time complexity of : ​
//    O(1)​ Constant
int Constant(int val)
{
    return val * val;
}

//    O(n)​ Linear
int Linear(int start, int n)
{
    for (int i = 0; i < n; ++i)
    {
        start += i;
    }
    return start;
}

//    O(log n) Logrithmic
int Logrithmic(int start, int n)
{
    for (int i = 0; i < n; i *= 2)
    {
        start += i;
    }
    return start;
}

//Create a vector of ints​
//Add 100 random numbers​
//Create a function that prints the values indexing through the vector​
void PrintIndexing(const std::vector<int>& values)
{
    std::cout << "Indexing: \n";
    for (int i = 0; i < values.size(); ++i)
    {
        std::cout << i << "\n";
    }
    //// for each loop
    //for (int i : values)
    //{

    //}
}

//Create a function that prints the values iterating through the vector​
void PrintIterating(const std::vector<int>& values)
{
    std::cout << "Iterator: \n";
    // for(auto iter = values.begin(); iter != values.end(); ++iter)
    for (std::vector<int>::const_iterator iter = values.begin(); iter != values.end(); ++iter)
    {
        std::cout << (*iter) << "\n";
    }
}
//Create a function that prints the values using a recursive function
void PrintRecursive(const std::vector<int>& values, int index)
{
    // be careful of STACK OVERFLOW
    // happens when the function is called too many times without exiting
    // function calls get added to the stack and consume stack memory
    // when this runs out, the program will crash
    // recursion shouldnt be used on large datasets vs indexing/iteration
    if (index < values.size())
    {
        std::cout << values[index] << "\n";
        PrintRecursive(values, index + 1);
    }
}
void IndexingExercise()
{
    std::vector<int> myInts;
    PrintIndexing(myInts);
    PrintIterating(myInts);
    PrintRecursive(myInts, 0);
}

class House
{
public:
    int price = 0;
    int squareFoot = 0;
    int rooms = 0;
    int distance = 0;

    bool operator()(const House& a, const House& b)
    {
        return a.price < b.price;
    }
};

struct SortByPrice
{
    bool operator()(const House& a, const House& b)
    {
        return a.price < b.price;
    }
};

struct SortBySqrFt
{
    bool operator()(const House& a, const House& b)
    {
        return a.squareFoot < b.squareFoot;
    }
};

struct SortByDistance
{
    bool operator()(const House& a, const House& b)
    {
        return a.distance < b.distance;
    }
};

struct SortByRoom
{
    bool operator()(const House& a, const House& b)
    {
        if (a.rooms == b.rooms)
        {
            return b.price < a.price;
        }

        return b.rooms < a.rooms;
    }
};

class HouseListings
{
public:
    void AddHouse(const House& house)
    {
        mHouses.push_back(house);
    }

    template<typename Callback>

    void PrintWithCriteria()
    {
        std::priority_queue<House, std::vector<House>, Callback> sortedHouses;

        for (int i = 0; i < mHouses.size(); ++i)
        {
            sortedHouses.push(mHouses[i]);
        }

        while (!sortedHouses.empty())
        {
            House top = sortedHouses.top();
            sortedHouses.pop();

            std::cout << "Price: " << top.price << " ";
            std::cout << "Rooms: " << top.rooms << " ";
            std::cout << "Distance: " << top.distance << " ";
            std::cout << "SqrFt: " << top.squareFoot << "\n";
        }
    }
private:
    std::vector<House> mHouses;
};

void PriorityQueueExercise()
{
    //Create a class called House​
    //    Int price​
    //    Int square foot​
    //    Int rooms​
    //    Int distance​
    //Create a class HouseListings​
    //    Std::vector<House> mHouses; ​
    //    Void ListHouse(const House & house)​
    //    Void PrintWithCritiera(sortCallbackFunction)​
    //    Prints the houses in the order stated by the callback​
    //    Adds houses to a priority queue and prints the list​
    //Add 20 houses, sort price, square foot, distance​
    //If there is a tie, sort should be by distance, then rooms, then square foot
    HouseListings houseListings;
    for (int i = 0; i < 20; ++i)
    {
        House newHouse;
        newHouse.price = 100000 + (rand() % 1000000);
        newHouse.distance = 10 + (rand() % 100);
        newHouse.rooms = 1 + (rand() % 4);
        newHouse.squareFoot = 1000 + (rand() % 2000);
        houseListings.AddHouse(newHouse);
    }

    houseListings.PrintWithCriteria<SortByRoom>();
}

struct Node
{
    // data for display
    std::string data;
    // a flag to declar node was visited
    bool visited = false;
    // to obtain path, need to know where we came from
    const Node* fromNode = nullptr;
    // connecting nodes
    std::vector<Node*> edges;
};

class Graph
{
public:
    void CreateGraph(int width, int height)
    {
        // create all the nodes
        mNodes.resize(width * height);

        for (int h = 0; h < height; ++h)
        {
            for (int w = 0; w < width; ++w)
            {
                int index = w + (h * width);

                if (w + 1 < width)
                {
                    int right = (w + 1) + (h * width);

                    // add neighbor to the right
                    mNodes[index].edges.push_back(&mNodes[right]);
                    // add self as right's neighbor
                    mNodes[right].edges.push_back(&mNodes[index]);
                }

                if (h + 1 < height)
                {
                    int down = w + ((h + 1) * width);

                    // add neighbor below
                    mNodes[index].edges.push_back(&mNodes[down]);
                    // add self as the below's neighbor
                    mNodes[down].edges.push_back(&mNodes[index]);
                }

                mNodes[index].data = std::to_string(w) + "_" + std::to_string(h);
            }
        }
    }

    void PrintPathDFS(int startIndex, int endIndex)
    {
        Reset();
        std::cout << "Printing Path (DFS):\n";

        Node* startNode = &mNodes[startIndex];
        Node* endNode = &mNodes[endIndex];
        std::stack<Node*> stack;
        stack.push(startNode);

        while (!stack.empty())
        {
            Node* node = stack.top();
            stack.pop();

            if (!node->visited)
            {
                node->visited = true;

                if (node == endNode)
                {
                    break;
                }

                for (int i = 0; i < node->edges.size(); ++i)
                {
                    Node* edgeNode = node->edges[i];

                    if (!edgeNode->visited)
                    {
                        edgeNode->fromNode = node;
                        stack.push(edgeNode);
                    }
                }
            }
        }

        const Node* path = endNode;

        while (path != nullptr)
        {
            std::cout << path->data << " ";
            path = path->fromNode;
        }
    }

    void PrintPathBFS(int startIndex, int endIndex)
    {
        Reset();
        std::cout << "Printing Path (BFS):\n";

        Node* startNode = &mNodes[startIndex];
        Node* endNode = &mNodes[endIndex];
        std::queue<Node*> queue;
        queue.push(startNode);

        while (!queue.empty())
        {
            Node* node = queue.front();
            queue.pop();

            if (!node->visited)
            {
                node->visited = true;

                if (node == endNode)
                {
                    break;
                }

                for (int i = 0; i < node->edges.size(); ++i)
                {
                    Node* edgeNode = node->edges[i];

                    if (!edgeNode->visited)
                    {
                        edgeNode->fromNode = node;
                        queue.push(edgeNode);
                    }
                }
            }
        }

        const Node* path = endNode;

        while (path != nullptr)
        {
            std::cout << path->data << " ";
            path = path->fromNode;
        }

    }

    void Reset()
    {
        for (int i = 0; i < mNodes.size(); ++i)
        {
            mNodes[i].visited = false;
            mNodes[i].fromNode = nullptr;
        }
    }

private:
    std::vector<Node> mNodes;
};

void GraphExercise()
{
    //Create a simple console application that asks a user to input a width
    //    and height​
    //    Create a "Node" struct that has a string data value and a vector of
    //    nodes called "edges"​
    //    Create a "Graph" class that contains a vector of Nodes​
    //    Build the Graph with the width and height given​
    //    All nodes will have there neighbors as the index next to them ​
    //    Tip if you add link for index + 1, also add the current node as a neighbor to the
    //    next node​
    //    Pick two locations within the grid​
    //    Print the BFS path and print the DFS path

    int width = 0;
    int height = 0;
    std::cout << "Enter a width: ";
    std::cin >> width;
    std::cout << "Enter a height: ";
    std::cin >> height;

    Graph graph;
    graph.CreateGraph(width, height);
    int startIndex = 0;
    int endIndex = 0;
    std::cout << "Enter a Start Index: ";
    std::cin >> startIndex;
    std::cout << "Enter a End Index: ";
    std::cin >> endIndex;

    graph.PrintPathDFS(startIndex, endIndex);
    std::cout << "\n\n";
    graph.PrintPathBFS(startIndex, endIndex);
}

int main()
{
    GraphExercise();
}
