/**************************************************************************************************/
/**
* \addtogroup GFX_WINDOW
* @{
* \details
* This file provides the public interface for the GFXWindow Module.
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

#ifndef GFX_WINDOW_HPP
#define GFX_WINDOW_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <glfw/glfw3.h>

#include "window/base_window.hpp"

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
    namespace Window
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class GFXWindow : public BaseWindow
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
            * \brief The default constructor for the GFXWindow.
            */
            GFXWindow(void);

            /**************************************************************************************************/
            /**
            * \brief The defaiult destructor for the GFXWindow.
            */
            ~GFXWindow(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Initializes the OpenGL window.
            * 
            * \param[in] width  The width of the window.
            * \param[in] height The height of the window.
            * \param[in] title  The title of the window.
            * 
            * \retval True if the window was initialized successfully.
            * \retval False if the window was not initialized successfully.
            */
            bool Initialize(int32_t width, int32_t height, const std::string& title);

            /**************************************************************************************************/
            /**
             * \brief Renders the OpenGL window.
             */
            void Render(void);

           /**************************************************************************************************/
           /**
           * \brief Handles input for the OpenGL window.
           */
            void HandleInput(void);

           /**************************************************************************************************/
           /**
           * \brief Gets the Native window.
           * 
           * \retval void* The native window.
           */
            void* GetNativeWindow(void) override;

           /**************************************************************************************************/
           /**
           * \brief Sets the native window.
           * 
           * \param[in] window The native window.
           */
            void SetNativeWindow(void* window) override;

           /**************************************************************************************************/
           /**
           * \brief Called when scroll is registered.
           * 
           * \param[in] delta The scroll delta.
           */
            void OnScroll(double delta) override;

           /**************************************************************************************************/
           /**
           * \brief Called when a key is pressed.
           * 
           * \param[in] key      The key pressed.
           * \param[in] scanCode The scan code of the key.
           * \param[in] action   The action of the key.
           * \param[in] mods     The mods of the key.
           */
            void OnKey(int32_t key, int32_t scanCode, int32_t action, int32_t mods) override;

           /**************************************************************************************************/
           /**
           * \brief Called when the window is resized.
           * 
           * \param[in] width  The width of the window.
           * \param[in] height The height of the window.
           */
            void OnResize(int32_t width, int32_t height) override;

           /**************************************************************************************************/
           /**
           * \brief Called when the window is closed.
           */
            void OnClose(void) override;

           /**************************************************************************************************/
           /**
           * \brief Determines if the window is running.
           * 
           * \retval True if the window is running.
           * \retval False if the window is not running.
           */
            bool IsRunning(void);

        private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/

            GLFWwindow* m_Window;   // The GLFW window.
            bool m_IsRunning;         // The running state of the window.

            // Render Contexts

            // UI Components

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
namespace WorldWeaver
{
    namespace Window
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline GFXWindow::~GFXWindow(){}
    }
}

#endif
/** @} */