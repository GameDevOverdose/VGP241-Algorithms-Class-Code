#include <iostream>
#include <vector>
#include <string>

// EXERCISE-1 ============================================

int HashFunction(const std::string& string)
{
    int sum = 0;

    for (char c : string)
    {
        sum += (int)c;
    }

    return sum;
}

int TableIndex(int num, int size)
{
    return num % size;
}

void Exercise1()
{
    //std::vector<std::vector<std::string>> hashTable;
    std::string string = "Abc";

    int hashValue = HashFunction(string);
    int tableIndex = TableIndex(hashValue, 20);

    std::cout << "Hash Value:" << hashValue;
    std::cout << "\nTable Index:" << tableIndex;

    //hashTable[tableIndex].push_back(string);
}

// EXERCISE-2 ============================================

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void PrintVector(const std::vector<int>& vector)
{
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];

        if (i < vector.size() - 1)
        {
            std::cout << ", ";
        }
    }
}

void InsertionSort(std::vector<int>& numbersToSort)
{
    for (int i = 0; i < numbersToSort.size(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (numbersToSort[j] < numbersToSort[j - 1])
            {
                Swap(numbersToSort[j], numbersToSort[j - 1]);
            }
        }
    }
}

void Merge(std::vector<int>& numbers, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    std::vector<int> vecLeft;
    std::vector<int> vecRight;

    for (int i = 0; i < size1; ++i)
    {
        vecLeft.push_back(numbers[i]);
    }

    for (int i = 0; i < size2; ++i)
    {
        vecRight.push_back(numbers[i + mid + 1]);
    }

    int vecLIter = 0;
    int vecRIter = 0;
    int vecIter = 0;

    while (vecLIter < size1 && vecRIter < size2)
    {
        if (vecLeft[vecLIter] <= vecRight[vecRIter])
        {
            numbers[vecIter] = vecRight[vecRIter];
            ++vecLIter;
        }
        else
        {
            numbers[vecIter] = vecLeft[vecLIter];
            ++vecRIter;
        }

        ++vecIter;
    }

    while (vecLIter < size1)
    {
        numbers[vecIter] = vecLeft[vecLIter];
        ++vecLIter;
        ++vecIter;
    }

    while (vecRIter < size2)
    {
        numbers[vecIter] = vecLeft[vecRIter];
        ++vecRIter;
        ++vecIter;
    }
}

void MergeSort(std::vector<int>& numbersToSort, int left, int right)
{
    int mid = left + ((right - left) / 2);
    MergeSort(numbersToSort, left, mid);
    MergeSort(numbersToSort, mid + 1, right);
    Merge(numbersToSort, left, mid, right);
}

void Exercise2()
{
    std::vector<int> randNumbers;
    int amount = 100;
    int minRange = 1;
    int maxRange = 1000;

    for (int i = 0; i < amount; ++i)
    {
        randNumbers.push_back((rand() % (maxRange - minRange)) + minRange);
    }

    PrintVector(randNumbers);

    std::cout << "\n\n";

    //InsertionSort(randNumbers);
    //PrintVector(randNumbers);

    MergeSort(randNumbers, 0, randNumbers.size() - 1);
    PrintVector(randNumbers);

    std::cout << "\n\n";

    std::cout << "\n\n";
}

// EXERCISE-3 ============================================

int main()
{
    Exercise2();
}