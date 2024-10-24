#include "Zombies.h"
#include "WalkAction.h"
#include "Transition.hpp"

Zombies::Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color) : Entity(position, behaviour, health, name, color)
{
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mColor = color;
    mState = Context::State::Walk;

}

Zombies::~Zombies()
{
}

void Zombies::Init()
{

    if (!mTexture.loadFromFile("./rsrc/le_zombig.png"))
    {
        std::cerr << "Error loading texture file!" << std::endl;
        return;
    }

    float scaleX = 40 / static_cast<float>(getTextureSize().x);
    float scaleY = 40 / static_cast<float>(getTextureSize().y);

    mSprite.setScale(scaleX, scaleY);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(sf::Vector2f(mPosition.x, (50 + posY)));
    mSprite.setOrigin(getTextureSize().x * 0.5f, getTextureSize().y * 0.5f);

    /*
    mShape.setRadius(20.f);
    mShape.setPosition(sf::Vector2f(mPosition.x, mPosition.y));
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
    */
}

void Zombies::Update()
{
    mShape.setPosition(getPosition());
}

void Zombies::checkCollision(std::vector<Entity*> mCollider)
{
    int a = 1;
}

void Zombies::Attack(Plant* plant)
{
    elapsedTime = clock.getElapsedTime();

    if (elapsedTime.asSeconds() >= 1)
    {
        plant->TakeDamage(1);

        clock.restart();
    }
}
