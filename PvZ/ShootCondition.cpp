#include "ShootCondition.h"
#include "Playground.h"

bool ShootCondition::Test(Entity* entity)
{
	for (int i = 0; i < Playground::getInstance()->mZombies.size(); i++)
	{
		if (Playground::getInstance()->mZombies[i]->getPosition().y == entity->getPosition().y)
			return true;
	}
	return false;
}