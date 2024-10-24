#include "Projectile.h"
#include "Playground.h"

Projectile::Projectile(sf::Vector2f position, int speed, std::string name, sf::Color color) : Entity(position, nullptr, 0, name, color)
{
	mSpeed = speed;
	mPosition = position;
	mName = name;
	mColor = color;

	mShape.setRadius(10.f);
	mShape.setPosition(sf::Vector2f(mPosition.x, mPosition.y));
	mShape.setFillColor(mColor);
	mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}

void Projectile::Update()
{
	checkCollision(Playground::getInstance()->GetZombies());

	Move();
	mShape.setPosition(mPosition);
}

void Projectile::Move()
{
	mPosition.x = mPosition.x + 0.2f;
	mPosition.y = mPosition.y;
}

void Projectile::checkCollision(std::vector<Entity*> mCollider)
{
	for (int i = 0; i < mCollider.size(); i++)
	{
		if (mCollider[i]->getPosition().x - mCollider[i]->getShape().getRadius() <= mPosition.x + mShape.getRadius() && mPosition.y == mCollider[i]->getPosition().y)
		{
			
			delete mCollider[i];
			Playground::getInstance()->RemoveZombies(i);

			for (int j = 0; j < Playground::getInstance()->GetProjectile().size(); j++) 
			{
				if (Playground::getInstance()->GetProjectile()[j] == this)
				{
					delete this;
					Playground::getInstance()->RemoveProjectile(j);
					return;
				}
			}
			
		}
	}
}