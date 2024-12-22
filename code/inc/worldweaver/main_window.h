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
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/
#include <QMainWindow>
#include <QGroupBox>

#include "worldweaver/double_slider.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
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
** 4.  PUBLIC CLASSES FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \brief Main WorldWeaver QT application class
 */
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    /**************************************************************************************************/
    /**
     * \brief Main WorldWeaver QT application constructor.
     * 
     * \param[inout]    parent  The parent QT widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**************************************************************************************************/
    /**
     * \brief WorldWeaver QT destructor class.
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;    // QT ui variable.
    WorldWeaver::Control::DoubleSlider* m_StarMassSlider; // Custom slider widget for star mass double values.
    WorldWeaver::Control::DoubleSlider* m_StarAgeSlider;  // Custom slider widget for star age double values

        
};

#endif // WORLDWEAVER_H
