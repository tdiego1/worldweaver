/**************************************************************************************************/
/**
* \addtogroup BASE_RENDER
* @{
* \details
* This file provides the public interface for the RenderContext Module.
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

#include "gfx/gfx_window.hpp"

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
        class RenderContext
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the <RenderContext>.
            */
            RenderContext(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Initializes the RenderContext.
            * 
            * \param[in] window The window to initialize the RenderContext with.
            * 
            * \retval True if the RenderContext was initialized successfully.
            */
            virtual bool Initialize(GFX::Window::BaseWindow* window);

            /**************************************************************************************************/
            /**
            * \brief Begins the RenderContext.
            */
            virtual void PreRender(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Post Render functions.
            */
            virtual void Render(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Ends the RenderContext.
            */
            virtual void End(void) = 0;

        protected:
            /*********************************/
            // Protected member variables
            /*********************************/

            GFX::Window::BaseWindow* m_Window;  // The window to render.

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
        inline RenderContext::RenderContext() : m_Window(nullptr)
        {}

        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline bool RenderContext::Initialize(GFX::Window::BaseWindow* window)
        {
            m_Window = window;
            return true;
        }
    }
}

/** @} */