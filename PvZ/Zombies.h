#pragma once
#include "Entity.hpp"
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Zombies : public Entity
{
	int		mSpeed;

public:
	Zombies(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int speed);
	~Zombies();

	void setState(Context::State);
	Context::State getState() const;
};

