/**************************************************************************************************/
/**
* \addtogroup RENDER
* @{
* \details
* This file provides the public interface for the GLContext Module.
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

#ifndef GFX_RENDER_GLCONTEXT_HPP
#define GFX_RENDER_GLCONTEXT_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/gfx_rendercontext.hpp"

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
        class GLContext : public RenderContext
        {

        public:
            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Initializes the GLContext.
            * 
            * \param[in] window The window to initialize the GLContext with.
            * 
            * \retval True if the GLContext was initialized successfully.
            * \retval False if the GLContext was not initialized successfully.
            */
            bool Initialize(GFX::Window::BaseWindow* window) override;

            /**************************************************************************************************/
            /**
            * \brief Sets up the GLContext for rendering.
            */
            void PreRender(void) override;

            /**************************************************************************************************/
            /**
            * \brief Renders the GLContext.
            */
            void Render(void) override;

            /**************************************************************************************************/
            /**
            * \brief Cleans up and ends the GLContext.
            */
            void End(void) override;

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