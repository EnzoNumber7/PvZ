#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"

class Playground
{
private:
	static Playground* mInstance;

	Playground();

public:
	std::vector<Plant*>			mPlants;
	std::vector<Zombies*>		mZombies;
	std::vector<Projectile*>	mProjectiles;

	static Playground* instantiate();
	static Playground* getInstance() { return mInstance; };

	~Playground() { };
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
};