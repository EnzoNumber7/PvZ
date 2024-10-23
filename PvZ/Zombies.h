#pragma once
#include "Entity.hpp"
#include "Plant.hpp"
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Transition;

class Zombies : public Entity
{
	int		mSpeed;


	Transition* mWalkTransition;
	Transition* mAttackTransition;

public:
	Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color);
	~Zombies();

	void Init(int posY);

	void Update() override;
	void checkCollision(std::vector<Entity*>& mColliding, std::vector<Entity*>& mCollider) override;

	void Attack(Plant* plant);
};

