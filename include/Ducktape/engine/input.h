/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>
#include <vector>
#include <Ducktape/engine/vector2.h>
#include <Ducktape/engine/application.h>

typedef sf::Keyboard::Key KeyCode;

namespace DT
{
    namespace Input
    {
        extern std::vector<KeyCode>keyUpList;
        extern std::vector<KeyCode>keyDownList;
        extern Vector2 mousePosition;

        bool GetMouseButton(int num);

        bool GetKey(KeyCode k);

        bool GetKeyUp(KeyCode k);

        bool GetKeyDown(KeyCode k);

        void Update();
    };
}

#endif