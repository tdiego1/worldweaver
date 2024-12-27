/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the PropertyPanel Module.
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

#include "gui/gui_property.hpp"
#include "gui/gui_helper.hpp"

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
WorldWeaver::GUI::PropertyPanel::PropertyPanel() :
    m_CurrentFile("< ... >")
{
    m_FileBrowser.SetTitle("Open Mesh");
    m_FileBrowser.SetTypeFilters({ ".fbx", ".obj" });
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::PropertyPanel::Render(WorldWeaver::GUI::GLView* sceneView)
{
    auto mesh = sceneView->GetMesh();

    ImGui::Begin("Properties");
    if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
    {
        if (ImGui::Button("Open..."))
        {
            m_FileBrowser.Open();
        }
        ImGui::SameLine(0, 5.0f);
        ImGui::Text(m_CurrentFile.c_str());
    }

    if (ImGui::CollapsingHeader("Material") && mesh)
    {
        ImGui::ColorPicker3("Color", (float*)&mesh->m_Color, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
        ImGui::SliderFloat("Roughness", &mesh->m_Roughness, 0.0f, 1.0f);
        ImGui::SliderFloat("Metallic", &mesh->m_Metallic, 0.0f, 1.0f);
    }

    if (ImGui::CollapsingHeader("Light"))
    {
        ImGui::Separator();
        ImGui::Text("Position");
        ImGui::Separator();
        WorldWeaver::GUI::Helper::DrawVector3Widget("Position", sceneView->GetLight()->m_Position);
    }

    ImGui::End();

    m_FileBrowser.Display();
    if (m_FileBrowser.HasSelected())
    {
        auto file_path = m_FileBrowser.GetSelected().string();
        m_CurrentFile = file_path.substr(file_path.find_last_of("/\\") + 1);

        m_MeshLoadCallback(file_path);

        m_FileBrowser.ClearSelected();
    }
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void WorldWeaver::GUI::PropertyPanel::SetMeshLoadCallback(const std::function<void(const std::string&)>& callback)
{
    m_MeshLoadCallback = callback;
}


/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */