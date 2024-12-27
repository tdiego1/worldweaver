/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Light Module.
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

#pragma once

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/element/gfx_element.hpp"

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
        class Light : public Element
        {

        public:
            /*********************************/
            // Public member variables
            /*********************************/

            glm::vec3 m_Position;   // The position of the light.
            glm::vec3 m_Color;      // The color of the light.
            float32_t m_Intensity;  // The intensity of the light.

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the Light.
            */
            Light(void);

            /**************************************************************************************************/
            /**
            * \brief The default destructor for the Light.
            */
            ~Light(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Updates the light.
            * 
            * \param[in] shader The shader to update.
            */
            void Update(GFX::Util::Shader* shader) override;

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
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline Light::~Light(){}
    }
}

/** @} */