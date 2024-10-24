#pragma once
#include "Action.hpp"

class Entity;

class WalkAction : public Action
{
public:

	void Start(Entity* entity) override;
	void Update(Entity* entity) override;
	void End(Entity* entity) override;
};

