#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Lane.h"

Lane::Lane(sf::Vector2f pos, sf::Vector2f size)
{
	mSize = size;
	mPos = pos;
}

Lane::~Lane()
{
}

void Lane::Init()
{
	mLine.setPosition(mPos);
	mLine.setSize(mSize);
	mLine.setFillColor(sf::Color::Black);
}
