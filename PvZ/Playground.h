#pragma once
#include <SFML/Graphics.hpp>
#include "Plant.hpp"
#include "Zombies.h"
#include "Projectile.h"
#include "Lane.h"
#include <iostream>

class Playground
{
private:
	static Playground* mInstance;

	Playground();

public:
	std::vector<Plant*>			mPlants;
	std::vector<Zombies*>		mZombies;
	std::vector<Projectile*>	mProjectiles;
	std::vector<Lane*>			mLine;

	static Playground* instantiate();
	static Playground* getInstance() {
		return mInstance;
	}

	~Playground() { };
	void Init(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
};