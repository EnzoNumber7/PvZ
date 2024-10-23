#pragma once
class Lane
{
private:
	sf::Vector2f mSize;
	sf::Vector2f mPos;
	sf::RectangleShape mLine;

public:

	Lane(sf::Vector2f pos, sf::Vector2f size);
	~Lane();

	void Init();

	sf::Vector2f getSize() { return mSize; }
	sf::Vector2f getPosition() { return mPos; }
	sf::RectangleShape getShape() { return mLine; }
};

