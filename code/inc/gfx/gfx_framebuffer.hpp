/**************************************************************************************************/
/**
* \addtogroup BASE_RENDER
* @{
* \details
* This file provides the public interface for the FrameBuffer Module.
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

#ifndef GFX_RENDER_FRAMEBUFFER_HPP
#define GFX_RENDER_FRAMEBUFFER_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <stdint.h>

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace GFX
{
    namespace Render
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class FrameBuffer
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the FrameBuffer.
            */
            FrameBuffer(void);

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
            virtual void CreateBuffers(int32_t width, int32_t height) = 0;

        protected:
            /*********************************/
            // Protected type definitions
            /*********************************/

            /*********************************/
            // Protected member variables
            /*********************************/

            /*********************************/
            // Protected functions
            /*********************************/

        private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/

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
namespace ProgramName
{
    namespace ComponentName
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline FrameBuffer::~FrameBuffer(){}
    }
}

#endif
/** @} */