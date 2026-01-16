#pragma once

#include <cstddef>
#include <algorithm>
#include <cassert>

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

    void PopBack()
    {
        Resize(mSize - 1);
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

private:
    T* mValues = nullptr;
    std::size_t mCapacity = 0;
    std::size_t mSize = 0;
};