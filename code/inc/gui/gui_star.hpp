/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the StarPanel Module.
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

#include "worldweaver/common.hpp"
#include "worldweaver/star.hpp"

#include "gui/gui_glview.hpp"

#include "imgui.h"

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
        /**************************************************************************************************/
        /**
         * \par Details:
         */
        class StarPanel
        {

          public:
            /*********************************/
            // Public type definitions
            /*********************************/

            /*********************************/
            // Public member variables
            /*********************************/

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
             * \brief The default constructor for the StarPanel.
             */
            StarPanel(void);

            /**************************************************************************************************/
            /**
             * \brief The default destructor for the StarPanel.
             */
            ~StarPanel(void) = default;

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
             * \brief
             *
             * \param[in]
             *
             * \retval
             */
            void Render(WorldWeaver::GUI::GLView* glView);

            /**************************************************************************************************/
            /**
             * \brief Sets the mesh load callback.
             *
             * \param[in] callback The mesh load callback.
             */
            void SetMeshLoadCallback(const std::function<void(const std::string&)>& callback);

          private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/

            /*********************************/
            // Private functions
            /*********************************/

            WorldWeaver::Model::Star m_CurrentStar;
            std::function<void(const std::string&)> m_MeshLoadCallback;   // The mesh load callback.
        };
    }   // namespace GUI
}   // namespace WorldWeaver

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