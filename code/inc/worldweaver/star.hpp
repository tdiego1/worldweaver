/**************************************************************************************************/
/**
* \addtogroup Star
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

#ifndef STAR_HPP
#define STAR_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/
#include <cstdint>

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
    namespace Model
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Star
        {

        public:
            /*********************************/
            // Public type definitions
            /*********************************/
            /**************************************************************************************************/
            /**
            * \brief The major spectral class of stars.
            */
            enum class SpectralMajor
            {
                O,
                B,
                A,
                F,
                G,
                K,
                M,
                UNSET
            };

            /**************************************************************************************************/
            /**
             * \brief Describes whether the star is capable of Earth-like life.
             */
            enum class LifeCapable
            {
                YES,
                NO,
                TOO_YOUNG
            };

            /**************************************************************************************************/
            /**
            * \brief The spectral class of stars.
            */
            struct SpectralClass
            {
                SpectralMajor spectralMajor;
                float spectralMinor;
                bool isMainSequence;
            };

            /**************************************************************************************************/
            /**
             * \brief The color of a star in rgba.
             */
            struct Color
            {
                uint8_t r;
                uint8_t g;
                uint8_t b;
            };

            /*********************************/
            // Public member variables
            /*********************************/

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the <ExampleClass>.
            */
            Star();

            /**************************************************************************************************/
            /**
            * \brief The defaiult destructor for the <ExampleClass>.
            */
            ~Star();

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Calculates the star's characteristics from mass.
            */
            void CalculateCharacteristics();

            /**************************************************************************************************/
            /**
            * \brief Sets the spectral class of a star.
            * 
            * \param[in] spectralClass The spectral class of the star.
            */
            void SetSpectralClass(SpectralClass spectralClass);

            /**************************************************************************************************/
            /**
            * \brief Sets the mass of a star.
            * 
            * \param[in] mass The mass of the star.
            */
           void SetMass(float mass);

            /**************************************************************************************************/
            /**
            * \brief Sets the current age of a star.
            * 
            * \param[in] currentAge The current age of the star.
            */
            void SetCurrentAge(float currentAge);

            /**************************************************************************************************/
            /**
            * \brief Sets the maximum age of a star.
            * 
            * \param[in] maxAge The maximum age of the star.
            */
            void SetMaxAge(float maxAge);

            /**************************************************************************************************/
            /**
            * \brief Sets the radius of a star.
            * 
            * \param[in] radius The radius of the star.
            */
            void SetRadius(float radius);

            /**************************************************************************************************/
            /**
            * \brief Sets the luminosity of a star.
            * 
            * \param[in] luminosity The luminosity of the star.
            */
            void SetLuminosity(float luminosity);

            /**************************************************************************************************/
            /**
            * \brief Sets the density of a star.
            * 
            * \param[in] density The density of the star.
            */
            void SetDensity(float density);

            /**************************************************************************************************/
            /**
            * \brief Sets the temperature of a star.
            * 
            * \param[in] temperature The temperature of the star.
            */
            void SetTemperature(float temperature);

            /**************************************************************************************************/
            /**
            * \brief Sets the color of a star.
            * 
            * \param[in] color The color of the star in rgb.
            */
            void SetColor(Color color);

            /**************************************************************************************************/
            /**
            * \brief Sets the minimum habitable zone of a star in AU.
            * 
            * \param[in] minHabitableZone The minimum habitable zone of the star in AU.
            */
            void SetMinHabitableZone(float minHabitableZone);

            /**************************************************************************************************/
            /**
            * \brief Sets the maximum habitable zone of a star in AU.
            * 
            * \param[in] maxHabitableZone The maximum habitable zone of the star in AU.
            */
            void SetMaxHabitableZone(float maxHabitableZone);

            /**************************************************************************************************/
            /**
            * \brief Sets whether a star is capable of supporting Earth-like life.
            * 
            * \param[in] lifeCapable The capability of the star to support Earth-like life.
            */
            void SetIsLifeCapable(LifeCapable lifeCapable);

            /**************************************************************************************************/
            /**
            * \brief Gets the spectral class of a star.
            * 
            * \retval SpectralClass The spectral class of the star.
            */
            SpectralClass GetSpectralClass() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the mass of a star.
             *  
             * \retval float The mass of the star.
             */
            float GetMass() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the current age of a star.
             *  
             * \retval float The current age of the star.
             */
            float GetCurrentAge() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the maximum age of a star.
             *  
             * \retval float The maximum age of the star.
             */
            float GetMaxAge() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the radius of a star.
             *  
             * \retval float The radius of the star.
             */
            float GetRadius() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the luminosity of a star.
             *  
             * \retval float The luminosity of the star.
             */
            float GetLuminosity() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the density of a star.
             *  
             * \retval float The density of the star.
             */
            float GetDensity() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the temperature of a star.
             *  
             * \retval float The temperature of the star.
             */
            float GetTemperature() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the color of a star.
             *  
             * \retval WorldWeaver::Model::Star::Color The color of the star in rgb.
             */
            Color GetColor() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the minimum habitable zone of a star in AU.
             *  
             * \retval float The minimum habitable zone of the star in AU.
             */
            float GetMinHabitableZone() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the maximum habitable zone of a star in AU.
             *  
             * \retval float The maximum habitable zone of the star in AU.
             */
            float GetMaxHabitableZone() const;

            /**************************************************************************************************/
            /**
             * \brief Gets whether a star is capable of supporting Earth-like life.
             *  
             * \retval LifeCapable The capability of the star to support Earth-like life.
             */
            LifeCapable GetIsLifeCapable() const;

        private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/
            SpectralClass m_SpectralClass;
            float m_Mass;
            float m_CurrentAge;
            float m_MaxAge;
            float m_Radius;
            float m_Luminosity;
            float m_Density;
            float m_Temperature;
            Color m_Color;
            float m_MinHabitableZone;
            float m_MaxHabitableZone;
            LifeCapable m_IsLifeCapable;

            /*********************************/
            // Private functions
            /*********************************/
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
namespace WorldWeaver
{
    namespace Model
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline Star::~Star(){}
    }
}

#endif
/** @} */