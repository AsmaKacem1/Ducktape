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

#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Renderer/Shader.h>
#include <Core/Window.h>
#include <Core/Macro.h>
#include <Renderer/Texture.h>
#include <Renderer/Color.h>
#include <Components/Transform.h>

namespace Ducktape
{
    class Renderer
    {
    public:
        bool renderWireframe = false;
        glm::mat4 projection = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);

        Shader shader;

        Window *window;

        void Init(Window &window);
        void Flush();
        void Clear();

        void DrawQuad(const glm::vec2 &position, const float &rotation, const glm::vec2 &scale, const Color &color, Texture &texture, unsigned int &VAO, const Transform &camera);
    };
}