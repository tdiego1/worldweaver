/**************************************************************************************************/
/**
* \addtogroup GFX_RENDER
* @{
* \details
* This file provides the public interface for the GLVertexBuffer Module.
* 
* \par COPYRIGHT
* Copyright (C) 2024 Diego Torres. All rights reserved.
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************************************/

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/gfx_glvibuffer.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types
**===============================================================================================*/

/*=================================================================================================
** 3.3 External global variables
**===============================================================================================*/

/*=================================================================================================
** 3.4 Static global variables
**===============================================================================================*/

/*=================================================================================================
** 3.5 Static function prototypes
**===============================================================================================*/

/*=================================================================================================
** 4.  PUBLIC FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
GFX::Render::GLVertexBuffer::GLVertexBuffer()
{
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLVertexBuffer::CreateBuffers(const std::vector<GFX::Element::Vertex>& vertices, const std::vector<uint32_t>& indices)
{
    glGenVertexArrays(1, &m_VAO);

    glGenBuffers(1, &m_EBO);
    glGenBuffers(1, &m_VBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GFX::Element::Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GFX::Element::Vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GFX::Element::Vertex), (void*)offsetof(GFX::Element::Vertex, m_Normal));

    glBindVertexArray(0);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLVertexBuffer::DeleteBuffers(void)
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &m_EBO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLVertexBuffer::Bind(void)
{
    glBindVertexArray(m_VAO);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLVertexBuffer::UnBind(void)
{
    glBindVertexArray(0);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLVertexBuffer::Draw(int32_t indexCount)
{
    Bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    UnBind();
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */