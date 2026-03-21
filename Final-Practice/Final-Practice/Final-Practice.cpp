#include <iostream>
#include <string>
#include <vector>

// HASH TABLE ----------------------------------------------------------

const int HASH_TABLE_SIZE = 10;

int HashFunction(std::string string)
{
    int hashValue = 0;

	for (int i = 0; i < string.size(); ++i)
	{
		hashValue += string[i];
	}

	return hashValue;
}

int GetIndexFromHashValue(int hashValue)
{
	return hashValue % HASH_TABLE_SIZE;
}

void HashTablePractice()
{
	std::cout << "Hash Table:\n\n";

	std::cout << GetIndexFromHashValue(HashFunction("ABC"));
}

// BUBBLE SORT ----------------------------------------------------------

void PrintVector(const std::vector<int>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		std::cout << vector[i];

		if (i != vector.size() - 1)
		{
			std::cout << ", ";
		}
	}
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void BubbleSort(std::vector<int>& vector)
{
	//optional optimization
	bool hasSwapped;

	for (int i = 0; i < vector.size(); ++i)
	{
		hasSwapped = false;

		for (int j = 0; j < vector.size() - i - 1; ++j)
		{
			if (vector[j] > vector[j + 1])
			{
				Swap(vector[j], vector[j + 1]);
				hasSwapped = true;
			}
		}

		if (!hasSwapped)
		{
			break;
		}
	}
}

void SelectionSort(std::vector<int>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < vector.size(); ++j)
		{
			if (vector[minIndex] > vector[j])
			{
				minIndex = j;
			}
		}

		Swap(vector[i], vector[minIndex]);
	}
}

void InsertionSort(std::vector<int>& vector)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		int key = vector[i];
		int j = i - 1;

		while (j >= 0 && vector[j] > key)
		{
			vector[j + 1] = vector[j];
			--j;
		}
		
		vector[j + 1] = key;
	}
}

void Merge(std::vector<int>& vector, int start, int mid, int end)
{
	int sizeLeft = mid - start + 1;
	int sizeRight = end - mid;

	std::vector<int> left;
	std::vector<int> right;

	for (int i = 0; i < sizeLeft; ++i)
	{
		left.push_back(vector[start + i]);
	}
	
	for (int i = 0; i < sizeRight; ++i)
	{
		right.push_back(vector[mid + 1 + i]);
	}

	int i = 0;
	int j = 0;
	int k = start;

	while (i < sizeLeft && j < sizeRight)
	{
		if (left[i] <= right[j])
		{
			vector[k] = left[i];
			++i;
		}
		else
		{
			vector[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < sizeLeft)
	{
		vector[k] = left[i];
		++i;
		++k;
	}

	while (j < sizeRight)
	{
		vector[k] = right[j];
		++j;
		++k;
	}
}

void MergeSort(std::vector<int>& vector, int start, int end)
{
	if (start < end)
	{
		int mid = ((end - start) / 2) + start;
		MergeSort(vector, start, mid);
		MergeSort(vector, mid + 1, end);
		Merge(vector, start, mid, end);
	}
}

int Partition(std::vector<int>& vector, int start, int end)
{
    int pivot = vector[start];
    int leftWall = start;

    for (int i = start + 1; i < end; ++i)
    {
        if (vector[i] < pivot)
        {
            ++leftWall;
            Swap(vector[i], vector[leftWall]);
        }
    }

    Swap(vector[start], vector[leftWall]);
    return leftWall;
}

void QuickSort(std::vector<int>& vector, int start, int end)
{
	if (start < end)
	{
		int pivot = Partition(vector, start, end);
		QuickSort(vector, start, pivot);
		QuickSort(vector, pivot + 1, end);
	}
}

void SortingPractice()
{
	std::vector <int> randNumbers;
	int amount = 100;

	for (int i = 0; i < amount; ++i)
	{
		randNumbers.push_back(rand() % 100);
	}

	PrintVector(randNumbers);

	//BubbleSort(randNumbers);
	//std::cout << "\n\nBubble Sort: ";
	//PrintVector(randNumbers);

	//SelectionSort(randNumbers);
	//std::cout << "\n\nSelection Sort: ";
	//PrintVector(randNumbers);

	//InsertionSort(randNumbers);
	//std::cout << "\n\nInsertion Sort: ";
	//PrintVector(randNumbers);

	//MergeSort(randNumbers, 0, randNumbers.size() - 1);
	//std::cout << "\n\nMerge Sort: ";
	//PrintVector(randNumbers);

	QuickSort(randNumbers, 0, randNumbers.size());
	std::cout << "\n\nQuick Sort: ";
	PrintVector(randNumbers);

	std::cout << "\n\n";
}

int main()
{
	SortingPractice();
}