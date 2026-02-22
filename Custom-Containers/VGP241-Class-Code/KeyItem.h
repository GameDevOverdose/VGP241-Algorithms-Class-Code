#pragma once

#include <iostream>
#include <string>

class KeyItem
{
public:
	KeyItem(const std::string& name)
	{
		mName = name;
		mCount = 0;
	}

	// could just use add for both adding and subtracting
	void Add(int amount) { mCount += amount; }
	void Consume(int amount) { mCount -= amount; }
	int GetCount() const { return mCount; }

	void Print()
	{
		std::cout << "<" << mName << ">:<" << mCount << ">";
	}

private:
	std::string mName;
	int mCount;
};