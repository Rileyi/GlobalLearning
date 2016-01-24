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
    // Constantes & énumérations
    public:
        static const int WIDTH, HEIGHT;
        static const std::string NAME;

        enum State {Uninitialized, Running, Exiting};

    // Méthodes publiques
    public:
        Application();
        Application(std::vector<std::string> &args);
        virtual ~Application();

        void start();
        void run();

    // Méthodes
    protected:
        Application(const Application&); // Non-implémentée
        Application& operator=(const Application&); // Non-implémentée

    // Attributs
    protected:
        std::vector<std::string> _args;
        sf::RenderWindow _window;
        State _state;
        sf::Texture _texture;
};

#endif // APPLICATION_H
