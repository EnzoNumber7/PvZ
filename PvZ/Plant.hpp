#pragma once
#include "Entity.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Plant : public Entity
{
   
    int mAmmoCount, mMaxAmmo;
   
public:

    Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int health, std::string name);
    ~Plant();

    void setState(Context::State state);
    Context::State getState() const;


    int getAmmoCount() const;
    void refillMagazine() ;

    bool shoot();
};
