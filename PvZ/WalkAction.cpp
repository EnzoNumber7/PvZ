#include "WalkAction.h"
#include "Entity.hpp"

void WalkAction::Start(Entity* entity)
{

}

void WalkAction::Update(Entity* entity)
{
	sf::Vector2f newPos;
	newPos.x = entity->getPosition().x - 0.2f;
	newPos.y = entity->getPosition().y;

	entity->setPosition(newPos);
}

void WalkAction::End(Entity* entity)
{
}
