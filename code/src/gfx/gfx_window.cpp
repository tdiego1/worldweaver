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
WorldWeaver::Window::GFXWindow::GFXWindow() :
    m_Window(nullptr),
    m_IsRunning(true)
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
bool WorldWeaver::Window::GFXWindow::Initialize(int32_t width, int32_t height, const std::string& title)
{
    return true;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::Render()
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::HandleInput()
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void* WorldWeaver::Window::GFXWindow::GetNativeWindow()
{
    return m_Window;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::SetNativeWindow(void* window)
{
    m_Window = static_cast<GLFWwindow*>(window);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::OnScroll(double delta)
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::OnKey(int32_t key, int32_t scanCode, int32_t action, int32_t mods)
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::OnResize(int32_t width, int32_t height)
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::Window::GFXWindow::OnClose()
{

}

/**************************************************************************************************/
/**
* \par Details: 
*/
bool WorldWeaver::Window::GFXWindow::IsRunning()
{
    return m_IsRunning;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */