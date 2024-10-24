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
	Projectile(sf::Vector2f position, int speed, std::string name, sf::Color color);
	~Projectile() { };

	void Update();

	void checkCollision(std::vector<Entity*> mCollider) override;
	void Move();
};

