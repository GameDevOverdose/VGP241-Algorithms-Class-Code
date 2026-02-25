#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;

void StartAlgorithm()
{
	gStartTime = std::chrono::steady_clock::now();
}

void PrintAlgorithmTime()
{
	auto endTime = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime);

	std::cout << "\nTime (mc): " << duration.count() << "\n";
}

// INSERTION SORT -------------------------------------------------------------------------------

void InsertionSort(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		int key = vec[i];
		int j = i - 1;

		while (j >= 0)
		{
			if (vec[j] > key)
			{
				vec[j + 1] = vec[j];
				--j;
			}
			else
			{
				break;
			}
		}
		vec[j + 1] = key;
	}
}

void Exercise1InsertionSort()
{
	std::cout << "\n\nInsertion Sort:\n\n";

	std::vector <int> vec(20);

	for (int i = 0; i < vec.size(); ++i)
	{
		int value = 1 + (rand() % 100);
		vec[i] = value;

		std::cout << vec[i] << " ";
	}

	InsertionSort(vec);
	std::cout << "\n";

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
}

// MERGE SORT -------------------------------------------------------------------------------

void Merge(std::vector<int>& vec, int left, int mid, int right)
{
	int leftSize = (mid - left) + 1;
	int rightSize = right - mid;

	std::vector <int> tempLeft(leftSize);
	std::vector <int> tempRight(rightSize);

	for (int i = 0; i < leftSize; ++i)
	{
		tempLeft[i] = vec[left + i];
	}

	for (int i = 0; i < rightSize; ++i)
	{
		tempRight[i] = vec[mid + i + 1];
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int vecIndex = left;

	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (tempLeft[leftIndex] <= tempRight[rightIndex])
		{
			vec[vecIndex] = tempLeft[leftIndex];
			++leftIndex;
		}
		else
		{
			vec[vecIndex] = tempRight[rightIndex];
			++rightIndex;
		}

		++vecIndex;
	}

	while (leftIndex < leftSize)
	{
		vec[vecIndex] = tempLeft[leftIndex];
		++vecIndex;
		++leftIndex;
	}

	while (rightIndex < rightSize)
	{
		vec[vecIndex] = tempRight[rightIndex];
		++vecIndex;
		++rightIndex;
	}
}

void MergeSort(std::vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int mid = left + ((right - left) / 2);
		MergeSort(vec, left, mid);
		MergeSort(vec, mid + 1, right);
		Merge(vec, left, mid, right);
	}
}

void Exercise2MergeSort()
{
	std::cout << "\n\nMerge Sort:\n\n";
	std::vector <int> vec(20);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = 1 + (rand() % 100);
		std::cout << vec[i] << " ";
	}

	MergeSort(vec, 0, vec.size() - 1);
	std::cout << "\n";

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
}

// QUICK SORT -------------------------------------------------------------------------------

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(std::vector <int>& vec, int left, int right)
{
	int pivot = vec[right];
	int i = left - 1;

	for (int j = left; j < right; ++j)
	{
		if (vec[j] < pivot)
		{
			++i;
			Swap(vec[i], vec[j]);
		}
	}

	Swap(vec[i + 1], vec[right]);

	return i + 1;
}

void QuickSort(std::vector<int>& vec, int left, int right)
{
	if (left < right)
	{
		int p = Partition(vec, left, right);
		QuickSort(vec, left, p - 1);
		QuickSort(vec, p + 1, right);
	}
}

void Exercise3QuickSort()
{
	std::cout << "\n\nQuick Sort:\n\n";

	std::vector<int> vec(20);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = 1 + (rand() % 100);
		std::cout << vec[i] << " ";
	}

	QuickSort(vec, 0, vec.size() - 1);
	std::cout << "\n";

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
}

// BUCKET SORT -------------------------------------------------------------------------------

