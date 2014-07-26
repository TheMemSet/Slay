#include <SFML/Graphics.hpp>
#include <iostream>
#include "HexGrid.hpp"

int main()
{
    sf::RenderWindow window (sf::VideoMode (640, 480), "Temporary title");
    window.setFramerateLimit (30);

    sf::Event ev;

    sf::Color backgroundColor = sf::Color (51, 153, 153);

    while (window.isOpen ())
    {
        while (window.pollEvent (ev))
        {
            if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
                window.close ();
            if (ev.type == sf::Event::Closed)
                window.close ();
        }

        window.clear (backgroundColor);
        window.display ();
    }
    return 0;
}
