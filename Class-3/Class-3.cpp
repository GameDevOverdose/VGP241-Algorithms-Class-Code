#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;

void StartAlgorithm()
{
	gStartTime = std::chrono::high_resolution_clock::now();
}

void PrintDuration()
{
	std::chrono::steady_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - gStartTime).count();
	std::cout << "\nDuration: " << duration << " ns\n" << std::endl;
}

//////
void GoToScreen(const std::string& screenName, std::array<std::string, 10>& screens)
{
	for (int i = 0; i < screens.size(); i++)
	{
		if (screens[i].empty())
		{
			screens[i] = screenName;
			break;
		}
	}

	std::cout << "[Array] Go to Screen: " << screenName << std::endl;
}

void GoToScreen(const std::string& screenName, std::vector<std::string>& screens)
{
	screens.push_back(screenName);

	std::cout << "[Vector] Go to Screen: " << screenName << std::endl;
}

void GoToScreen(const std::string& screenName, std::stack<std::string>& screens)
{
	screens.push(screenName);

	std::cout << "[Stack] Go to Screen: " << screenName << std::endl;
}

void GoBack(std::array<std::string, 10>& screens)
{
	//Find the last added screen, remove it
	for (int i = screens.size(); i >= 0; i--)
	{
		if (!screens[i].empty())
		{
			std::cout << "[Array] Go back from Screen: " << screens[i] << std::endl;
			screens[i] = "";
			break;
		}
	}

	//Find the next last added screen
	for (int i = screens.size(); i >= 0; i--)
	{
		if (!screens[i].empty())
		{
			std::cout << "[Array] Is On Screen: " << screens[i] << std::endl;
			break;
		}
	}
}

void GoBack(std::vector <std::string>& screens)
{
	std::cout << "[Vector] Go back from Screen: " << screens.back() << std::endl;
	screens.pop_back();
	std::cout << "[Vector] Is On Screen: " << screens.back() << std::endl;
}

void GoBack(std::stack <std::string>& screens)
{
	std::cout << "[Stack] Go back from Screen: " << screens.top() << std::endl;
	screens.pop();
	std::cout << "[Stack] Is On Screen: " << screens.top() << std::endl;
}

void ExampleScreens()
{
	std::array<std::string, 10> screensArray;
	std::vector<std::string> screensVector;
	std::stack<std::string> screensStack;

	StartAlgorithm();

	std::cout << "Array: " << std::endl;

	GoToScreen("MainMenu", screensArray);
	GoToScreen("LevelSelect", screensArray);
	GoToScreen("GamePlay", screensArray);
	GoToScreen("GameOver", screensArray);
	GoBack(screensArray);
	GoBack(screensArray);
	GoBack(screensArray);

	PrintDuration();

	StartAlgorithm();

	std::cout << "Vector: " << std::endl;

	GoToScreen("MainMenu", screensVector);
	GoToScreen("LevelSelect", screensVector);
	GoToScreen("GamePlay", screensVector);
	GoToScreen("GameOver", screensVector);
	GoBack(screensVector);
	GoBack(screensVector);
	GoBack(screensVector);

	PrintDuration();

	StartAlgorithm();

	std::cout << "Stack: " << std::endl;

	GoToScreen("MainMenu", screensStack);
	GoToScreen("LevelSelect", screensStack);
	GoToScreen("GamePlay", screensStack);
	GoToScreen("GameOver", screensStack);
	GoBack(screensStack);
	GoBack(screensStack);
	GoBack(screensStack);

	PrintDuration();
}

//////
void EnterLine(const std::string& name, std::array <std::string, 10>& people)
{
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i].empty())
		{
			people[i] = name;
			break;
		}
	}

	std::cout << "[Array] " << name << " entered the line." << std::endl;
}

void EnterLine(const std::string& name, std::vector <std::string>& people)
{
	people.push_back(name);

	std::cout << "[Vector] " << name << " entered the line." << std::endl;
}

void EnterLine(const std::string& name, std::queue <std::string>& people)
{
	people.push(name);

	std::cout << "[Queue] " << name << " entered the line." << std::endl;
}

