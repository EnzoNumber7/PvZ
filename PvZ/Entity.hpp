#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Behaviour.hpp"
#include "Context.hpp"
#include <iostream>

class Entity
{
protected:

	int				mHealth;
	sf::Vector2f	mPosition;
	std::string		mName;
	Context::State	mState;
	Behaviour*		mBehaviour;
	sf::Color		mColor;
	sf::CircleShape	mShape;

public:
	Entity(sf::Vector2f position, Behaviour* behaviour, int health, std::string name, sf::Color color) {}

	sf::Color getColor() const { return mColor; }
	sf::Vector2f getPosition() const { return mPosition; }
	Context::State getState() const { return mState; }
	sf::CircleShape getShape() const { return mShape; }
	void setState(Context::State state) { mState = state; }
	void setPosition(sf::Vector2f position) { mPosition = position; }
	virtual void Update() = 0;

	virtual void checkCollision(std::vector<Entity*>& mColliding, std::vector<Entity*>& mCollider) = 0;
};