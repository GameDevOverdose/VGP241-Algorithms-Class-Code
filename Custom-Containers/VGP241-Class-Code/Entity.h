#pragma once

#include <string>

#include "Vector2.h"

class Entity
{
public:
	Entity();
	~Entity();

	void Initialize(const std::string& textureFilePath);

	void Update();

	void Render();

	void SetPosition(float x, float y);
	void SetRandomPosition(Vector2 minBoundSidePos, Vector2 maxBoundSidePos);

	bool operator>(const Entity& rhs) const
	{
		//Could also just use Magnitude Squared, but this is more explicit
		Vector2 origin{ 0.0f, 0.0f };
		return mPosition.DistanceSquared(origin) > rhs.mPosition.DistanceSquared(origin);
	}

private:
	std::size_t mTextureID;
	Vector2 mPosition;
};