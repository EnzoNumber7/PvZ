#include "Plant.hpp"
#include "Context.hpp"

Plant::Plant(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int health, std::string name, sf::Color color)
    : Entity(mPosition, behaviour, health,name, color)
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

bool Plant::shoot()
{
    return false;
}

void Plant::Update()
{
    int a = 0;
}
