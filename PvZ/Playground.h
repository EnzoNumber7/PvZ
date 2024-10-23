#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"

class Transition;
class Behavior;

class Playground
{
private:
	static Playground* mInstance;

	Playground();

	std::vector<Plant*>			mPlants;
	std::vector<Zombies*>		mZombies;
	std::vector<Projectile*>	mProjectiles;

	Behaviour*					mPlantsBehavior;
	Behaviour*					mZombiesBehavior;

public:

	static Playground* instantiate();
	static Playground* getInstance() {
		return mInstance;
	}

	~Playground() { };
	void Init();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);

	std::vector<Zombies*>		GetZombies();
	std::vector<Plant*>			GetPlant();
	std::vector<Projectile*>	GetProjectile();
};