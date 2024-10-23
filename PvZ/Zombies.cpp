#include "Zombies.h"

Zombies::Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color) : Entity(position, behaviour, health, name, color)
{
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mColor = color;
    mState = Context::State::Attack;
}

Zombies::~Zombies()
{
}

void Zombies::Init(int posY)
{
    mShape.setRadius(20.f);
    mShape.setPosition(sf::Vector2f(mPosition.x, (50 + posY)));
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}

void Zombies::Update()
{
    int a = 0;
}

void Zombies::checkCollision(std::vector<Entity*>& mColliding, std::vector<Entity*>& mCollider)
{
    int a = 1;
}

void Zombies::Attack(Plant* plant)
{
    int a = 2;
}