void BucketSort(std::vector <int>& vec)
{
	const int size = vec.size();
	int maxValue = 0;

	for (int i = 0; i < size; ++i)
	{
		maxValue = std::max(maxValue, vec[i]);
	}

	++maxValue;

	std::vector<std::vector<int>> buckets(size);

	for (int i = 0; i < size; ++i)
	{
		int bucketIndex = ((size * vec[i]) / maxValue);
		buckets[bucketIndex].push_back(vec[i]);
	}

	// Sorting method for each bucket
	for (int i = 0; i < size; ++i)
	{
		InsertionSort(buckets[i]);
	}

	// combine all buckets back into the container
	int vecIndex = 0;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < buckets[i].size(); ++j)
		{
			vec[vecIndex] = buckets[i][j];
			++vecIndex;
		}
	}
}

void Exercise4BucketSort()
{
	std::cout << "\n\nBucket Sort:\n\n";

	std::vector<int> vec(20);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = 1 + (rand() % 100);
		std::cout << vec[i] << " ";
	}

	BucketSort(vec);
	std::cout << "\n";

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
}

// RADIX SORT -------------------------------------------------------------------------------

void PrintVector(const std::vector <int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void CountingSort(std::vector<int>& vec, int exp)
{
	std::vector<int> output(vec.size());
	int count[10] = { 0 };

	for (int i = 0; i < vec.size(); ++i)
	{
		int index = (vec[i] / exp) % 10;
		++count[index];
	}

	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	for (int i = vec.size() - 1; i >= 0; --i)
	{
		int index = (vec[i] / exp) % 10;
		output[count[index] - 1] = vec[i];
		--count[index];
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = output[i];
	}
}

void RadixSort(std::vector <int>& vec)
{
	int maxValue = 0;

	for (int i = 0; i < vec.size(); ++i)
	{
		maxValue = std::max(maxValue, vec[i]);
	}
	for (int exp = 1; maxValue / exp << maxValue >  0; exp *= 10)
	{
		CountingSort(vec, exp);
		//PrintVector(vec);
	}
}

void Exercise5RadixSort()
{
	std::cout << "\n\nRadix Sort:\n\n";

	std::vector<int> vec(20);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = 1 + (rand() % 100);
		std::cout << vec[i] << " ";
	}

	RadixSort(vec);
	std::cout << "\n";

	PrintVector(vec);
}

// RADIX SORT -------------------------------------------------------------------------------

void Exercise6SortingRace()
{
	std::cout << "\nSorting Race:\n";
	int vectorSize = 10000;

	std::vector<int> vecA(vectorSize);
	std::vector<int> vecB(vectorSize);
	std::vector<int> vecC(vectorSize);
	std::vector<int> vecD(vectorSize);
	std::vector<int> vecE(vectorSize);

	for (int i = 0; i < vectorSize; ++i)
	{
		int value = 1 + (rand() % 1000000);
		vecA[i] = value;
		vecB[i] = value;
		vecC[i] = value;
		vecD[i] = value;
		vecE[i] = value;
	}

	// slower with bigger values, but simple
	std::cout << "\nInsertion Sort:";

	StartAlgorithm();
	InsertionSort(vecA);
	PrintAlgorithmTime();

	// divide and conquer, but uses a lot of recursion, and can limit stack space
	std::cout << "\nMerge Sort:";

	StartAlgorithm();
	MergeSort(vecB, 0, vecB.size() - 1);
	PrintAlgorithmTime();

	// also uses divide and conquer, but uses less memory than merge sort 
	std::cout << "\nQuick Sort:";

	StartAlgorithm();
	QuickSort(vecC, 0, vecC.size() - 1);
	PrintAlgorithmTime();

	// fairly fast but requires a lot of memory to work
	std::cout << "\nBucket Sort:";

	StartAlgorithm();
	BucketSort(vecD);
	PrintAlgorithmTime();

	// fast, but limited to fixed size data (eg. ints, strings, longs etc.)
	std::cout << "\nRadix Sort:";

	StartAlgorithm();
	RadixSort(vecE);
	PrintAlgorithmTime();
}

int main()
{
    std::cout << "Sorting:\n";

    //Exercise1InsertionSort();
    //Exercise2MergeSort();
	//Exercise3QuickSort();
	//Exercise4BucketSort();
	//Exercise5RadixSort();
	Exercise6SortingRace();

	std::cout << "\n\n";
}