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
	Entity(sf::Vector2f position, Behaviour* behaviour, int health, std::string name, sf::Color color) 
	{
		position = { 0, 0 }, behaviour = nullptr, health = 0, name = "", color = sf::Color::Green;
	};

	sf::Color getColor() const { return mColor; }
	sf::Vector2f getPosition() const { return mPosition; }
	Context::State getState() const { return mState; }
	void setState(Context::State state) { mState = state; }
	virtual void Update() = 0;
};