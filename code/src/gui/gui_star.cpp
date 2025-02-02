/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the Star Module.
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

#include "gui/gui_star.hpp"

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
WorldWeaver::GUI::StarPanel::StarPanel() : m_CurrentStar()
{
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void WorldWeaver::GUI::StarPanel::Render(WorldWeaver::GUI::GLView* sceneView)
{
    // 1. Create a window called "Star Interface" and begin ImGui frame.
    ImGui::Begin("Star", NULL);

    float32_t star_mass = m_CurrentStar.GetMass();
    std::string spectral_class = "";
    std::string is_life_capable = "";

    if (ImGui::SliderFloat("Mass", &star_mass, 0.075f, 2.0f, "%.3f Msol", ImGuiSliderFlags_AlwaysClamp))
    {
        m_CurrentStar.SetMass(star_mass);
    }

    float32_t star_age = m_CurrentStar.GetCurrentAge();

    if (ImGui::SliderFloat("Current Age", &star_age, 0.0f, m_CurrentStar.GetMaxAge(), "%.3f Gyr", ImGuiSliderFlags_AlwaysClamp))
    {
        // Set the current age of the star.
        m_CurrentStar.SetCurrentAge(star_age);
    }

    ImGui::Separator();

    switch (m_CurrentStar.GetSpectralClass().spectralMajor)
    {
        case WorldWeaver::Model::Star::SpectralMajor::O:
            spectral_class = "O";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::B:
            spectral_class = "B";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::A:
            spectral_class = "A";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::F:
            spectral_class = "F";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::G:
            spectral_class = "G";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::K:
            spectral_class = "K";
            break;
        case WorldWeaver::Model::Star::SpectralMajor::M:
            spectral_class = "M";
            break;
    }

    spectral_class.append(std::format("{:.1f}", m_CurrentStar.GetSpectralClass().spectralMinor));
    spectral_class.append("V");

    ImGui::Text("Spectral Class: %s", spectral_class.c_str());
    ImGui::Text("Mass: %.3f Msol", m_CurrentStar.GetMass());
    ImGui::Text("Current Age: %.3f Gyr", m_CurrentStar.GetCurrentAge());
    ImGui::Text("Max Age: %.3f Gyr", m_CurrentStar.GetMaxAge());
    ImGui::Text("Radius: %.3f Rsol", m_CurrentStar.GetRadius());
    ImGui::Text("Luminosity: %.3f Lsol", m_CurrentStar.GetLuminosity());
    ImGui::Text("Density: %.3f Dsol", m_CurrentStar.GetDensity());
    ImGui::Text("Temperature: %.f K", m_CurrentStar.GetTemperature());
    ImGui::Text("Color: R: %d, G: %d, B: %d", m_CurrentStar.GetColor().r, m_CurrentStar.GetColor().g, m_CurrentStar.GetColor().b);
    ImGui::Text("Habitable Zone: %.3f - %.3f AU", m_CurrentStar.GetMinHabitableZone(), m_CurrentStar.GetMaxHabitableZone());

    switch (m_CurrentStar.GetIsLifeCapable())
    {
        case WorldWeaver::Model::Star::LifeCapable::YES:
            is_life_capable = "Yes";
            break;
        case WorldWeaver::Model::Star::LifeCapable::NO:
            is_life_capable = "No";
            break;
        case WorldWeaver::Model::Star::LifeCapable::TOO_YOUNG:
            is_life_capable = "Too Young";
            break;
    }
    ImGui::Text("Has Earth-like life? %s", is_life_capable.c_str());

    // 3. End the ImGui frame.
    ImGui::End();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void WorldWeaver::GUI::StarPanel::SetMeshLoadCallback(const std::function<void(const std::string&)>& callback)
{
    m_MeshLoadCallback = callback;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */