/**************************************************************************************************/
/**
* \addtogroup DoubleSlider
* @{
* \details
* This file provides the public interface for the DoubleSlider Module.
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

#ifndef DOUBLE_SLIDER_HPP
#define DOUBLE_SLIDER_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <stdfloat>

#include <QWidget>
#include <QSlider>

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace Control
{
    /**************************************************************************************************/
    /**
    * \par Details: 
    */
    class DoubleSlider :
        public QWidget
    {
    Q_OBJECT
    public:
        /*********************************/
        // Public type definitions
        /*********************************/

        /*********************************/
        // Public member variables
        /*********************************/

        /*********************************/
        // Constructors/Destructor
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief Main WorldWeaver QT application constructor.
         * 
         * \param[inout]    slider      The parent QT widget.
         * \param[in]       minDouble   Minimum double range.
         * \param[in]       maxDouble   Max double range.
         * \param[in]       minSlider   Min slider integer range value.
         * \param[in]       maxSlider   Max slider integer range value.
         */
        DoubleSlider(QSlider* slider, double minDouble, double maxDouble, int minSlider, int maxSlider);

        /**************************************************************************************************/
        /**
         * \brief The destructor for the DoubleSlider.
         */
        ~DoubleSlider(void);

        /*********************************/
        // Public functions
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief Sets the range of double values you wish the slider to be.
         * 
         * \param[in]   min     Minimum value the slider should be set to.
         * \param[in]   max     Maximum value the slider should be set to.
         */
        void setDoubleRange(double min, double max);

        /**************************************************************************************************/
        /**
         * \brief Gets the value of the slider by converting the value from a range of (0,99) to the
         *         double range set .
         * 
         * \retval  double  Returns the curent value of the slider within the range set.
         */
        double getDoubleValue() const;

    signals:
        /**************************************************************************************************/
        /**
         * \brief Signal to use when double value has changed.
         */
        void doubleValueChanged(double value);

    public slots:
        /**************************************************************************************************/
        /**
         * \brief Sets the value of the slider by converting the value into a range of (0,99).
         * 
         * \param[in]   value   Value to set the slider.
         */
        void setDoubleValue(double value);

    private slots:
        /**************************************************************************************************/
        /**
         * \brief Function called when the slider changed.
         */
        void onValueChanged(int value);

    private:
        /*********************************/
        // Private type definitions
        /*********************************/

        /*********************************/
        // Private member variables
        /*********************************/

        QSlider* m_Slider;  // QSlider object to extend.
        double m_Min;       // Minimum slider value set by setRange().
        double m_Max;       // Maximum slider value set by setRange().

        /*********************************/
        // Private functions
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief Converts a double value to an integer within the set range.
         * 
         * \retval  int  Returns the integer value of the slider within the range (0,99)
         */
        int toIntValue(double value) const;

        /**************************************************************************************************/
        /**
         * \brief Converts an int value to a double within the set range.
         * 
         * \retval  double  Double value of the slider.
         */
        double toDoubleValue(int value) const;

    };
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
namespace Control
{
    /**************************************************************************************************/
    /**
    * \par Details: 
    */
    inline DoubleSlider::~DoubleSlider(void){}
}

#endif
/** @} */