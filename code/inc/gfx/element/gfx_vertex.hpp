/**************************************************************************************************/
/**
* \addtogroup ELEMENTS
* @{
* \details
* This file provides the public interface for the Vertex Module.
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

#ifndef GFX_ELEMENT_VERTEX_HPP
#define GFX_ELEMENT_VERTEX_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <string>

#include <glm/glm.hpp>

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
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Vertex
        {

        public:
            /*********************************/
            // Public type definitions
            /*********************************/

            /*********************************/
            // Public member variables
            /*********************************/

            glm::vec3 m_Position;
            glm::vec3 m_Normal;

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the Vertex.
            */
            Vertex(void);

            /**************************************************************************************************/
            /**
            * \brief Initialize the vertex by string to be tokenized.
            * 
            * \param[in] tokens The tokens to initialize the vertex.
            */
            Vertex(const std::vector<std::string> tokens);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            Vertex(const glm::vec3& position, const glm::vec3& normal);

            /**************************************************************************************************/
            /**
            * \brief The defaiult destructor for the Vertex.
            */
            ~Vertex(void) = default;

            /*********************************/
            // Public functions
            /*********************************/

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

#endif
/** @} */