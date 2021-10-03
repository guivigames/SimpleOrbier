#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <memory>
#include "UtilMath.hpp"
#include "TextureManager.h"

TextureManager g_textureManager;

#include "Planet.hpp"

const int width = 800;
const int height = 600;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode( width, height), "Oriter");

    Planet planet( sf::Vector2f{width/2, height/2}, 30);
    Planet player( sf::Vector2f{width/4, height/4}, 5);
    
    bool running = false;

    sf::Clock timer;
    while (window.isOpen())
    {
        sf::Time dt = timer.restart();  ///< Frame rate controller.
        float At = dt.asSeconds();
        // Catch events.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the current mouse position in the window.
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        // convert it to world coordinates.
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

        // Update renderer.
        window.clear();
        if (!running){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                running = true;
                player.SetAccel(At*((player.GetPos()+player.GetRadius())-worldPos));
            }

            sf::Vertex line[] =
            {
                sf::Vertex((player.GetPos()+player.GetRadius())+((player.GetPos()+player.GetRadius()))-worldPos),
                sf::Vertex(player.GetPos() + player.GetRadius())
            };
            window.draw(line, 2, sf::Lines);
        }
        else {
            sf::Vector2f gCentre = planet.GetPos()+planet.GetRadius();
            sf::Vector2f diff = gCentre - (player.GetPos()+player.GetRadius());
            float h = ((float)pow(pow(diff.x, 2)+pow(diff.y, 2), 0.5));
            sf::Vector2f accel = sf::Vector2f{  At*diff.x/h,  At*diff.y/h};
            player.SetAccel(player.GetAccel()+accel);
            player.SetPos(player.GetPos() + player.GetAccel());
        }

        player.Draw(window);
        planet.Draw(window);
        window.display();
    }

    
    return 0;
}