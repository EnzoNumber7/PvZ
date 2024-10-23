#pragma once
#include "Entity.hpp"
#include "Context.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Plant : Entity
{
   
    int mAmmoCount, mMaxAmmo;
   
public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant();

    void setState(Context::State);
    Context::State getState() const;


    int getAmmoCount() const;
    void refillMagazine() ;

    bool shoot();

    void Update();
};
