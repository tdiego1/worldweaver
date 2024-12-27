/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the GUIHelper Module.
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

#include "imgui.h"
#include "imgui_internal.h"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace WorldWeaver
{
    namespace GUI
    {
        namespace Helper
        {
            /**************************************************************************************************/
            /**
            * \brief Draws an ImGui widget for a glm::vec3.
            * 
            * \param[in] label The label for the widget.
            * \param[in] values The values for the widget.
            * \param[in] resetValue The value to reset the widget to.
            * \param[in] columnWidth The width of the column.
            */
            void DrawVector3Widget(const std::string& label, glm::vec3& values);
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