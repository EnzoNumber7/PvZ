#include "ShootAction.h"
#include "Plant.hpp"

void ShootAction::Start(Entity* entity)
{
	clock.restart();
}

void ShootAction::Update(Entity* entity)
{
	elapsedTime = clock.getElapsedTime();

	if (elapsedTime.asSeconds() >= 1)
	{
		Plant* plant = (Plant*)entity;
		plant->shoot();

		clock.restart();
	}
}