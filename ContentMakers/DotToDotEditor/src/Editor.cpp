#include "Editor.h"

#include <iostream>
#include <fstream>

/**
 * Constructeur à partir d'une fenêtre
 */
Editor::Editor(sf::RenderWindow &window, sf::Texture &texture, std::string& filename) : _window(window), _filename(filename), _running(true), _sprite(), _dots(), _font()
{
    _sprite.setTexture(texture);
    _font.loadFromFile("arial.ttf");
}

/**
 * Destructeur
 */
Editor::~Editor()
{
}


/**
 * Boucle principale du Jeu
 * Renvoie à l'application le Application::State suivant
 */
Application::State Editor::run()
{
    render();
    // on fait tourner la boucle principale
    while (_running)
    {
        // on gère les évènements
        sf::Event event;
        while (_window.pollEvent(event))
        {
            handle_event(event);
        }
    }
    save();
    return Application::State::Exiting;
}

/**
 * Fonction qui gère les évènements
 */
void Editor::handle_event(const sf::Event& event)
{
    if(event.type == sf::Event::Closed)
    {
        _running = false;
    }
    if (event.type == sf::Event::KeyPressed)
    {
        // Press Return to exit the editor
        if (event.key.code == sf::Keyboard::Return)
        {
            _running = false;
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i pixel_pos = sf::Mouse::getPosition(_window); // récupération de la position de la souris dans la fenêtre
            sf::Vector2f world_pos = _window.mapPixelToCoords(pixel_pos); // conversion en coordonnées "monde"
            // Add a dot to the list
            Dot dot(_dots.size(), world_pos);
            _dots.push_back(dot);
            std::cout << dot << std::endl;
            render();
        }
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            // Remove the last dot
            if (_dots.empty() == false)
            {
                _dots.pop_back();
                std::cout << "Last dot removed" << std::endl;
                render();
            }
        }
    }
}

void Editor::render()
{
    _window.draw(_sprite);
    for (auto it = _dots.begin(); it != _dots.end(); it++)
        draw(*it);
    _window.display();
}

void Editor::draw(const Dot &dot)
{
    // Cross
    sf::RectangleShape horizontal(sf::Vector2f(7, 3)), vertical(sf::Vector2f(3, 7));
    horizontal.setPosition(dot.get_pos().x-3, dot.get_pos().y-1);
    vertical.setPosition(dot.get_pos().x-1, dot.get_pos().y-3);
    // Text
    sf::Text text(std::to_string(dot.get_number()), _font);
    text.setCharacterSize(12);
    text.setPosition(dot.get_pos().x - 5, dot.get_pos().y - 18);
    // Colors
    horizontal.setFillColor(sf::Color::Red);
    vertical.setFillColor(sf::Color::Red);
    text.setColor(sf::Color::Black);
    // Draw
    _window.draw(horizontal);
    _window.draw(vertical);
    _window.draw(text);
}

void Editor::save() const
{
    std::ofstream file(_filename + ".dots.xml");

    std::cout << "Saving..." << std::endl;
    if (file.is_open())
    {
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>" << std::endl;
        file << "<exercice type=\"dot-to-dot\">" << std::endl;
            // Requirements
            file << "\t<requirements>" << std::endl;
            file << "\t\t<subject type=\"arithmetic\" value=\"0\"/>" << std::endl;
            file << "\t\t<move type=\"drag-and-drop\ value=\"0\"/>" << std::endl;
            file << "\t</requirements>" << std::endl;
            // Learnings
            file << "\t<learnings>" << std::endl;
            file << "\t\t<subject type=\"arithmetic\" experience=\"0\"/>" << std::endl;
            file << "\t\t<move type=\"drag-and-drop\ experience=\"0\"/>" << std::endl;
            file << "\t</learnings>" << std::endl;
            // Content
            file << "\t<content>" << std::endl;
            file << "\t\t<background filename=\"" << _filename << "\"/>" << std::endl;
            // Dots
            for (auto it = _dots.begin(); it != _dots.end(); it++)
            {
                file << "\t\t";
                file << (*it) << std::endl;
            }
            file << "\t</content>" << std::endl;
        file << "</exercice>" << std::endl;
        file.close();
    }
    else
        std::cout << "Saving failed" << std::endl;
}


