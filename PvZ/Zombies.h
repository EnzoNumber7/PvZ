#pragma once
#include "Entity.hpp"
#include "Plant.hpp"
#include "Context.hpp"
#include "Behaviour.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Transition;

class Zombies : public Entity
{
	int		mSpeed;
	sf::Clock clock;
	sf::Time elapsedTime;


public:
	Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color);
	~Zombies();

	void Init();

	void Update() override;
	void checkCollision(std::vector<Entity*> mCollider) override;

	void Attack(Plant* plant);
};

