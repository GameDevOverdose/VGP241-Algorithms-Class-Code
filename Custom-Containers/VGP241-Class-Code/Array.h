#pragma once

#include <cstddef>
#include "ContainerIterator.h"

template<typename T, std::size_t N>
class Array
{
public:
    // base constructor, called by default
    Array()
    {
        // allocate memory 
        // size required is size of T type object
        //      times the number of items N
        mValues = new T[N];
    }
    // constructor overload
    Array(T initValue)
    {
        mValues = new T[N];
        for (std::size_t i = 0; i < N; ++i)
        {
            mValues[i] = initValue;
        }
    }
    // destructor when destroyed
    ~Array()
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
            mValues = nullptr;
        }
    }

    //Gets called when Array<int, 5> int array = otherArray;
    Array(const Array& other)
    {
        mValues = new T[N];

        for (int i = 0; i < N; ++i)
        {
            mValues[i] = other.mValues[i];
        }
    }

    //Get called when Array<int, 5> int array = std::move(otherArray);
    Array(Array&& other)
    {
        mValues = std::move(other.mValues);
        other.mValues = nullptr;
    }

    //Get called when Array<int, 5> int array = otherArray;
    Array& operator=(const Array& other)
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
        }

        mValues = new T[N];

        for (int i = 0; i < N; ++i)
        {
            mValues[i] = other.mValues[i];
        }

        return *this;
    }

    //Get called when Array<int, 5> int array = std::move(otherArray);
    Array& operator=(Array&& other)
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
        }

        mValues =std::move(other.mValues);
        other.mValues = nullptr;
        return *this;
    }

    // gets the number of elements in the array
    const std::size_t Size() const
    {
        return N;
    }

    // gets the data stored in the array
    T* Data()
    {
        return mValues;
    }

    // const version
    const T* Data() const
    {
        return mValues;
    }

    // operator overloads to access data
    T& operator[](std::size_t index)
    {
        // can add custom data to catch out of bounds
        // eg: assert, throw/catch
        return mValues[index];
    }

    // const version
    const T& operator[](std::size_t index) const
    {
        return mValues[index];
    }

    //Iterators
    using Iterator = ContainerIterator<T>;
    using Const_Iterator = ContainerIterator<const T>;

    Iterator Begin() {return Iterator(mValues);}
    Iterator End() {return Iterator(mValues + N);}

    Const_Iterator Begin() const {return Const_Iterator(mValues);}
    Const_Iterator End() const {return Const_Iterator(mValues + N);}

private:
    T* mValues = nullptr;
};