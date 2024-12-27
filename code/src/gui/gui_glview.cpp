/**************************************************************************************************/
/**
* \addtogroup <DoxModuleId>
* @{
* \details
* This file provides the public interface for the <Module_Name> Module.
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

#include "gui/gui_glview.hpp"

#include "imgui.h"

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
WorldWeaver::GUI::GLView::GLView() :
    m_Camera(nullptr),
    m_FrameBuffer(nullptr),
    m_Shader(nullptr),
    m_Light(nullptr),
    m_Mesh(nullptr),
    m_Size(800, 600)
{
    m_FrameBuffer = std::make_unique<GFX::Render::GLFrameBuffer>();
    m_FrameBuffer->CreateBuffers(800, 600);
    m_Shader = std::make_unique<GFX::Util::Shader>();
    m_Shader->Load("shaders/vs.shader", "shaders/fs_pbr.shader");
    m_Light = std::make_unique<GFX::Element::Light>();
    m_Camera = std::make_unique<GFX::Element::Camera>(glm::vec3(0.0f, 0.0f, 3.0f), 45.0f, 1.3f, 0.1f, 100.0f);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
GFX::Element::Light* WorldWeaver::GUI::GLView::GetLight()
{
    return m_Light.get();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::Resize(int32_t width, int32_t height)
{
    m_Size.x = width;
    m_Size.y = height;

    m_FrameBuffer->CreateBuffers((int32_t)m_Size.x, (int32_t)m_Size.y);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::Render()
{
    m_Shader->Use();

    m_Light->Update(m_Shader.get());

    m_FrameBuffer->Bind();

    if (m_Mesh)
    {
        m_Mesh->Update(m_Shader.get());
        m_Mesh->Render();
    }

    m_FrameBuffer->Unbind();

    ImGui::Begin("Scene");

    ImVec2 viewport_panel_size = ImGui::GetContentRegionAvail();
    m_Size = { viewport_panel_size.x, viewport_panel_size.y };

    m_Camera->SetAspect(m_Size.x / m_Size.y);
    m_Camera->Update(m_Shader.get());

    // add rendered texture to ImGUI scene window
    uint64_t texture_id = m_FrameBuffer->GetTexture();
    ImGui::Image(texture_id, ImVec2{ m_Size.x, m_Size.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

    ImGui::End();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::LoadMesh(const std::string& path)
{
    if(!m_Mesh)
    {
        m_Mesh = std::make_shared<GFX::Element::Mesh>();
    }

    m_Mesh->Load(path);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::SetMesh(std::shared_ptr<GFX::Element::Mesh> mesh)
{
    m_Mesh = mesh;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
std::shared_ptr<GFX::Element::Mesh> WorldWeaver::GUI::GLView::GetMesh()
{
    return m_Mesh;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::OnMouseMove(double x, double y, GFX::Element::Input::EInputButton button)
{
    m_Camera->OnMouseMove(x, y, button);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::OnMouseWheel(double delta)
{
    m_Camera->OnMouseWheel(delta);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::GLView::ResetView()
{
    m_Camera->Reset();
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */