#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

class Entity
{
	sf::Vector2f	mPosition;
	std::string		mName;
	int				mHealth;
	Context::State mState;
	Behaviour* mBehaviour;

	sf::Color mColor;

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
};