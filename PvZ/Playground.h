#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"
#include "Lane.h"
#include <iostream>

class Transition;
class Behavior;

class Playground
{
private:
	static Playground* mInstance;

	Playground();

	std::vector<Entity*>			mPlants;
	std::vector<Entity*>		mZombies;
	std::vector<Projectile*>	mProjectiles;
	std::vector<Lane*>			mLine;

	Behaviour*					mPlantsBehavior;
	Behaviour*					mZombiesBehavior;

	Transition* mIdleTransition;
	Transition* mShootTransition;
	Transition* mWalkTransition;
	Transition* mAttackTransition;

public:

	static Playground* instantiate();
	static Playground* getInstance() {
		return mInstance;
	}

	~Playground() { };
	void Init(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);

	std::vector<Entity*>		GetZombies();
	std::vector<Entity*>			GetPlant();
	std::vector<Projectile*>	GetProjectile();
	void						AddProjectile(Projectile* proj);
	void						RemoveProjectile(int index);
	void						RemoveZombies(int index);
};