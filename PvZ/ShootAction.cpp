#include "ShootAction.h"
#include "Plant.hpp"

void ShootAction::Start(Entity* entity)
{
}

void ShootAction::Update(Entity* entity)
{
	Plant* plant = (Plant*)entity;
	plant->shoot();
}

void ShootAction::End(Entity* entity)
{

}