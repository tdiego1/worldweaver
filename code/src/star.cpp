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
#include "worldweaver/star.hpp"
#include <cstring>

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
WorldWeaver::Model::Star::Star() :
    m_Mass(0.0),
    m_CurrentAge(0.0),
    m_MaxAge(0.0),
    m_Radius(0.0),
    m_Luminosity(1.0),
    m_Density(1.0),
    m_Temperature(1.0),
    m_Color(1.0),
    m_MinHabitableZone(0.0),
    m_MaxHabitableZone(0.0),
    m_IsEarthLike(false)
{
    m_SpectralClass.spectralMajor = SpectralMajor::UNSET;
    m_SpectralClass.spectralMinor = 0.0;
    m_SpectralClass.isMainSequence = false;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetSpectralClass(SpectralClass spectralClass)
{
    m_SpectralClass = spectralClass;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetMass(double mass)
{
    m_Mass = mass;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetCurrentAge(double currentAge)
{
    m_CurrentAge = currentAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetMaxAge(double maxAge)
{
    m_MaxAge = maxAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetRadius(double radius)
{
    m_Radius = radius;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetLuminosity(double luminosity)
{
    m_Luminosity = luminosity;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetDensity(double density)
{
    m_Density = density;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetTemperature(double temperature)
{
    m_Temperature = temperature;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetColor(double color)
{
    m_Color = color;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetMinHabitableZone(double minHabitableZone)
{
    m_MinHabitableZone = minHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetMaxHabitableZone(double maxHabitableZone)
{
    m_MaxHabitableZone = maxHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetIsEarthLike(bool isEarthLike)
{
    m_IsEarthLike = isEarthLike;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
WorldWeaver::Model::Star::SpectralClass WorldWeaver::Model::Star::GetSpectralClass() const
{
    return m_SpectralClass;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetMass() const
{
    return m_Mass;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetCurrentAge() const
{
    return m_CurrentAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetMaxAge() const
{
    return m_MaxAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetRadius() const
{
    return m_Radius;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetLuminosity() const
{
    return m_Luminosity;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetDensity() const
{
    return m_Density;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetTemperature() const
{
    return m_Temperature;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetColor() const
{
    return m_Color;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetMinHabitableZone() const
{
    return m_MinHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
double WorldWeaver::Model::Star::GetMaxHabitableZone() const
{
    return m_MaxHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
bool WorldWeaver::Model::Star::GetIsEarthLike() const
{
    return m_IsEarthLike;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */