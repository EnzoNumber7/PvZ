#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, Behaviour* behaviour, int speed, sf::Color color) 
	: Entity(position,behaviour,1,"bullet", color)
{
	mSpeed = speed;
}