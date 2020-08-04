#include <SFML/Graphics.hpp>
#include "save_data/File.h"
#include "save_data/save.h"
#include <iostream>

int main()
{
    // Create the main window
    initFS();
    sf::RenderWindow app(sf::VideoMode(800, 600), "Tree Game Window");
    Player();
    save();

    // Start the game loop

    while (app.isOpen())
    {
        // Process events
        sf::Event event{};
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Update the window
        app.display();
    }


    return EXIT_SUCCESS;
}
