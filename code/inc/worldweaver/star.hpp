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
                M
            };

            /**************************************************************************************************/
            /**
            * \brief The spectral class of stars.
            */
            struct SpectralClass
            {
                SpectralMajor spectralMajor;
                double spectralMinor;
                bool isMainSequence;
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
            
        private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/
            SpectralClass m_SpectralClass;
            double m_Mass;
            double m_CurrentAge;
            double m_MaxAge;
            double m_Radius;
            double m_Luminosity;
            double m_Density;
            double m_Temperature;
            double m_Color;
            double m_MinHabitableZone;
            double m_MaxHabitableZone;
            bool m_IsEarthLike;

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