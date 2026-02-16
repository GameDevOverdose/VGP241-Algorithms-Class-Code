#include "Entity.h"
#include "TextureManager.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Initialize(const std::string& textureFilePath)
{
	mTextureID = TextureManager::Get().LoadTexture(textureFilePath);

	SetRandomPosition({0, 0}, {100, 100});
	//SetRandomPosition({0, 0}, {120, 30});
}

void Entity::Update()
{
	SetRandomPosition({0, 0}, {100, 100});
	//SetRandomPosition({ 0, 0 }, { 120, 30 });
}

void Entity::Render()
{
	TextureManager::Get().GetTexture(mTextureID).Print();
	//TextureManager::Get().GetTexture(mTextureID).Print(mPosition.x, mPosition.y);
	std::cout << "(" << mPosition.x << ", " << mPosition.y << ")\n";
}

void Entity::SetPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void Entity::SetRandomPosition(Vector2 minBoundSidePos, Vector2 maxBoundSidePos)
{
	SetPosition((rand() % ((int)maxBoundSidePos.x + 1)) + (int)minBoundSidePos.x, (rand() % ((int)maxBoundSidePos.y + 1)) + (int)minBoundSidePos.y);
}