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

#include "gfx/gfx_glwindow.hpp"
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
GFX::Window::GLWindow::GLWindow() : m_Window(nullptr), m_IsRunning(false)
{
    m_UIContext = std::make_unique<GFX::Render::UIContext>();
    m_RenderContext = std::make_unique<GFX::Render::GLContext>();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
GFX::Window::GLWindow::~GLWindow()
{
    m_UIContext->End();
    m_RenderContext->End();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
bool GFX::Window::GLWindow::Initialize(int32_t width, int32_t height, const std::string& title)
{
    m_Width = width;
    m_Height = height;
    m_Title = title;

    m_RenderContext->Initialize(this);

    m_UIContext->Initialize(this);

    m_RenderView = std::make_unique<WorldWeaver::GUI::GLView>();

    m_StarPanel = std::make_unique<WorldWeaver::GUI::StarPanel>();

    m_StarPanel->SetMeshLoadCallback([this](std::string filepath) { m_RenderView->LoadMesh(filepath); });

    m_IsRunning = true;

    return m_IsRunning;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::Render()
{
    // Clear the view
    m_RenderContext->PreRender();

    // Initialize UI components
    m_UIContext->PreRender();

    // render scene to framebuffer and add it to scene view
    m_RenderView->Render();

    // Render the star panel
    m_StarPanel->Render(m_RenderView.get());

    // Render the UI
    m_UIContext->Render();

    // Render end, swap buffers
    m_RenderContext->Render();

    HandleInput();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::HandleInput()
{
    // TODO: move this and camera to scene UI component?

    if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
    {
        m_RenderView->OnMouseWheel(-0.4f);
    }

    if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
    {
        m_RenderView->OnMouseWheel(0.4f);
    }

    if (glfwGetKey(m_Window, GLFW_KEY_F) == GLFW_PRESS)
    {
        m_RenderView->ResetView();
    }

    float64_t x_pos;
    float64_t y_pos;
    glfwGetCursorPos(m_Window, &x_pos, &y_pos);

    m_RenderView->OnMouseMove(x_pos, y_pos, GFX::Element::Input::GetPressedButton(m_Window));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void* GFX::Window::GLWindow::GetNativeWindow()
{
    return m_Window;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::SetNativeWindow(void* window)
{
    m_Window = static_cast<GLFWwindow*>(window);
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::OnScroll(float64_t delta)
{
    m_RenderView->OnMouseWheel(delta);
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::OnKey(int32_t key, int32_t scanCode, int32_t action, int32_t mods)
{
    if (action == GLFW_PRESS)
    {
    }
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::OnResize(int32_t width, int32_t height)
{
    m_Width = width;
    m_Height = height;

    m_RenderView->Resize(width, height);
    Render();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void GFX::Window::GLWindow::OnClose()
{
    m_IsRunning = false;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
bool GFX::Window::GLWindow::IsRunning()
{
    return m_IsRunning;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */