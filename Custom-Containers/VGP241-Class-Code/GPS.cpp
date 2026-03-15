#include "GPS.h"

GPS::GPS()
{
	mCities.Reserve(25);
}

void GPS::AddCity(const std::string& name, const Vector2& position)
{
	for (int i = 0; i < mCities.Size(); ++i)
	{
		// if string was the only comparison for duplicacy then could just use mCityMap.Has(name)
		if (mCities[i].GetName() == name && mCities[i].GetPosition() == position)
		{
			return;
		}
	}

	mCityMap[name] = mCities.Size();

	// if doing it with Vector<City*> mCities, the vector only transfers pointers, but never the data
	// then resize does not cause any issues
	mCities.PushBack({ name, position });
	mCityGraph.AddItem(&mCities[mCities.Size() - 1]);
}
void GPS::AddCitiesToMap()
{
	// Resizing vector allocates the data to different memory blocks
	// If adding more cities than reserved, call this function after all cities have been added
	for (std::size_t i = 0; i < mCities.Size(); ++i)
	{
		mCityGraph.AddItem(&mCities[i]);
	}
}

void GPS::ConnectCities(const CityA8& a, const CityA8& b)
{
	if (!(mCityMap.Has(a.GetName()) && mCityMap.Has(b.GetName())))
	{
		return;
	}

	int cityAIndex = mCityMap[a.GetName()];
	int cityBIndex = mCityMap[b.GetName()];

	// because of this the vector is still needed, so not sure if the performance benefit outweighs the memory cost of storing both map and vector
	// for a vector only version check the previous commit
	// could also use DistanceSquared for weights and then square root them when needing/printing actual distance, for optimization
	mCityGraph.AddEdge(cityAIndex, cityBIndex, mCities[cityAIndex].GetPosition().Distance(mCities[cityBIndex].GetPosition()));
}

float GPS::FindPath(const CityA8& from, const CityA8& to, Vector<const CityA8*>& pathOutput)
{
	if (!(mCityMap.Has(from.GetName()) && mCityMap.Has(to.GetName())))
	{
		return -1.0f;
	}

	int cityAIndex = mCityMap[from.GetName()];
	int cityBIndex = mCityMap[to.GetName()];

	return mCityGraph.GetPath(cityAIndex, cityBIndex, pathOutput);
}