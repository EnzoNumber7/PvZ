#pragma once
#include "Action.hpp"

class AttackAction : Action
{
public:

	void Start(Entity* entity) override;
	void Update(Entity* entity) override;
	void End(Entity* entity) override;
};

