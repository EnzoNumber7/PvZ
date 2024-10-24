#include "Zombies.h"
#include "WalkAction.h"
#include "Transition.hpp"

Zombies::Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color) : Entity(position, behaviour, health, name, color)
{
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mColor = color;
    mState = Context::State::Walk;

}

Zombies::~Zombies()
{
}

void Zombies::Init()
{
    mShape.setRadius(20.f);
    mShape.setPosition(sf::Vector2f(mPosition.x, mPosition.y));
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}

void Zombies::Update()
{
    mShape.setPosition(getPosition());
}

void Zombies::checkCollision(std::vector<Entity*> mCollider)
{
    int a = 1;
}

void Zombies::Attack(Plant* plant)
{
    elapsedTime = clock.getElapsedTime();

    if (elapsedTime.asSeconds() >= 1)
    {
        plant->TakeDamage(1);

        clock.restart();
    }
}
