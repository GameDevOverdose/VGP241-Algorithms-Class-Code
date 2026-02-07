#pragma once

#include <cstddef>
#include <algorithm>
#include <cassert>

#include "ContainerIterator.h"

template<typename T>

class Vector
{
public:
    Vector()
        : mValues(nullptr)
        , mCapacity(0)
        , mSize(0)
    {

    }

    ~Vector()
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
            mValues = nullptr;
        }

        mCapacity = 0;
        mSize = 0;
    }

    Vector(const Vector& other)
    {
        if (other.mCapacity > 0)
        {
            mValues = new T[other.mCapacity];

            for (int i = 0; i < other.mCapacity; i++)
            {
                mValues[i] = other.mValues[i];
            }
        }
        mSize = other.mSize;
        mCapacity = other.mCapacity;
    }

    Vector(Vector&& other)
    {
        mValues = other.mValues;
        mSize = other.mSize;
        mCapacity = other.mCapacity;

        other.mValues = nullptr;
        other.mSize = 0;
        other.mCapacity = 0;
    }

    Vector& operator=(const Vector& other)
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
        }

        if (other.mCapacity > 0)
        {
            mValues = new T[other.mCapacity];

            for (int i = 0; i < other.mCapacity; i++)
            {
                mValues[i] = other.mValues[i];
            }
        }

        mSize = other.mSize;
        mCapacity = other.mCapacity;

        return *this;
    }

    Vector& operator=(Vector&& other)
    {
        if (mValues != nullptr)
        {
            delete[] mValues;
            mValues = nullptr;
        }

        mValues = other.mValues;
        mSize = other.mSize;
        mCapacity = other.mCapacity;

        other.mValues = nullptr;
        other.mSize = 0;
        other.mCapacity = 0;

        return *this;
    }

    //Reserve, allocate data for space requirements (only if increasing capacity)
    void Reserve(std::size_t capacity)
    {
        if (capacity > mCapacity)
        {
            T* newValues = new T[capacity];

            if (mValues != nullptr)
            {
                for (std::size_t i = 0; i < mSize; i++)
                {
                    newValues[i] = mValues[i];
                }
            }
            delete[] mValues;
            mValues = newValues;
            mCapacity = capacity;
        }
    }

    //Resize, allocate the max required values, initialize the data if needed
    void Resize(std::size_t size, const T& initValue = T())
    {
        if (size == mSize)
        {
            return;
        }

        if (size < mSize)
        {
            for (std::size_t i = size; i < mSize; i++)
            {
                mValues[i].~T();
            }
        }
        else if (mSize < size)
        {
            std::size_t newCapacity = std::max(size, mCapacity * 2);
            Reserve(newCapacity);

            for (std::size_t i = mSize; i < size; i++)
            {
                mValues[i] = initValue;
            }
        }

        mSize = size;
    }

    void Clear()
    {
        Resize(0);
    }

    const std::size_t Size() const
    {
        return mSize;
    }

    const std::size_t Capacity() const
    {
        return mCapacity;
    }

    void PushBack(const T& value)
    {
        if (mSize >= mCapacity)
        {
            std::size_t newCapacity = (mCapacity == 0) ? 10 : mCapacity * 2;
            Reserve(newCapacity);
        }
        mValues[mSize] = value;
        mSize++;
    }

    //Remove item
    void PopBack()
    {
        Resize(mSize - 1);
    }

    //Just adding to have a functional queue
    void PopFront()
    {
        //Swaps the front all the way to back
        for (std::size_t i = 0; i < mSize - 1; ++i)
        {
            T tmp = mValues[i];
            mValues[i] = mValues[i + 1];
            mValues[i + 1] = tmp;
        }

        PopBack();
    }

    T& operator[](std::size_t index)
    {
        assert(index < mSize);
        return mValues[index];
    }

    const T& operator[](std::size_t index) const
    {
        assert(index < mSize);
        return mValues[index];
    }

    //Iterators
    using Iterator = ContainerIterator<T>;
    using Const_Iterator = ContainerIterator<const T>;

    Iterator Begin() {return Iterator(mValues);}
    Iterator End() {return Iterator(mValues + mSize);}

    Const_Iterator Begin() const {return Const_Iterator(mValues);}
    Const_Iterator End() const {return Const_Iterator(mValues + mSize);}

private:
    T* mValues = nullptr;
    std::size_t mCapacity = 0;
    std::size_t mSize = 0;
};