void PurchaseTicket(std::array <std::string, 10>& people)
{
	//Get the first person in line
	std::cout << "[Array] " << people[0] << " purchased a ticket." << std::endl;

	//Remove and move everyone up
	for (int i = 0; i < people.size() - 1; i++)
	{
		people[i] = people[i + 1];
	}
}

void PurchaseTicket(std::vector <std::string>& people)
{
	std::cout << "[Vector] " << people[0] << " purchased a ticket." << std::endl;

	people.erase(people.begin());
}

void PurchaseTicket(std::queue <std::string>& people)
{
	std::cout << "[Queue] " << people.front() << " purchased a ticket." << std::endl;

	people.pop();
}

void ExampleTickets()
{
		std::array <std::string, 10> peopleArray;
	std::vector <std::string> peopleVector;
	std::queue <std::string> peopleQueue;

	StartAlgorithm();

	std::cout << "Array: \n" << std::endl;

	EnterLine("Alice", peopleArray);
	EnterLine("Bob", peopleArray);
	EnterLine("Charlie", peopleArray);
	EnterLine("Diana", peopleArray);

	PurchaseTicket(peopleArray);

	EnterLine("Eve", peopleArray);
	EnterLine("Frank", peopleArray);
	EnterLine("Grace", peopleArray);

	while (!peopleArray[0].empty())
	{
		PurchaseTicket(peopleArray);
	}

	PrintDuration();

	StartAlgorithm();

	std::cout << "Vector: \n" << std::endl;

	EnterLine("Alice", peopleVector);
	EnterLine("Bob", peopleVector);
	EnterLine("Charlie", peopleVector);
	EnterLine("Diana", peopleVector);

	PurchaseTicket(peopleVector);

	EnterLine("Eve", peopleVector);
	EnterLine("Frank", peopleVector);
	EnterLine("Grace", peopleVector);

	while (!peopleVector.empty())
	{
		PurchaseTicket(peopleVector);
	}

	PrintDuration();

	StartAlgorithm();

	std::cout << "Queue: \n" << std::endl;

	EnterLine("Alice", peopleQueue);
	EnterLine("Bob", peopleQueue);
	EnterLine("Charlie", peopleQueue);
	EnterLine("Diana", peopleQueue);

	PurchaseTicket(peopleQueue);

	EnterLine("Eve", peopleQueue);
	EnterLine("Frank", peopleQueue);
	EnterLine("Grace", peopleQueue);

	while (!peopleQueue.empty())
	{
		PurchaseTicket(peopleQueue);
	}

	PrintDuration();
}

/////

void Example()
{
	std::priority_queue <int> myPriorityQueue;

	int maxNumbers = 10;
	int minRange = 1;
	int maxRange = 200;

	StartAlgorithm();

	for (int i = 0; i < maxNumbers; i++)
	{
		int randomNumber = (rand() % maxRange) + minRange;

		std::cout << randomNumber << ", ";

		myPriorityQueue.push(randomNumber);
	}

	std::cout << "\n\n";

	while (myPriorityQueue.size() > 0)
	{
		std::cout << myPriorityQueue.top() << ", ";
		myPriorityQueue.pop();
	}

	std::cout << "\n\n";

	PrintDuration();
}

/////

class Student
{
public:
	Student() :mAge(0), mMark(0) {}

	void SetFirstName(const std::string& firstName) { mFirstName = firstName; }
	void SetLastName(const std::string& lastName) { mLastName = lastName; }
	void SetAge(int age) { mAge = age; }
	void SetMark(int mark) { mMark = mark; }

	void Print()
	{
		std::cout << "Student: " << mFirstName << " " << mLastName << ", Age: " << mAge << ", Mark: " << mMark << std::endl;
	}

	//Override less than operator
	bool operator<(const Student& rhs) const
	{
		if (rhs.mMark == mMark)
		{
			return rhs.mLastName < mLastName;
		}

		return mMark < rhs.mMark;
	}

