#include "StopShootCondition.h"
#include "Playground.h"

bool StopShootCondition::Test(Entity* entity)
{
	for (int i = 0; i < Playground::getInstance()->mZombies.size(); i++)
	{
		if (Playground::getInstance()->mZombies[i]->getPosition().y == entity->getPosition().y)
			return false;
	}
	return true;
}
