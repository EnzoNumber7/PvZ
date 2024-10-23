#include "Plant.hpp"
#include "Context.hpp"

Plant::Plant(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int health, std::string name)
    : Entity(mPosition, behaviour, health,name)
{
    mAmmoCount = ammo_count;
    mMaxAmmo = ammo_count;
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mState = Context::State::Idle;
}

Plant::~Plant()
{

}

void Plant::setState(Context::State state)
{
    mState = state;
}

Context::State Plant::getState() const
{
    return mState;
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