	int GetAge() const { return mAge; }
	int GetMark() const { return mMark; }

private:
	std::string mFirstName;
	std::string mLastName;
	int mAge;
	int mMark;
};

struct CompareAgeAscending
{
	bool operator()(const Student& lhs, const Student& rhs) const
	{
		return rhs.GetAge() < lhs.GetAge();
	}
};

struct CompareAgeDescending
{
	bool operator()(const Student& lhs, const Student& rhs) const
	{
		return lhs.GetAge() < rhs.GetAge();
	}
};

Student AddStudent(const std::string& firstName, const std::string& lastName, int age, int mark)
{
	Student newStudent;

	newStudent.SetFirstName(firstName);
	newStudent.SetLastName(lastName);
	newStudent.SetAge(age);
	newStudent.SetMark(mark);
	
	std::cout << "Added Student: " << std::endl;
	newStudent.Print();

	return newStudent;
}

void ExamplePriorityQueue()
{
	//Default
//std::priority_queue <Student> students;

	std::priority_queue <Student, std::vector<Student>, CompareAgeAscending> students;

	students.push(AddStudent("Alice", "Smith", 20, 85));
	students.push(AddStudent("Bob", "Johnson", 22, 90));
	students.push(AddStudent("Charlie", "Brown", 19, 78));
	students.push(AddStudent("Diana", "Williams", 21, 92));
	students.push(AddStudent("Eve", "Jones", 20, 88));
	students.push(AddStudent("Frank", "Garcia", 23, 80));
	students.push(AddStudent("Grace", "Miller", 22, 95));
	students.push(AddStudent("Hank", "Davis", 24, 76));
	students.push(AddStudent("Ivy", "Rodriguez", 21, 89));
	students.push(AddStudent("Jack", "Martinez", 20, 84));
	students.push(AddStudent("Kathy", "Hernandez", 22, 91));
	students.push(AddStudent("Leo", "Lopez", 19, 79));
	students.push(AddStudent("Mia", "Gonzalez", 21, 87));
	students.push(AddStudent("Nina", "Wilson", 23, 93));
	students.push(AddStudent("Oscar", "Anderson", 20, 82));
	students.push(AddStudent("Paul", "Thomas", 22, 88));
	students.push(AddStudent("Quinn", "Taylor", 19, 90));
	students.push(AddStudent("Rose", "Moore", 21, 77));
	students.push(AddStudent("Sam", "Jackson", 23, 94));
	students.push(AddStudent("Tina", "Martin", 20, 81));

	std::cout << "\n";

	while (!students.empty())
	{
		Student topStudent = students.top();
		topStudent.Print();
		students.pop();
	}
}

/////

void ExampleIterator()
{
	std::vector <int> myVector;

	for (int i = 0; i < 20; i++)
	{
		myVector.push_back(rand() % 40 + 1);
	}

	//Step through by index
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i] << ", ";
	}

	std::cout << "\n\n";

	//Step through by iterator
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		std::cout << (*it) << ", ";
	}
}

/////

unsigned long GetFactorial(const unsigned long value)
{
	if (value <= 1)
	{
		return 1;
	}

	return value * GetFactorial(value - 1);
}

void ExampleRecursion()
{
	unsigned long input;

	std::cout << "Enter a number: ";
	std::cin >> input;

	StartAlgorithm();

	unsigned long total = input;

	for (unsigned long i = input - 1; i > 0; --i)
	{
		total *= i;
	}

	std::cout << "[For] Factorial: " << total << "\n";

	PrintDuration();

	StartAlgorithm();

	std::cout << "[Recursion] Factorial: " << GetFactorial(input);

	PrintDuration();
}

void DicePermutations(int numDice, int maxRoll)
{
	if (numDice <= 0)
	{
		std::cout << "\n";
		return;
	}

	std::cout << maxRoll << " ";
	DicePermutations(numDice, maxRoll);
}

void DiceRecursionExercise()
{
	StartAlgorithm();

	DicePermutations(2, 6);

	PrintDuration();
}

int main()
{

}