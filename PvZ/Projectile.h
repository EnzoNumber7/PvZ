#pragma once
#include "Entity.hpp"
#include "Plant.hpp"
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Projectile : public Entity
{
	int		mSpeed;

public:
	Projectile(sf::Vector2f position, Behaviour* behaviour, int speed);
	~Projectile() { };

	void Move();
};

