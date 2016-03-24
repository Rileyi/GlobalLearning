#include "Application.h"

#include <iostream>
#include <string>

#include "Editor.h"

const int Application::WIDTH = 291;
const int Application::HEIGHT = 327;
const std::string Application::NAME = "Dot-to-Dot Editor";

/**
 * Constructeur par défaut
 */
Application::Application() : _args(), _window(), _state(State::Uninitialized), _texture()
{
}

/**
 * Constructeur avec arguments
 */
Application::Application(std::vector<std::string> &args) : _args(args), _window(), _state(State::Uninitialized), _texture()
{
}

/**
 * Destructeur
 */
Application::~Application()
{
}

/**
 * Initialise l'application
 */
void Application::start()
{
    if (_state != State::Uninitialized)
        return;
    if (_args.size() != 2)
    {
        std::cout << "Wrong number of arguments.\nParameter 1 must be the image path." << std::endl;
        return;
    }
    if (_texture.loadFromFile(_args[1]) == false)
        return;
    _window.create(sf::VideoMode(_texture.getSize().x, _texture.getSize().y), NAME, sf::Style::Close | sf::Style::Titlebar);
    _window.setVerticalSyncEnabled(true);
    _window.setKeyRepeatEnabled(false);
    _state = State::Running;
    run();
}

/**
 * Boucle principale de l'application
 */
void Application::run()
{
    if (_state != State::Running)
        return;

    Editor editor(_window, _texture, _args[1]);
    // on fait tourner la boucle principale
    while (_state != State::Exiting)
    {
        _state = editor.run();
    }
    _window.close();
}

