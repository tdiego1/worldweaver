/**************************************************************************************************/
/**
* \addtogroup BASE_RENDER
* @{
* \details
* This file provides the public interface for the VertexIndexBuffer Module.
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

#ifndef GFX_RENDER_VERTEX_INDEX_BUFFER_HPP
#define GFX_RENDER_VERTEX_INDEX_BUFFER_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <GLFW/glfw3.h>

#include "gfx/element/gfx_element_vertex.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace GFX
{
    namespace Render
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class VertexIndexBuffer
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the BaseRender.
            */
            VertexIndexBuffer(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Creates the buffers for the vertices and indices.
            * 
            * \param[in] vertices The vertices to create the buffer.
            * \param[in] indices The indices to create the buffer.
            */
            virtual void CreateBuffers(const std::vector<GFX::Element::Vertex>& vertices, const std::vector<uint32_t>& indices) = 0;

            /**************************************************************************************************/
            /**
            * \brief Deletes the buffers for the vertices and indices.
            */
            virtual void DeleteBuffers(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Binds the buffer.
            */
            virtual void Bind(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief UnBinds from the buffer.
            */
            virtual void UnBind(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Draws the buffer.
            * 
            * \param[in] indexCount The index count to draw.
            */
            virtual void Draw(int32_t indexCount) = 0;

        protected:
            /*********************************/
            // Protected member variables
            /*********************************/

            GLuint m_VBO;   // The Vertex Buffer Object (VBO).
            GLuint m_VAO;   // The Vertex Array Object (VAO).
            GLuint m_EBO;   // The Element Buffer Object (EBO).

        };
    }
}

/*=================================================================================================
** 3.3 Constants
**===============================================================================================*/

/*=================================================================================================
** 3.4 Variables
**===============================================================================================*/

/*=================================================================================================
** 3.5 Functions
**===============================================================================================*/
namespace GFX
{
    namespace Render
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline VertexIndexBuffer::VertexIndexBuffer() : m_VBO{ 0 }, m_VAO{ 0 }, m_EBO{ 0 }
        {}
    }
}

#endif
/** @} */