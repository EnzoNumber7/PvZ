#include <SFML/Graphics.hpp>
#include "Playground.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1300, 800), "PvZ");
    Playground::instantiate();
    Playground::getInstance()->Init(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            Playground::getInstance()->handleUserInput(event, window);
        }

        window.clear();
        Playground::getInstance()->draw(window);
        window.display();
    }

    return 0;
}