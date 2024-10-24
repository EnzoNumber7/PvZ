#include "AttackAction.h"
#include "Plant.hpp"
#include "Playground.h"

void AttackAction::Start(Entity* entity)
{
}

void AttackAction::Update(Entity* entity)
{
	for (int i = 0; i < Playground::getInstance()->GetPlant().size(); i++)
	{
		if (Playground::getInstance()->GetPlant()[i]->getPosition().y == entity->getPosition().y && Playground::getInstance()->GetPlant()[i]->getPosition().x + 50 >= entity->getPosition().x) 
		{
			Zombies* zombie = (Zombies*)entity;
			Plant* plant = (Plant*)Playground::getInstance()->GetPlant()[i];
			zombie->Attack(plant);
		}
	}
}

void AttackAction::End(Entity* entity)
{

}