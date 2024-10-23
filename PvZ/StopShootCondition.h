#pragma once
#include "Condition.hpp"

class StopShootCondition: public Condition
{
public:
	bool Test(Entity* entity) override;
};

