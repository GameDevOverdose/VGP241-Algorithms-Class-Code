#include "GPS.h"

GPS::GPS()
{
	mCities.Reserve(25);
}

void GPS::AddCity(const std::string& name, const Vector2& position)
{
	for (int i = 0; i < mCities.Size(); ++i)
	{
		if (mCities[i].GetName() == name && mCities[i].GetPosition() == position)
		{
			// city is a duplicate
			return;
		}
	}


	// UnorderdMap<std::string, int> mCities;
	// mCityMap[name] = mCities.Size();
	// if(mCityMap.HasKey(name))) { return }
	// int indexA = mCityMap[name];
	// int indexB = mCityMap[name];

	// City newCity = new City();
	// Vector<City*> mCities;
	// if doing it this way, the vector only transfers pointers, but never the data
	// then resize does not cause any issues
	mCities.PushBack({ name, position });
	mCityGraph.AddItem(&mCities[mCities.Size() - 1]);
}
void GPS::AddCitiesToMap()
{
	// this would have to be done AFTER all of the cities are added
	// then resize will not happen
	for (std::size_t i = 0; i < mCities.Size(); ++i)
	{
		mCityGraph.AddItem(&mCities[i]);
	}
}

void GPS::ConnectCities(const CityA8& a, const CityA8& b)
{
	int cityAIndex = -1;
	int cityBIndex = -1;

	for (std::size_t i = 0; i < mCities.Size(); i++)
	{
		if (mCities[i].GetName() == a.GetName() && mCities[i].GetPosition() == a.GetPosition())
		{
			cityAIndex = i;
		}

		if (mCities[i].GetName() == b.GetName() && mCities[i].GetPosition() == b.GetPosition())
		{
			cityBIndex = i;
		}
	}

	mCityGraph.AddEdge(cityAIndex, cityBIndex, mCities[cityAIndex].GetPosition().Distance(mCities[cityBIndex].GetPosition()));
}

float GPS::FindPath(const CityA8& from, const CityA8& to, Vector<const CityA8*>& pathOutput)
{
	int cityAIndex = -1;
	int cityBIndex = -1;

	for (std::size_t i = 0; i < mCities.Size(); i++)
	{
		if (mCities[i].GetName() == from.GetName() && mCities[i].GetPosition() == from.GetPosition())
		{
			cityAIndex = i;
		}

		if (mCities[i].GetName() == to.GetName() && mCities[i].GetPosition() == to.GetPosition())
		{
			cityBIndex = i;
		}
	}

	return mCityGraph.GetPath(cityAIndex, cityBIndex, pathOutput);
}