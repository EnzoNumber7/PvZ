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

	std::vector<Plant*> mPlants;
	Playground();

public:
	static Playground* instantiate();
	static Playground* getInstance();

	~Playground() { };
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);
};