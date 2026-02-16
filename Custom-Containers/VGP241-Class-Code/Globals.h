#pragma once

#include <functional>
#include <string>

#include "Vector.h"

namespace Globals
{
	inline std::size_t HashFunction(const std::string& str)
	{
		std::size_t hash = 0;

		for (std::size_t i = 0; i < str.size(); ++i)
		{
			hash = (~hash << 1) + (std::size_t)(str[i]);
		}

		return hash;
	}

	template<typename T>
	void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T>
	void BubbleSort(Vector<T>& values)
	{
		std::size_t size = values.Size();

		for (std::size_t i = 0; i < size; ++i)
		{
			for (std::size_t j = 0; j < size - i - 1; ++j)
			{
				if (values[j] > values[j + 1])
				{
					Swap(values[j], values[j + 1]);
				}
			}
		}
	}

	template<typename T>
	void BubbleSort(Vector<T>& values, std::function<bool(const T&, const T&)>& sortFunc)
	{
		std::size_t size = values.Size();

		for (std::size_t i = 0; i < size; ++i)
		{
			for (std::size_t j = 0; j < size - i - 1; ++j)
			{
				if (values[j] > values[j + 1])
				{
					Swap(values[j], values[j + 1]);
				}
			}
		}
	}


	template<typename T>
	void SelectionSort(Vector<T>& values)
	{
		std::size_t size = values.Size();

		for (std::size_t i = 0; i < size - 1; ++i)
		{
			std::size_t minIndex = i;

			for (std::size_t j = i + 1; j < size; ++j)
			{
				if (values[j] < values[minIndex])
				{
					minIndex = j;
				}
			}

			if (i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}

	template<typename T>
	void SelectionSort(Vector<T>& values, std::function<bool(const T&, const T&)>& sortFunc)
	{
		std::size_t size = values.Size();

		for (std::size_t i = 0; i < size - 1; ++i)
		{
			std::size_t minIndex = i;

			for (std::size_t j = i + 1; j < size; ++j)
			{
				if (sortFunc(values[j], values[minIndex]))
				{
					minIndex = j;
				}
			}

			if (i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}
}