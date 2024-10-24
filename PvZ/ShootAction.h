#pragma once
#include "Action.hpp"
#include "SFML/Graphics.hpp"

class ShootAction : public Action
{

public:
	void Start(Entity* entity) override;
	void Update(Entity* entity) override;
	void End(Entity* entity) override;
};

