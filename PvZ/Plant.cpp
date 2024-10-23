#include "Plant.hpp"
#include "Context.hpp"

Plant::Plant(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int health, std::string name, sf::Color color)
    : Entity(position, behaviour, health,name, color)
{
    mAmmoCount = ammo_count;
    mMaxAmmo = ammo_count;
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mColor = color;
    mState = Context::State::Idle;
}

Plant::~Plant()
{

}

int Plant::getAmmoCount() const
{
    return mAmmoCount;
}

void Plant::refillMagazine()
{
    mAmmoCount = mMaxAmmo;
}

void Plant::Init()
{
    mShape.setRadius(20.f);
    mShape.setPosition(mPosition);
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}

bool Plant::shoot()
{
    return false;
}

void Plant::Update()
{
    int a = 0;
}

void Plant::checkCollision(std::vector<Entity*>& mColliding, std::vector<Entity*>& mCollider)
{
    int a = 1;
}
