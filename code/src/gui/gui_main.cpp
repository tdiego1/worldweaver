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

#include <cmath>
#include <string>

#include "imgui.h"

#include "gui/gui_main.hpp"
#include "worldweaver/star.hpp"


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
static WorldWeaver::Model::Star g_CurrentStar;

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
void WorldWeaver::GUI::StarInterface()
{
    // 1. Create a window called "Star Interface" and begin ImGui frame.
    ImGui::Begin("Star", NULL);

    float star_mass = g_CurrentStar.GetMass();
    float star_age = g_CurrentStar.GetCurrentAge();
    std::string is_life_capable = "";

    if(ImGui::SliderFloat("Mass", &star_mass, 0.075f, 2.0f, "%.3f Msol", ImGuiSliderFlags_AlwaysClamp))
    {
        g_CurrentStar.SetMass(star_mass);
    }

    g_CurrentStar.CalculateCharacteristics();

    if(ImGui::SliderFloat("Current Age", &star_age, 0.0f, g_CurrentStar.GetMaxAge(), "%.3f Gyr", ImGuiSliderFlags_AlwaysClamp))
    {
        // Set the current age of the star.
        g_CurrentStar.SetCurrentAge(star_age);
    }

    ImGui::Separator();

    ImGui::Text("Spectral Class: ");

    ImGui::Text("Mass: %.3f Msol", g_CurrentStar.GetMass());

    ImGui::Text("Current Age: %.3f Gyr", g_CurrentStar.GetCurrentAge());

    ImGui::Text("Max Age: %.3f Gyr", g_CurrentStar.GetMaxAge());

    ImGui::Text("Radius: %.3f Rsol", g_CurrentStar.GetRadius());

    ImGui::Text("Luminosity: %.3f Lsol", g_CurrentStar.GetLuminosity());

    ImGui::Text("Density: %.3f Dsol", g_CurrentStar.GetDensity());

    ImGui::Text("Temperature: %.f K", g_CurrentStar.GetTemperature());

    ImGui::Text("Color: R: %d, G: %d, B: %d", g_CurrentStar.GetColor().r, g_CurrentStar.GetColor().g, g_CurrentStar.GetColor().b);

    ImGui::Text("Habitable Zone: %.3f - %.3f AU", g_CurrentStar.GetMinHabitableZone(), g_CurrentStar.GetMaxHabitableZone());

    switch(g_CurrentStar.GetIsLifeCapable())
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

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */