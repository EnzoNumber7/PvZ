#include "StopShootCondition.h"
#include "Playground.h"

bool StopShootCondition::Test(Entity* entity)
{
	for (int i = 0; i < Playground::getInstance()->GetZombies().size(); i++)
	{
		if (Playground::getInstance()->GetZombies()[i]->getPosition().y == entity->getPosition().y)
			return false;
	}
	return true;
}
