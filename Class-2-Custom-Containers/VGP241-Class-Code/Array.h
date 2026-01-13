#pragma once

#include <cstddef>

template <typename T, std::size_t N>

class Array
{
    public:
    Array()
    {
        //Size required is size of T type object times N number of objects
        mValues = new T[N];
    }

    Array(T initValue)
    {
        mValues = new T[N];

        for (std::size_t i = 0 ; i < N; ++i)
        {
            mValues[i] = initValue;
        }
    }

    ~Array()
    {
        delete[] mValues;
        mValues = nullptr;
    }

    //Get size of the array
    const std::size_t size() const
    {
        return N;
    }

    // gets the data stored in the array
    T* Data()
    {
        return mValues;
    }

    // Const version of Data()
    const T* Data() const
    {
        return mValues;
    }

    T& operator[](std::size_t index)
    {
        return mValues[index];
    }

    // Const version of operator[]
    const T& operator[](std::size_t index) const
    {
        return mValues[index];
    }

private:
    T* mValues = nullptr;
};