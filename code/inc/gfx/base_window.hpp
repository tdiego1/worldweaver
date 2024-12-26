/**************************************************************************************************/
/**
* \addtogroup BASE_WINDOW
* @{
* \details
* This file provides the public interface for the BaseWindow Module.
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

#ifndef BASE_WINDOW_HPP
#define BASE_WINDOW_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/
#include <cstdint>
#include <string>

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
        class BaseWindow
        {

        public:
            /*********************************/
            // Public type definitions
            /*********************************/

            /*********************************/
            // Public member variables
            /*********************************/

            int32_t m_Width;
            int32_t m_Height;
            std::string m_Title;

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Gets the Native window.
            * 
            * \retval void* The native window.
            */
           virtual void* GetNativeWindow(void) = 0;

           /**************************************************************************************************/
           /**
           * \brief Sets the native window.
           * 
           * \param[in] window The native window.
           */
           virtual void SetNativeWindow(void* window) = 0;

           /**************************************************************************************************/
           /**
           * \brief Called when scroll is registered.
           * 
           * \param[in] delta The scroll delta.
           */
           virtual void OnScroll(double delta) = 0;

           /**************************************************************************************************/
           /**
           * \brief Called when a key is pressed.
           * 
           * \param[in] key The key pressed.
           * \param[in] scanCode The scan code of the key.
           * \param[in] action The action of the key.
           * \param[in] mods The mods of the key.
           */
           virtual void OnKey(int32_t key, int32_t scanCode, int32_t action, int32_t mods) = 0;

           /**************************************************************************************************/
           /**
           * \brief Called when the window is resized.
           * 
           * \param[in] width The width of the window.
           * \param[in] height The height of the window.
           */
           virtual void OnResize(int32_t width, int32_t height) = 0;

           /**************************************************************************************************/
           /**
           * \brief Called when the window is closed.
           */
           virtual void OnClose(void) = 0;
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