#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <stack>

// PART 2 (don't forget the word document for Part 1)

int GetFactorial(int number)
{
    if (number <= 1)
    {
        return 1;
    }

    return number * (GetFactorial(number - 1));
}
void Questions1()
{
    std::cout << "Question 1:\n";

    std::cout << "5! = " << GetFactorial(5) << "\n";
    std::cout << "7! = " << GetFactorial(7) << "\n";
    std::cout << "4! = " << GetFactorial(4) << "\n";
    std::cout << "10! = " << GetFactorial(10) << "\n";
    std::cout << "8! = " << GetFactorial(8) << "\n";

    std::cout << "\n";
}

int StringLength(const char* str)
{
    int index = 0;
    
    while (str[index] != '\0')
    {
		index++;
    }

    return index;
}

void Questions2()
{
    std::cout << "Question 2:\n";

    std::cout << "The length of 'hello' is " << StringLength("hello") << "\n";
    std::cout << "The length of 'world' is " << StringLength("world") << "\n";
    std::cout << "The length of 'fantastic' is " << StringLength("fantastic") << "\n";
    std::cout << "The length of 'algorithm' is " << StringLength("algorithm") << "\n";
    std::cout << "\n";
}

class Home
{
};

class HomeOwner
{
public:
    HomeOwner()
    {
        mMyHome = new Home();
    }
    ~HomeOwner()
    {
        delete mMyHome;
        mMyHome = nullptr;
    }

    // Is supposed to create an identical mMyHome duplicate like the other HomeOwner,
    // but instead of just pointing to the other's, it should point to it's own mMyHome,
    // so that changing one doesn't affect the other
    void operator=(HomeOwner other)
    {
		//Home home = *other.mMyHome;
        //mMyHome = &home;

        //mMyHome = new Home(*other.mMyHome);

        //mMyHome = other.mMyHome;
    }

private:
    Home* mMyHome = nullptr;
};

void Questions3()
{
    std::cout << "Question 3:\n";
    HomeOwner newHomeOwner;
    // Throws a runtime error even if the code in the operator function is commented out
    // Happens once the compiler leaves the scope and the HomeOwner's destructor is called
    // In debug mode the compiler doesn't even enter the operator function (my syntax for the operator might be incorrect)
    //HomeOwner otherHomeOwner = newHomeOwner;

    // TODO create deep copy capabilities for HoweOwner
    std::cout << "\n";
}

