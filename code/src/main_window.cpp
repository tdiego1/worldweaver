/**************************************************************************************************/
/**
 * \addtogroup main
 * @{
 * \details
 * This file implements the main functionality.
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
#include "worldweaver/main_window.h"
#include "./ui_main_window.h"

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
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    const double c_star_mass_min = 0.0;         // Min star mass in solar masses (Msol).
    const double c_star_mass_max = 2.0;         // Max star mass in solar masses (Msol).
    const double c_star_mass_step = 0.01;       // Star mass spin box step interval.
    const double c_star_mass_default = 1.0;     // Star mass default value (Earth = 1Msol).
    const int c_star_mass_slider_min = 0;       // Min star mass slider (integer).
    const int c_star_mass_slider_max = 100000;  // Max star mass slider (integer).
    const int c_star_mass_slider_step = 1;      // Star mass slider step interval.
    const double c_star_age_min = 0.0;          // Min star age in billions of Earth years (Gyr)

    ui->setupUi(this);

    // Create custom slider widgets.
    m_StarMassSlider = new WorldWeaver::Control::DoubleSlider(ui->starMassSlider,
                                                              c_star_mass_min,
                                                              c_star_mass_max,
                                                              c_star_mass_slider_min,
                                                              c_star_mass_slider_max);

    m_StarAgeSlider = new WorldWeaver::Control::DoubleSlider(ui->starAgeSlider, 0.0, 80.0, 0, 100000);

    // Set star mass spin box default values.
    ui->starMassSpinBox->setMinimum(c_star_mass_min);
    ui->starMassSpinBox->setMaximum(c_star_mass_max);
    ui->starMassSpinBox->setSingleStep(c_star_mass_step);
    ui->starMassSpinBox->setValue(c_star_mass_default);

    // Set star mass slider default values.
    ui->starMassSlider->setSingleStep(c_star_mass_slider_step);
    ui->starMassSlider->setTickPosition(QSlider::NoTicks);
    ui->starMassSlider->setValue(c_star_mass_slider_max / 2);

    ui->starAgeSpinBox->setMinimum(0.0);

    connect(m_StarMassSlider, SIGNAL(doubleValueChanged(double)), ui->starMassSpinBox, SLOT(setValue(double)));
    connect(ui->starMassSpinBox, &QDoubleSpinBox::valueChanged, m_StarMassSlider, &WorldWeaver::Control::DoubleSlider::setDoubleValue);

    connect(ui->starAgeSlider, &QSlider::valueChanged, ui->starAgeSpinBox, &QDoubleSpinBox::setValue);
    connect(ui->starAgeSpinBox, &QDoubleSpinBox::valueChanged, ui->starAgeSlider, &QSlider::setValue);

}

/**************************************************************************************************/
/**
 * \par Details: Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*=================================================================================================
** 5.  PRIVATE FUNCTIONS
**===============================================================================================*/
