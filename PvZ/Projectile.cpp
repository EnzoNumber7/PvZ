#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, Behaviour* behaviour, int speed) : Entity(position,behaviour,1,"bullet")
{
	mSpeed = speed;
}