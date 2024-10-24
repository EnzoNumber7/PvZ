#pragma once
#include "Entity.hpp"
#include <iostream>

class Transition;
class Behavior;

class Plant : public Entity
{
    int mAmmoCount, mMaxAmmo;
 
    sf::Clock clock;
    sf::Time elapsedTime;

public:

    Plant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int health, std::string name, sf::Color color);
    ~Plant();

    int getAmmoCount() const;
    void refillMagazine();

    void Init();

    bool shoot();

    void Update() override;
    void checkCollision(std::vector<Entity*> mCollider) override;
    void TakeDamage(int damage);

    
};
