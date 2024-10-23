#pragma once
#include "Action.hpp"
#include "SFML/Graphics.hpp"

class ShootAction : public Action
{
	sf::Clock clock;
	sf::Time elapsedTime;

public:
	void Start(Entity* entity) override;
	void Update(Entity* entity) override;
	void End(Entity* entity) override;
};

