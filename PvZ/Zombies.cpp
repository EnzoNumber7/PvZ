#include "Zombies.h"
#include "WalkAction.h"
#include "Transition.hpp"
#include "AttackCondition.h"
#include "AttackAction.h"

Zombies::Zombies(sf::Vector2f position, Behaviour* behaviour, int ammo_count, int speed, int health, std::string name, sf::Color color) : Entity(position, behaviour, health, name, color)
{
    mBehaviour = behaviour;
    mPosition = position;
    mHealth = health;
    mName = name;
    mColor = color;
    mState = Context::State::Attack;

    /*
    // -- ZOMBIE WALK STATE -- //
    Action* walkAction = (Action*)(new WalkAction());
    mWalkTransition->addCondition(new AttackCondition());
    mWalkTransition->setTargetState(Context::State::Walk);
    mBehaviour->AddTransition(Context::State::Walk, mWalkTransition);
    mBehaviour->AddAction(Context::State::Walk, walkAction);

    // -- ZOMBIE ATTACK STATE -- //
    Action* attackAction = (Action*)(new AttackAction());
    mWalkTransition->addCondition(new AttackCondition());
    mWalkTransition->setTargetState(Context::State::Walk);
    mBehaviour->AddTransition(Context::State::Walk, mWalkTransition);
    mBehaviour->AddAction(Context::State::Walk, walkAction);
    */
}

Zombies::~Zombies()
{
}

void Zombies::Init(int posY)
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
    mShape.setPosition(sf::Vector2f(mPosition.x, (50 + posY)));
    mShape.setFillColor(mColor);
    mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
    */
}

void Zombies::Update()
{
    int a = 0;
}

void Zombies::checkCollision(std::vector<Entity*>& mColliding, std::vector<Entity*>& mCollider)
{
    int a = 1;
}

void Zombies::Attack(Plant* plant)
{
    int a = 2;
}
