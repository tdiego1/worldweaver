/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Input Module.
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

#include "gfx/gfx_common.hpp"

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
        namespace Input
        {
            /**************************************************************************************************/
            /**
            * \brief The keyboard input buttons.
            */
            enum class EInputButton
            {
                LEFT = 0,
                RIGHT = 1,
                MIDDLE = 2,
                NONE = 9
            };

            /**************************************************************************************************/
            /**
            * \brief Gets the button that was pressed.
            * 
            * \param[in] window The window that the button was pressed in.
            * 
            * \retval EInputButton The button that was pressed.
            */
            EInputButton GetPressedButton(GLFWwindow* window);


        }
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

/** @} */