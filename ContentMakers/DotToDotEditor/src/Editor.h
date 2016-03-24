#ifndef EDITOR_H
#define EDITOR_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings for SFML
#include <SFML/Graphics.hpp>
#pragma GCC diagnostic pop // turn the warnings back on

#include <list>

#include "Application.h"
#include "Dot.h"

class Editor
{
    // Méthodes publiques
    public:
        Editor(sf::RenderWindow& window, sf::Texture&, std::string&);
        virtual ~Editor();

        Application::State run();

    // Méthodes protégées
    protected:
        Editor(const Editor&); // Non-implémentée
        Editor& operator=(const Editor&); // Non-implémentée
        bool is_running() const;
        void handle_event(const sf::Event&);
        void render();
        void draw(const Dot&);
        void save() const;

    // Attributs
    protected:
        sf::RenderWindow& _window;
        std::string _filename;
        bool _running;
        sf::Sprite _sprite;
        std::list<Dot> _dots;
        sf::Font _font;
};

#endif // EDITOR_H
