/*
Ducktape | An open source C++ 2D & 3D game engine that focuses on being fast, and powerful.
Copyright (C) 2022 Aryan Baburajan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

In case of any further questions feel free to contact me at
the following email address:
aryanbaburajan2007@gmail.com
*/

#include <Core/Window.h>

namespace DT
{
    void Window::Init()
    {
        FT("Window::Init()");

        window.create(sf::VideoMode(Configuration::windowSize.x, Configuration::windowSize.y), Configuration::windowTitle, sf::Style::Default);
    }

    void Window::Clear()
    {
        window.clear(sf::Color::Black);
    }

    void Window::Tick()
    {
        FT("Window::Tick()");

        window.display();
    }

    glm::vec2 Window::GetResolution()
    {
        FT("Window::GetResolution()");

        return glm::vec2(window.getSize().x, window.getSize().y);
    }

    void Window::SetResolution(glm::vec2 resolution)
    {
        FT("Window::SetResolution()");

        window.setSize(sf::Vector2u(resolution.x, resolution.y));
        view.setSize(sf::Vector2f(resolution.x, resolution.y));
        window.setView(view);
    }
}