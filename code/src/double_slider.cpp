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

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "worldweaver/double_slider.hpp"

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
 * \par Details: Default constructor.
 */
WorldWeaver::Control::DoubleSlider::DoubleSlider(QSlider* slider, double minDouble, double maxDouble, int minSlider, int maxSlider) :
    m_Slider(slider),
    m_Min(minDouble),
    m_Max(maxDouble)
{
    m_Slider->setRange(minSlider, maxSlider);

    connect(slider, &QSlider::valueChanged, this, &DoubleSlider::onValueChanged);
}

/**************************************************************************************************/
/**
 * \par Details: None.
 */
void WorldWeaver::Control::DoubleSlider::setDoubleRange(double min, double max)
{
    this->m_Min = min;
    this->m_Max = max;
}

/**************************************************************************************************/
/**
 * \par Details: None.
 */
void WorldWeaver::Control::DoubleSlider::setDoubleValue(double value)
{
    m_Slider->setValue(this->toIntValue(value));
}

/**************************************************************************************************/
/**
 * \par Details: None.
 */
double WorldWeaver::Control::DoubleSlider::getDoubleValue() const
{
    return this->toDoubleValue(m_Slider->value());
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \par Details: None.
 */
int WorldWeaver::Control::DoubleSlider::toIntValue(double value) const
{
    int new_value = static_cast<int>(((value - this->m_Min) / (this->m_Max - this->m_Min)) * 100000.0);
    return new_value;
}

/**************************************************************************************************/
/**
 * \par Details: None.
 */
double WorldWeaver::Control::DoubleSlider::toDoubleValue(int value) const
{
    double new_value = static_cast<double>(value) / 100000.0 * (this->m_Max - this->m_Min) + this->m_Min;
    return new_value; 
}

/**************************************************************************************************/
/**
 * \par Details: None.
 */
void WorldWeaver::Control::DoubleSlider::onValueChanged(int value)
{
    emit doubleValueChanged(this->getDoubleValue());
}

/** @} */
