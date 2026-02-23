#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class KeyItem
{
public:
	KeyItem(){}

	KeyItem(const std::string& name)
	{
		mName = name;
		mCount = 0;
	}

	// could just use add for both adding and subtracting
	// or could use absolute on the amount to enforce addition/subtraction
	void Add(int amount) { mCount += amount; }
	void Consume(int amount) { mCount -= amount; }
	std::string GetName() const { return mName; }
	int GetCount() const { return mCount; }

	void Print(bool printLikeList)
	{
		//std::cout << "<" << mName << ">:<" << mCount << ">";

		if (printLikeList)
		{
			std::cout << std::right << std::setw(16) << mName << " : " << mCount;
			return;
		}

		std::cout << mName << " (" << mCount << ")";
	}

private:
	std::string mName;
	int mCount;
};