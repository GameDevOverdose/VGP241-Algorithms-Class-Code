#include <iostream>

#include "Array.h"
#include "Vector.h"

int main()
{
    Array <int, 5> myInts(0);

    std::cout << "Array:\n";
    for (std::size_t i = 0; i < myInts.size(); ++i)
    {
        myInts[i] = i + 1;
        std::cout << "Value at " << i << " is: " << myInts[i] << "\n";
    }

    Vector <int> myVector;

    myVector.Reserve(10);

    std::cout << "\nVector:\n";
    for (std::size_t i = 0; i < 10; ++i)
    {
        myVector.PushBack(i + 1);
        std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
    }

    myVector.Resize(5);

    std::cout << "\nVector Resize:\n";
    for (std::size_t i = 0; i < myVector.Size(); ++i)
    {
        std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
    }
}