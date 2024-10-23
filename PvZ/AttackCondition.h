#pragma once
#include "Condition.hpp"

class Entity;

class AttackCondition : public Condition
{
	bool Test(Entity* entity) override;
};

