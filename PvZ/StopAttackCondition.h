#pragma once
#include "Condition.hpp"

class Entity;

class StopAttackCondition : public Condition
{
	bool Test(Entity* entity) override;
};

