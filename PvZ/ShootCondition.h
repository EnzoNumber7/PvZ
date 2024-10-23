#pragma once
#include "Condition.hpp"
class ShootCondition : public Condition
{
public:
	bool Test(Entity* entity) override;
};

