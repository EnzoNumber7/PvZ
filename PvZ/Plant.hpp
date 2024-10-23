#pragma once
#include "Entity.hpp"
#include "Behaviour.hpp"
#include <iostream>

class Plant : public Entity
{
    int mAmmoCount, mMaxAmmo;
   
public:

    Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int health, std::string name, sf::Color color);
    ~Plant();

    int getAmmoCount() const;
    void refillMagazine() ;

    bool shoot();

    void Update() override;
};
