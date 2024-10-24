#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"
#include "Lane.h"
#include "Playground.h"

#include "Transition.hpp"
#include "Behaviour.hpp"
#include "Condition.hpp"
#include "ShootCondition.h"
#include "StopShootCondition.h"
#include "IdleAction.h"
#include "ShootAction.h"
#include "WalkAction.h"
#include "AttackCondition.h"
#include "StopAttackCondition.h"
#include "AttackCondition.h"
#include "AttackAction.h"

Playground* Playground::mInstance = nullptr;

Playground::Playground() {}

Playground* Playground::instantiate()
{
	mInstance = new Playground();
	return mInstance;
}

void Playground::Init(sf::RenderWindow& window)
{
	mPlantsBehavior = new Behaviour();
	mZombiesBehavior = new Behaviour();

	// -- PLANT IDLE STATE -- //
	Action* idleAction = (Action*)(new IdleAction());
	Condition* shootCondition = (Condition*)(new ShootCondition());
	mIdleTransition = new Transition();
	mIdleTransition->addCondition(shootCondition);
	mIdleTransition->setTargetState(Context::State::Attack);
	mPlantsBehavior->AddTransition(Context::State::Idle, mIdleTransition);
	mPlantsBehavior->AddAction(Context::State::Idle, idleAction);

	// -- PLANT SHOOT STATE -- //
	Action* shootAction = (Action*)(new ShootAction());
	Condition* stopShootCondition = (Condition*)(new StopShootCondition());
	mShootTransition = new Transition();
	mShootTransition->addCondition(stopShootCondition);
	mShootTransition->setTargetState(Context::State::Idle);
	mPlantsBehavior->AddTransition(Context::State::Attack, mShootTransition);
	mPlantsBehavior->AddAction(Context::State::Attack, shootAction);

	// -- ZOMBIE WALK STATE -- //
	Action* walkAction = (Action*)(new WalkAction());
	Condition* attackCondition = (Condition*)(new AttackCondition());
	mWalkTransition = new Transition();
	mWalkTransition->addCondition(attackCondition);
	mWalkTransition->setTargetState(Context::State::Attack);
	mZombiesBehavior->AddTransition(Context::State::Walk, mWalkTransition);
	mZombiesBehavior->AddAction(Context::State::Walk, walkAction);

	// -- ZOMBIE ATTACK STATE -- //
	Action* attackAction = (Action*)(new AttackAction());
	Condition* stopAttackCondition = (Condition*)(new StopAttackCondition());
	mAttackTransition = new Transition();
	mAttackTransition->addCondition(stopAttackCondition);
	mAttackTransition->setTargetState(Context::State::Walk);
	mZombiesBehavior->AddTransition(Context::State::Attack, mAttackTransition);
	mZombiesBehavior->AddAction(Context::State::Attack, attackAction);

	for (int i = 0; i < 8; i++)
	{
		Plant* plant = new Plant(sf::Vector2f(10, 50 + (i * 100)), mPlantsBehavior, 10, 5, "Pisto-Pois", sf::Color::Green);
		plant->Init();
		Lane* line = new Lane(sf::Vector2f(0, i * 100), sf::Vector2f(window.getSize().x, 100));
		line->Init();
		mPlants.push_back(plant);
		mLine.push_back(line);
	}
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mLine.size(); i++)
	{
		window.draw(mLine[i]->getShape());
	}

	for (int i = 0; i < mPlants.size(); i++)
	{
		window.draw(mPlants[i]->getSprite());
	}

	for (int i = 0; i < mZombies.size(); i++)
	{
		window.draw(mZombies[i]->getSprite());
	}

	for (int i = 0; i < mProjectiles.size(); i++)
	{
		window.draw(mProjectiles[i]->getShape());
	}
}

void Playground::update()
{
	for (int i = 0; i < mPlants.size(); i++)
	{
		mPlants[i]->Update();
		mPlantsBehavior->Update(mPlants[i]);
	}
	for (int j = 0; j < mZombies.size(); j++)
	{
		mZombies[j]->Update();
		mZombiesBehavior->Update(mZombies[j]);
	}
	for (int k = 0; k < mProjectiles.size(); k++)
	{
		mProjectiles[k]->Update();
	}

	for (int l = 0; l < mPlants.size(); l++)
	{
		if (mPlants[l]->getHp() <= 0)
		{
			delete mPlants[l];
			mPlants.erase(mPlants.begin() + l);

		}
	}
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed &&
		event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2i test = sf::Mouse::getPosition(window);
		sf::Vector2f aa = (sf::Vector2f)test;
		int posY = mLine.at(sf::Mouse::getPosition(window).y / 100)->getPosition().y + 50;
		Zombies* zombie = new Zombies(sf::Vector2f(sf::Mouse::getPosition(window).x, posY), mZombiesBehavior, NULL, 5.f, 8, "Zombie", sf::Color::Red);
		zombie->Init();
		mZombies.push_back(zombie);
	}
}

std::vector<Entity*> Playground::GetZombies()
{
	return mZombies;
}

std::vector<Entity*> Playground::GetPlant()
{
	return mPlants;
}

std::vector<Projectile*> Playground::GetProjectile()
{
	return mProjectiles;
}

void Playground::AddProjectile(Projectile* proj)
{
	mProjectiles.push_back(proj);
}

void Playground::RemoveProjectile(int index)
{
	mProjectiles.erase(mProjectiles.begin() + index);
}

void Playground::RemoveZombies(int index)
{
	mZombies.erase(mZombies.begin() + index);
}