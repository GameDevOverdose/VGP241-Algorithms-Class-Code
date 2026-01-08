#include <iostream>
#include <array>
#include <vector>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;

void StartAlgorithm()
{
	std::cout << "Algorithm Started\n";

	gStartTime = std::chrono::high_resolution_clock::now();
}

void PrintDuration()
{
	std::chrono::steady_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime).count();

	std::cout << "Duration (ms): " << duration << "\n";
}

void PrintRandomValues(int* intArray, int maxSize, int maxValues)
{
	for (int i = 0; i < maxValues; i++)
	{
		int randIndex = rand() % maxSize;
		int value = intArray[randIndex];

		std::cout << "Value at index " << randIndex << ": " << value << std::endl;
	}
}

void ConstantTimeComplexity()
{
	std::array<int, 100> intArrayA;
	std::array<int, 10000> intArrayB;

	for (int i = 0; i < intArrayA.size(); i++)
	{
		intArrayA[i] = i;
	}

	for (int i = 0; i < intArrayB.size(); i++)
	{
		intArrayB[i] = i;
	}

	StartAlgorithm();

	std::cout << "Printing ArrayA: \n";
	PrintRandomValues(intArrayA.data(), intArrayA.size(), 20);

	PrintDuration();

	StartAlgorithm();

	std::cout << "\nPrinting ArrayB: \n";
	PrintRandomValues(intArrayB.data(), intArrayB.size(), 20);

	PrintDuration();
}

int GetNumberOfRepeats(const std::vector <int>& vec, int value)
{
	int count = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			count++;
		}
	}

	return count;
}

void LinearTimeComplexity()
{
	std::vector <int> intVectorA;
	std::vector <int> intVectorB;

	intVectorA.resize(100);

	for (int i = 0; i < intVectorA.size(); i++)
	{
		intVectorA[i] = (rand() % 50) + 1;
	}

	intVectorB.resize(10000);

	for (int i = 0; i < intVectorB.size(); i++)
	{
		intVectorB[i] = (rand() % 50) + 1;
	}

	int inputNumber = 0;

	std::cout << "Enter a number between 1 to 50: ";
	std::cin >> inputNumber;

	std::cout << "\n";

	StartAlgorithm();

	int count = GetNumberOfRepeats(intVectorA, inputNumber);
	std::cout << "Vector A Repeats " << inputNumber << ": " << count << " Times\n";

	PrintDuration();

	std::cout << "\n";

	StartAlgorithm();

	count = GetNumberOfRepeats(intVectorB, inputNumber);
	std::cout << "Vector B Repeats " << inputNumber << ": " << count << " Times\n";

	PrintDuration();
}

void PrintAtIntervals(const std::vector<int>& vec, int interval)
{
	for (int i = 0; i < vec.size(); i += interval)
	{
		std::cout << "(" << i << " : " << vec[i] << ")" << "\n";
	}
}

void LogarithmicTimeComplexity()
{
	std::vector <int> intVectorA;
	std::vector <int> intVectorB;

	intVectorA.resize(100);
	intVectorB.resize(1000);

	for (int i = 0; i < intVectorA.size(); i++)
	{
		intVectorA[i] = (rand() % 100) + 1;
	}

	for (int i = 0; i < intVectorB.size(); i++)
	{
		intVectorB[i] = (rand() % 100) + 1;
	}

	int interval = 0;

	std::cout << "Enter a number between 1 to 10: ";
	std::cin >> interval;

	StartAlgorithm();

	std::cout << "Vector A intervals\n";
	PrintAtIntervals(intVectorA, interval);

	PrintDuration();

	std::cout << "\n";

	StartAlgorithm();

	std::cout << "Vector B intervals\n";
	PrintAtIntervals(intVectorB, interval);

	PrintDuration();
}

void PrintNextPairIndices(const std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i] == vec[j])
			{
				std::cout << "Value (" << vec[i] << ") repeats at (" << i << ", " << j << ")\n";
			}
		}
	}
}

void QuadraticTimeComplexity()
{
	std::vector <int> intVectorA;
	std::vector <int> intVectorB;

	intVectorA.resize(10);
	intVectorB.resize(20);

	for (int i = 0; i < intVectorA.size(); i++)
	{
		intVectorA[i] = (rand() % 50) + 1;
	}

	for (int i = 0; i < intVectorB.size(); i++)
	{
		intVectorB[i] = (rand() % 50) + 1;
	}

	StartAlgorithm();
	std::cout << "Vector A pairs:\n";
	PrintNextPairIndices(intVectorA);
	PrintDuration();

	std::cout << "\n";

	StartAlgorithm();
	std::cout << "Vector B pairs:\n";
	PrintNextPairIndices(intVectorB);
	PrintDuration();
}

int main()
{
	QuadraticTimeComplexity();
}