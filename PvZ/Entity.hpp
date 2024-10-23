#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
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

	sf::Color mColor;

	Entity(sf::Vector2f position, Behaviour* behaviour, int health, std::string name) { };

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
	virtual void Update() = 0;
};