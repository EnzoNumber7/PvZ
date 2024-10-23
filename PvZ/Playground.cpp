#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"
#include "Lane.h"
#include "Playground.h"

Playground* Playground::mInstance = nullptr;

Playground::Playground() {}

Playground* Playground::instantiate()
{
	mInstance = new Playground();
	return mInstance;
}

void Playground::Init(sf::RenderWindow& window)
{
	// -- ZOMBIE WALK STATE -- //
	//Action* idleAction = (Action*)(new WalkAction());
	//mIdleTransition->addCondition();
	//mIdleTransition->setTargetState(Context::State::Idle);
	//mPlantsBehavior->AddTransition(Context::State::Idle, mIdleTransition);
	//mPlantsBehavior->AddAction(Context::State::Idle, idleAction);

	for (int i = 0; i < 8; i++)
	{
		Plant* plant = new Plant(sf::Vector2f(10, 25 + (i * 100)), mPlantsBehavior, 10, 5, "Pisto-Poid", sf::Color::Green);
		plant->Init();
		Lane* line = new Lane(sf::Vector2f(0, i * 100), sf::Vector2f(window.getSize().x, 100));
		line->Init();
		mPlants.push_back(plant);
		mLine.push_back(line);
	}
}

void Playground::draw(sf::RenderWindow& window)
{

	for (int i = 0; i < mPlants.size(); i++)
	{
		window.draw(mLine[i]->getShape());
		window.draw(mPlants[i]->getShape());
	}

	for (int i = 0; i < mZombies.size(); i++)
	{
		window.draw(mZombies[i]->getShape());
	}
}

void Playground::update()
{
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed &&
		event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i test = sf::Mouse::getPosition(window);
		sf::Vector2f aa = (sf::Vector2f)test;
		Zombies* zombie = new Zombies((sf::Vector2f)sf::Mouse::getPosition(window), nullptr, NULL, 5.f, 8, "Zombie", sf::Color::Red);
		zombie->Init(mLine.at(sf::Mouse::getPosition(window).y / 100)->getPosition().y);
		mZombies.push_back(zombie);
	}
}

std::vector<Zombies*> Playground::GetZombies()
{
	return mZombies;
}

std::vector<Plant*> Playground::GetPlant()
{
	return mPlants;
}

std::vector<Projectile*> Playground::GetProjectile()
{
	return mProjectiles;
}
