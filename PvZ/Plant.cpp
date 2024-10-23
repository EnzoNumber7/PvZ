#include "Plant.hpp"

Plant::Plant()
{

}

Plant::Plant(sf::Vector2f position,
    Behaviour* plant_behaviour,
    int ammo_count)
{
    mAmmoCount = ammo_count;
    mMaxAmmo = ammo_count;
    mBehaviour = plant_behaviour;
    mPosition = position;
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

sf::Color Plant::getColor() const
{
    // oui
}

sf::Vector2f Plant::getPosition() const
{
    return mPosition;
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

}

void Plant::Update()
{

}