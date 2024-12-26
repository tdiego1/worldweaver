/**************************************************************************************************/
/**
* \addtogroup APPLICATION
* @{
* \details
* This file provides the public interface for the Application Module.
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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/
#include <string>

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
    namespace Main
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Application
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the <ExampleClass>.
            */
            Application(const std::string &appName);

            /**************************************************************************************************/
            /**
            * \brief The defaiult destructor for the <ExampleClass>.
            */
            ~Application(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Main loop of the application.
            */
            void MainLoop(void);

        private:
            /*********************************/
            // Private member variables
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
    namespace Main
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline Application::~Application(){}
    }
}

#endif
/** @} */