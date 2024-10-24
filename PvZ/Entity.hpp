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
	sf::Vector2f	mShapeRadius;
	std::string		mName;
	Context::State	mState;
	Behaviour*		mBehaviour;
	sf::Color		mColor;
	sf::CircleShape	mShape;
	sf::Texture		mTexture;
	sf::Vector2u	mTextureSize;
	sf::Sprite		mSprite;
	int				mRadius = 20;

public:
	Entity(sf::Vector2f position, Behaviour* behaviour, int health, std::string name, sf::Color color) {}

	sf::Color getColor() const { return mColor; }
	int getHp() const { return mHealth; }
	sf::Vector2f getPosition() const { return mPosition; }
	sf::Vector2f getOrigin() const { return mShape.getOrigin(); }
	Context::State getState() const { return mState; }
	sf::CircleShape getShape() const { return mShape; }
	sf::Texture		getTexture() const { return mTexture; }
	sf::Sprite		getSprite() const { return mSprite; }
	sf::Vector2u	getTextureSize() { mTextureSize = mTexture.getSize(); return mTextureSize; }
	void setState(Context::State state) { mBehaviour->End(this); mState = state; mBehaviour->Start(this); };
	void setPosition(sf::Vector2f position) { mPosition = position; }
	virtual void Update() = 0;

	virtual void checkCollision(std::vector<Entity*> mCollider) = 0;
};