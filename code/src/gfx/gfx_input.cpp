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

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/element/gfx_input.hpp"

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
GFX::Element::Input::EInputButton GFX::Element::Input::GetPressedButton(GLFWwindow* window)
{
    EInputButton result = EInputButton::NONE;

    if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
    {
        return EInputButton::LEFT;
    }
    else if (glfwGetMouseButton(window, 1) == GLFW_PRESS)
    {
        return EInputButton::RIGHT;
    }
    else if (glfwGetMouseButton(window, 2) == GLFW_PRESS)
    {
        return EInputButton::MIDDLE;
    }

    return EInputButton::NONE;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */