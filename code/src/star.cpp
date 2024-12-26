/**************************************************************************************************/
/**
* \addtogroup STAR
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
#include "worldweaver/star.hpp"
#include <cstring>
#include <cmath>

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
* \brief Determines the Spectral Class of a star.
* 
* \param[in] mass The mass of the star.
* 
* \retval SpectralClass The spectral class of the star.
*/
static WorldWeaver::Model::Star::SpectralClass DetermineSpectralClass(float temperature);

/**************************************************************************************************/
/**
 * \brief Calculates the luminosity of a star.
 *  
 * \param[in] mass The mass of the star.
 * 
 * \retval float The luminosity of the star.
 */
static float CalculateLuminosity(float mass);

/**************************************************************************************************/
/**
 * \brief Calculates the radius of a star.
 *  
 * \param[in] mass The mass of the star.
 * 
 * \retval float The radius of the star.
 */
static float CalculateRadius(float mass);

/**************************************************************************************************/
/**
* \brief Calculate the color of a star.
* 
* \param[in] temperature The temperature of the star.
* 
* \retval WorldWeaver::Model::Star::Color The color of the star in rgb.
*/
static WorldWeaver::Model::Star::Color CalculateColor(float temperature);

/**************************************************************************************************/
/**
* \brief Determines if star is life capable.
* 
* \param[in] mass           The mass of the star.
* \param[in] currentAge     The current age of the star.
* 
* \retval LifeCapable::Yes The star is capable of supporting Earth-like life.
* \retval LifeCapable::No  The star is not capable of supporting Earth-like life.
* \retval LifeCapable::TooYoung The star is too young to support Earth-like life.
*/
static WorldWeaver::Model::Star::LifeCapable DetermineIfLifeCapable(float mass, float currentAge);

/*=================================================================================================
** 4.  PUBLIC FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
WorldWeaver::Model::Star::Star() :
    m_Mass(1.0),
    m_CurrentAge(6.0),
    m_MaxAge(0.0),
    m_Radius(0.0),
    m_Luminosity(0.0),
    m_Density(0.0),
    m_Temperature(0.0),
    m_Color{ 0 },
    m_MinHabitableZone(0.0),
    m_MaxHabitableZone(0.0),
    m_IsLifeCapable(LifeCapable::YES)
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
void WorldWeaver::Model::Star::SetMass(float mass)
{
    m_Mass = mass;

    // Calculate the star's characteristics.
    CalculateCharacteristics();
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::SetCurrentAge(float currentAge)
{
    m_CurrentAge = currentAge;

    // Calculate the star's characteristics.
    CalculateCharacteristics();
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
float WorldWeaver::Model::Star::GetMass() const
{
    return m_Mass;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetCurrentAge() const
{
    return m_CurrentAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetMaxAge() const
{
    return m_MaxAge;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetRadius() const
{
    return m_Radius;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetLuminosity() const
{
    return m_Luminosity;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetDensity() const
{
    return m_Density;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetTemperature() const
{
    return m_Temperature;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
WorldWeaver::Model::Star::Color WorldWeaver::Model::Star::GetColor() const
{
    return m_Color;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetMinHabitableZone() const
{
    return m_MinHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float WorldWeaver::Model::Star::GetMaxHabitableZone() const
{
    return m_MaxHabitableZone;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
WorldWeaver::Model::Star::LifeCapable WorldWeaver::Model::Star::GetIsLifeCapable() const
{
    return m_IsLifeCapable;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::Model::Star::CalculateCharacteristics()
{
    // Calculate the luminoisty of the star.
    m_Luminosity = CalculateLuminosity(m_Mass);

    // Calculate the max age of the star.
    m_MaxAge = (m_Mass / m_Luminosity) * 10.0f;

    if(m_CurrentAge > m_MaxAge)
    {
        m_CurrentAge = m_MaxAge;
    }

    // Calculate the radius of the star.
    m_Radius = CalculateRadius(m_Mass);

    // Calculate the density of the star.
    m_Density = m_Mass / (float)pow(m_Radius, 3);

    // Calculate the temperature of the star in Kelvin.
    m_Temperature = 5776.0f * ((float)pow((m_Luminosity / (float)pow(m_Radius, 2)), 0.25f));

    // Determine the spectral class of the star.
    m_SpectralClass = DetermineSpectralClass(m_Temperature);

    // Calculate the color of the star.
    m_Color = CalculateColor(m_Temperature);

    // Calculate the habitable zone of the star.
    m_MinHabitableZone = (float)sqrt(m_Luminosity / 1.1);
    m_MaxHabitableZone = (float)sqrt(m_Luminosity / 0.53);

    // Determine if the star will have Earth-like life.
    m_IsLifeCapable = DetermineIfLifeCapable(m_Mass, m_CurrentAge);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
WorldWeaver::Model::Star::SpectralClass DetermineSpectralClass(float temperature)
{
    WorldWeaver::Model::Star::SpectralClass spectral_class;

    if(temperature < 3700)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::M;
        spectral_class.spectralMinor = (1.0f - (temperature - 2000.0f) / 1700.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else if(temperature < 5200)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::K;
        spectral_class.spectralMinor = (1.0f - (temperature - 3700.0f) / 1500.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else if(temperature < 6000)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::G;
        spectral_class.spectralMinor = (1.0f - (temperature - 5200.0f) / 800.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else if(temperature < 7500)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::F;
        spectral_class.spectralMinor = (1.0f - (temperature - 6000.0f) / 1500.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else if(temperature < 10000)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::A;
        spectral_class.spectralMinor = (1.0f - (temperature - 7500.0f) / 2500.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else if(temperature < 33000)
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::B;
        spectral_class.spectralMinor = (1.0f - (temperature - 10000.0f) / 23000.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }
    else
    {
        spectral_class.spectralMajor = WorldWeaver::Model::Star::SpectralMajor::O;
        spectral_class.spectralMinor = (1.0f - (temperature - 33000.0f) / 62000.0f) * 10.0f;
        spectral_class.isMainSequence = true;
    }

    return spectral_class;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
float CalculateLuminosity(float mass)
{
    if(mass < 0.43f)
    {
        return (0.23 * (float)pow(mass, 0.23));
    }
    else if(mass < 2.0f)
    {
        return((float)pow(mass, 4));
    }
    else
    {
        return(1.4 * (float)pow(mass, 3.5));
    }
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
float CalculateRadius(float mass)
{
    if(mass < 1.0f)
    {
        return((float)pow(mass, 0.8));
    }
    else
    {
        return((float)pow(mass, 0.57));
    }
}

/**************************************************************************************************/
/**
* \par Details: 
*/
WorldWeaver::Model::Star::Color CalculateColor(float temperature)
{
    WorldWeaver::Model::Star::Color star_color;

    if(temperature <= 3700)
    {
        //Yellow
        star_color.r = 255;
        star_color.g = 204;
        star_color.b = 111;
    }
    else if(temperature < 5200)
    {
        // Yellow-orange
        star_color.r = 255;
        star_color.g = 210;
        star_color.b = 161;
    }
    else if(temperature < 6000)
    {
        // Orange-white
        star_color.r = 255;
        star_color.g = 244;
        star_color.b = 234;
    }
    else if(temperature < 7500)
    {
        // White
        star_color.r = 248;
        star_color.g = 247;
        star_color.b = 255;
    }
    else if(temperature < 10000)
    {
        // Blue-white
        star_color.r = 202;
        star_color.g = 215;
        star_color.b = 255;
    }
    else if(temperature < 33000)
    {
        // Light blue
        star_color.r = 170;
        star_color.g = 191;
        star_color.b = 255;
    }
    else
    {
        // Blue
        star_color.r = 155;
        star_color.g = 176;
        star_color.b = 255;
    }

    return star_color;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
WorldWeaver::Model::Star::LifeCapable DetermineIfLifeCapable(float mass, float currentAge)
{
    if(mass >= 0.5 && mass <= 1.4)
    {
        if(currentAge >= 3.5)
        {
            return(WorldWeaver::Model::Star::LifeCapable::YES);
        }
        else
        {
            return(WorldWeaver::Model::Star::LifeCapable::TOO_YOUNG);
        }
    }
    else
    {
        return(WorldWeaver::Model::Star::LifeCapable::NO);
    }
}


/** @} */