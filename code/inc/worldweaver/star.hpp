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
                M,
                UNSET
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
            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetSpectralClass(SpectralClass spectralClass);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
           void SetMass(double mass);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetCurrentAge(double currentAge);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetMaxAge(double maxAge);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetRadius(double radius);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetLuminosity(double luminosity);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetDensity(double density);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetTemperature(double temperature);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetColor(double color);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetMinHabitableZone(double minHabitableZone);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetMaxHabitableZone(double maxHabitableZone);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetIsEarthLike(bool isEarthLike);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \retval 
            */
            SpectralClass GetSpectralClass() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetMass() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetCurrentAge() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetMaxAge() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetRadius() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetLuminosity() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetDensity() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetTemperature() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetColor() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetMinHabitableZone() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            double GetMaxHabitableZone() const;

            /**************************************************************************************************/
            /**
             * \brief
             *  
             * \retval 
             */
            bool GetIsEarthLike() const;

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