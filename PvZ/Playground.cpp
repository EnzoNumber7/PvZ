#include "Plant.hpp"
#include "Playground.h"

Playground* Playground::mInstance = nullptr;

Playground::Playground() {}

Playground* Playground::instantiate()
{
	mInstance = new Playground();
	return mInstance;
}

void Playground::Init()
{
	for (int i = 0; i < 8; i++)
	{
		Plant* plant = new Plant(sf::Vector2f(10, 25 + (i * 100)), nullptr, 10, 5, "Pisto-Poids", sf::Color::Green);
		plant->Init();
		mPlants.push_back(plant);
	}
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mPlants.size(); i++)
	{
		window.draw(mPlants[i]->getShape());
	}
}

void Playground::update()
{
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
}
