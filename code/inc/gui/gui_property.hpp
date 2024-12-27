/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the Property Module.
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

#ifndef GUI_PROPERTY_HPP
#define GUI_PROPERTY_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <functional>
#include <string>

#include "imgui.h"
#include <ImFileBrowser.h>

#include "gui/gui_glview.hpp"

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
        class PropertyPanel
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the PropertyPanel.
            */
            PropertyPanel(void);

            /**************************************************************************************************/
            /**
            * \brief The default destructor for the PropertyPanel.
            */
            ~PropertyPanel(void) = default;

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Renders the Property Panel.
            */
            void Render(WorldWeaver::GUI::GLView* sceneView);

            /**************************************************************************************************/
            /**
            * \brief Sets the mesh load callback.
            * 
            * \param[in] callback The mesh load callback.
            */
            void SetMeshLoadCallback(const std::function<void(const std::string&)>& callback);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            ImGui::FileBrowser m_FileBrowser;                           // The file browser.
            std::function<void(const std::string&)> m_MeshLoadCallback; // The mesh load callback.
            std::string m_CurrentFile;                                  // The path to the current file.

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