void IsPalendrome(const std::string& word)
{
    std::vector <char> characterVector;
    characterVector.resize(word.size());

    int halfwayPoint = word.size() % 2 == 0 ? word.size() / 2 : word.size() / 2;

    int charIndex = 0;
    int isPalindrome = true;

    for (int i = word.size() - 1; i >= 0; --i)
    {
        char character = word[charIndex];

        if (word[charIndex] != '\0')
        {
            characterVector[i] = word[charIndex];
        }

        charIndex++;
    }

    for (int i = 0; i < word.size(); ++i)
    {
        //std::cout << characterVector[i] << " : " << word[i] << "\n";

        if (word[i] != characterVector[i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        std::cout << word << " is a palindrome.";
    }
    else
    {
        std::cout << word << " is not a palindrome.";
    }

    std::cout << "\n";
}
void Questions4()
{
    std::cout << "Question 4:\n";

    IsPalendrome("HELLO");
    IsPalendrome("LEVEL");
    IsPalendrome("10110101");
    IsPalendrome("10100101");
    IsPalendrome("TACOCAT");

    std::cout << "\n";
}

struct Car
{
    Car(const std::string& name, int cost, int milage, int tankSize)
        : name(name)
        , cost(cost)
        , milage(milage)
        , gasTankSize(tankSize)
    {

    }
    std::string name;
    int cost;
    int milage;
    int gasTankSize;

    void Print()
    {
        std::cout << name << " Cost: $" << cost << " : Milage: " << milage << "km : TankSize: " << gasTankSize << "L\n";
    }
};

struct SortByCost
{
    const int operator()(Car a, Car b)
    {
        return a.cost < b.cost;
    }
};

struct SortByMilage
{
    const int operator()(Car a, Car b)
    {
		if (a.milage == b.milage)
        {
            return a.cost < b.cost;
        }

        return a.milage < b.milage;
    }
};

struct SortByTankSize
{
    const int operator()(Car a, Car b)
    {
        if (a.gasTankSize == b.gasTankSize)
        {
            return a.cost < b.cost;
        }

        return a.gasTankSize < b.gasTankSize;
    }
};

void Questions5()
{
    std::cout << "Question 5:\n";
    std::vector<Car> cars;
    cars.push_back(Car("Ford", 10000, 65000, 50));
    cars.push_back(Car("Toyota", 9000, 88000, 50));
    cars.push_back(Car("Dodge", 33500, 45000, 72));
    cars.push_back(Car("Prius", 15000, 10000, 50));
    cars.push_back(Car("Subaru", 12000, 101000, 66));
    cars.push_back(Car("Nissan", 14000, 25000, 66));
    cars.push_back(Car("BMW", 50000, 73000, 72));

    std::priority_queue<Car, std::vector<Car>, SortByCost> carsSortedByCost;
    std::priority_queue<Car, std::vector<Car>, SortByMilage> carsSortedByMilage;
    std::priority_queue<Car, std::vector<Car>, SortByTankSize> carsSortedByTankSize;

    for (int i = 0; i < cars.size(); ++i)
    {
        carsSortedByCost.push(cars[i]);
        carsSortedByMilage.push(cars[i]);
        carsSortedByTankSize.push(cars[i]);
    }

    std::cout << "Sorted By Cost:\n\n";

    while (!carsSortedByCost.empty())
    {
		Car car = carsSortedByCost.top();
		car.Print();
		carsSortedByCost.pop();
    }

    std::cout << "\nSorted By Milage:\n\n";

    while (!carsSortedByMilage.empty())
    {
        Car car = carsSortedByMilage.top();
        car.Print();
        carsSortedByMilage.pop();
    }

    std::cout << "\nSorted By Tank Size:\n\n";

    while (!carsSortedByTankSize.empty())
    {
        Car car = carsSortedByTankSize.top();
        car.Print();
        carsSortedByTankSize.pop();
    }

    std::cout << "\n";
}

void AddToNode(std::array<int, 3>& node, std::array<int, 3>& nodeAtLevel, int k)
{
    if (node[k] < nodeAtLevel[k])
    {
        std::cout << "Node is added to the Left\n";
        return;
    }

    std::cout << "Node is added to the Right\n";
}

void Questions6()
{
    std::cout << "Question 6:\n";

    std::vector<std::array<int, 3>> listOfVectors =
    {
        {10, 10, 10},
        {5, 12, 8},
        {13, 4, 4},
        {2, 20, 6},
        {15, 5, 1},
        {11, 7, 9},
        {3, 9, 5}
    };

    std::array<int, 3> nodeAtLevel = { 9, 11, 7 };

    for (int i = 0; i < listOfVectors.size(); ++i)
    {
        AddToNode(listOfVectors[i], nodeAtLevel, i % 3);
    }

    std::cout << "\n";
}

void PrintConnectionsDFS(const std::vector<std::vector<int>>& graph, int startIndex)
{
    std::cout << "Print Connections (DFS):\n";

    std::stack <int> stack;
	stack.push(startIndex);

    std::vector <bool> visited;
    visited.resize(graph.size(), false);

    while (!stack.empty())
    {
        int index = stack.top();
		stack.pop();

        if (!visited[index])
        {
            visited[index] = true;

            for (int i = 0; i < graph[index].size(); i++)
            {
                if (!visited[graph[index][i]])
                {
                    stack.push(graph[index][i]);
                    //visited[graph[index][i]] = true;
                }
            }

            if (!stack.empty())
            {
                std::cout << index << "_" << stack.top() << " ";
            }
        }
    }

    std::cout << "\n\n";
}

void PrintConnectionsBFS(const std::vector<std::vector<int>>& graph, int startIndex)
{
    std::cout << "Print Connections (BFS):\n";

    std::queue <int> queue;
    queue.push(startIndex);

    std::vector <bool> visited;
    visited.resize(graph.size(), false);

    while (!queue.empty())
    {
        int index = queue.front();
        queue.pop();

        if (!visited[index])
        {
            visited[index] = true;

            for (int i = 0; i < graph[index].size(); i++)
            {
                if (!visited[graph[index][i]])
                {
                    queue.push(graph[index][i]);
                    //visited[graph[index][i]] = true;
                }
            }

            if (!queue.empty())
            {
                std::cout << index << "_" << queue.front() << " ";
            }
        }
    }

    std::cout << "\n\n";
}

void AddLink(std::vector<std::vector<int>>& graph, int index, int linkIndex)
{
    graph[index].push_back(linkIndex);
    graph[linkIndex].push_back(index);
}

void Questions7()
{
    std::cout << "Question 7:\n";

    int numNodes = 20;

    std::vector<std::vector<int>> adjacencyList;
    adjacencyList.resize(numNodes);

    AddLink(adjacencyList, 0, 1);
    AddLink(adjacencyList, 0, 2);
    AddLink(adjacencyList, 0, 3);
    AddLink(adjacencyList, 1, 4);
    AddLink(adjacencyList, 1, 5);
    AddLink(adjacencyList, 2, 6);
    AddLink(adjacencyList, 2, 7);
    AddLink(adjacencyList, 2, 8);
    AddLink(adjacencyList, 3, 9);
    AddLink(adjacencyList, 3, 10);
    AddLink(adjacencyList, 4, 11);
    AddLink(adjacencyList, 4, 12);
    AddLink(adjacencyList, 5, 13);
    AddLink(adjacencyList, 5, 14);
    AddLink(adjacencyList, 6, 15);
    AddLink(adjacencyList, 7, 16);
    AddLink(adjacencyList, 7, 17);
    AddLink(adjacencyList, 8, 18);
    AddLink(adjacencyList, 8, 19);

    PrintConnectionsDFS(adjacencyList, 10);
    PrintConnectionsBFS(adjacencyList, 3);

    std::cout << "\n";
}

int main()
{
    Questions1();
    Questions2();
    Questions3();
    Questions4();
    Questions5();
    Questions6();
    Questions7();
}