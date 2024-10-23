#include "StopAttackCondition.h"
#include "Entity.hpp"
#include "Playground.h"

bool StopAttackCondition::Test(Entity* entity)
{
	for (int i = 0; i < Playground::getInstance()->GetPlant().size(); i++)
	{
		if (Playground::getInstance()->GetPlant()[i]->getPosition().y == entity->getPosition().y && Playground::getInstance()->GetPlant()[i]->getPosition().x + 50 >= entity->getPosition().x)
			return false;
	}
	return true;
}


