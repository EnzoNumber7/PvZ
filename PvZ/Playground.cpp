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
