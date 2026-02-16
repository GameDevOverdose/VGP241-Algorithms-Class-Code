#include "Assignment-4.h"

#include <iostream>
#include <thread>
#include <chrono>

#include "Vector.h"
#include "Entity.h"
#include "Globals.h"

Entity AddEntity(const std::string& filePath)
{
	Entity entity;
	entity.Initialize(filePath);
	return entity;
}

void AddEntities(Vector<Entity>& entities, const std::string& filePath, int amount = 1)
{
	for (int i = 0; i < amount; ++i)
	{
		entities.PushBack(AddEntity(filePath));
	}
}

void UpdateEntities(Vector<Entity>& entities)
{
	for (int i = 0; i < entities.Size(); ++i)
	{
		entities[i].Update();
	}
}

void RenderEntities(Vector<Entity>& entities)
{
	for (int i = 0; i < entities.Size(); ++i)
	{
		entities[i].Render();

		std::cout << "\n";
	}
}

void UpdateAndRenderEntities(Vector<Entity>& entities)
{
	for (int i = 0; i < entities.Size(); ++i)
	{
		entities[i].Update();
		entities[i].Render();

		std::cout << "\n";
	}
}

void Assignment4()
{
	Vector<Entity> myEntities;
	std::string input;

	// I realize that these are supposed to be just file paths not textures, but it looks pretty
	myEntities.PushBack(AddEntity("   O  \n"
								  "  /|\\/ \n"
								  "  / \\ "));

	myEntities.PushBack(AddEntity("   0  \n"
								  "  /|\\ \n"
								  " _/ \\_ "));

	AddEntities(myEntities, "  ___  \n"
							" (x x) \n"
							" \\_-_/ ", 20);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Update, Sort and Render" << " (" << i + 1 << "): \n";
		UpdateEntities(myEntities);
		Globals::BubbleSort(myEntities);
		RenderEntities(myEntities);

		//std::cin >> input;
	}

	while (input != "Exit")
	{
		std::cout << "What would you like to do (Update / Sort / Exit): ";
		std::cin >> input;

		if (input == "Sort")
		{
			Globals::BubbleSort(myEntities);
		}
		
		system("cls");

		if (input == "Update")
		{
			UpdateAndRenderEntities(myEntities);
		}
		else
		{
			std::cout << "Unsorted Entities: \n\n";

			RenderEntities(myEntities);
		}
	}
}