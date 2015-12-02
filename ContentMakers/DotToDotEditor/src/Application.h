#ifndef APPLICATION_H
#define APPLICATION_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings for SFML
#include <SFML/Graphics.hpp>
#pragma GCC diagnostic pop // turn the warnings back on

#include <thread>
#include <vector>
#include <string>

class Application
{
    // Constantes & �num�rations
    public:
        static const int WIDTH, HEIGHT;
        static const std::string NAME;

        enum State {Uninitialized, Running, Exiting};

    // M�thodes publiques
    public:
        Application();
        Application(std::vector<std::string> &args);
        virtual ~Application();

        void start();
        void run();

    // M�thodes
    protected:
        Application(const Application&); // Non-impl�ment�e
        Application& operator=(const Application&); // Non-impl�ment�e

    // Attributs
    protected:
        std::vector<std::string> _args;
        sf::RenderWindow _window;
        State _state;
        sf::Texture _texture;
};

#endif // APPLICATION_H
