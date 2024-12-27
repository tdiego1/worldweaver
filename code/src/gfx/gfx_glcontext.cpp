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

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/gfx_glcontext.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdint.h>

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

/**************************************************************************************************/
/**
* \brief The callback for the key event.
* 
* \param[in] window     The window that the key event occurred.
* \param[in] key        The key that was pressed.
* \param[in] scanCode   The scan code of the key.
* \param[in] action     The action of the key.
* \param[in] mods       The mods of the key.
*/
static void OnKeyCallback(GLFWwindow* window, int32_t key, int32_t scanCode, int32_t action, int32_t mods);

/**************************************************************************************************/
/**
* \brief The callback for the scroll event.
* 
* \param[in] window     The window that the scroll event occurred.
* \param[in] xOffset    The x offset of the scroll.
* \param[in] yOffset    The y offset of the scroll.
*/
static void OnScrollCallback(GLFWwindow* window, float64_t xOffset, float64_t yOffSet);

/**************************************************************************************************/
/**
* \brief The callback for the resize event.
* 
* \param[in] window The window that the resize event occurred.
* \param[in] width  The width of the window.
* \param[in] height The height of the window.
*/
static void OnResizeCallback(GLFWwindow* window, int32_t width, int32_t height);

/**************************************************************************************************/
/**
* \brief The callback for the close event.
* 
* \param[in] window The window that the close event occurred.
*/
static void OnCloseCallback(GLFWwindow* window);

/*=================================================================================================
** 4.  PUBLIC FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
bool GFX::Render::GLContext::Initialize(GFX::Window::BaseWindow* window)
{
    GFX::Render::RenderContext::Initialize(window);

    // Initialize the library
    if (!glfwInit())
    {
        fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
        return false;
    }

    // Create the window and store this window as window pointer
    // so that we can use it in callback functions
    GLFWwindow* gl_window = glfwCreateWindow(window->m_Width, window->m_Height, window->m_Title.c_str(), nullptr, nullptr);
    window->SetNativeWindow(gl_window);

    if (!gl_window)
    {
        fprintf(stderr, "Error: GLFW Window couldn't be created\n");
        return false;
    }

    glfwSetWindowUserPointer(gl_window, window);
    glfwSetKeyCallback(gl_window, OnKeyCallback);
    glfwSetScrollCallback(gl_window, OnScrollCallback);
    glfwSetWindowSizeCallback(gl_window, OnResizeCallback);
    glfwSetWindowCloseCallback(gl_window, OnCloseCallback);
    glfwMakeContextCurrent(gl_window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    return true;

}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLContext::PreRender()
{
    glViewport(0, 0, m_Window->m_Width, m_Window->m_Height);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLContext::Render()
{
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow*) m_Window->GetNativeWindow());
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLContext::End()
{
    glfwDestroyWindow((GLFWwindow*)m_Window->GetNativeWindow());
    glfwTerminate();
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
static void OnKeyCallback(GLFWwindow* window, int32_t key, int32_t scanCode, int32_t action, int32_t mods)
{
    GFX::Window::BaseWindow* gl_window = static_cast<GFX::Window::BaseWindow*>(glfwGetWindowUserPointer(window));
    gl_window->OnKey(key, scanCode, action, mods);
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
static void OnScrollCallback(GLFWwindow* window, float64_t xOffset, float64_t yOffSet)
{
    GFX::Window::BaseWindow* gl_window = static_cast<GFX::Window::BaseWindow*>(glfwGetWindowUserPointer(window));
    gl_window->OnScroll(yOffSet);
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
static void OnResizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
    GFX::Window::BaseWindow* gl_window = static_cast<GFX::Window::BaseWindow*>(glfwGetWindowUserPointer(window));
    gl_window->OnResize(width, height);
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
static void OnCloseCallback(GLFWwindow* window)
{
    GFX::Window::BaseWindow* gl_window = static_cast<GFX::Window::BaseWindow*>(glfwGetWindowUserPointer(window));
    gl_window->OnClose();
}

/** @} */