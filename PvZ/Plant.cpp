#include "Plant.hpp"
#include "Context.hpp"
#include "IdleAction.h"
#include "ShootAction.h"
#include "WalkAction.h"
#include "Transition.hpp"
#include "Behaviour.hpp"
#include "Projectile.h"
#include "Playground.h"

Plant::Plant(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int health, std::string name, sf::Color color)
    : Entity(position, behaviour, health, name, color)
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

    if (!mTexture.loadFromFile("./rsrc/le_pisto_pois.png"))
    {
        std::cerr << "Error loading texture file!" << std::endl;
        return;
    }

    float scaleX = 40 / static_cast<float>(getTextureSize().x);
    float scaleY = 40 / static_cast<float>(getTextureSize().y);

    mSprite.setScale(scaleX, scaleY);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(mPosition);
    mSprite.setOrigin(getTextureSize().x * 0.5f, getTextureSize().y * 0.5f);

    /*
    mShape.setRadius(20.f);
    mShape.setPosition(mPosition);
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
    mShape.setTexture(&mTexture);
    */
}

bool Plant::shoot()
{
    elapsedTime = clock.getElapsedTime();

    if (mAmmoCount == 0)
        refillMagazine();
    else  if (elapsedTime.asSeconds() >= 1)
    {
        Projectile* proj = new Projectile(sf::Vector2f(mPosition.x + 10, mPosition.y), 2, "Bullet", sf::Color::Magenta);
        Playground::getInstance()->AddProjectile(proj);
        mAmmoCount--;

        clock.restart();
    }

    return true;
}

void Plant::Update()
{
}

void Plant::checkCollision(std::vector<Entity*> mCollider)
{
    int a = 1;
}

void Plant::TakeDamage(int damage)
{
    mHealth -= damage;
}
