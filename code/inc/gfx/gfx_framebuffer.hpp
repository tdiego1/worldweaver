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

#pragma once

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/gfx_common.hpp"

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
            * \brief Creates the buffers for the FrameBuffer.
            * 
            * \param[in] width  The width of the FrameBuffer.
            * \param[in] height The height of the FrameBuffer.
            */
            virtual void CreateBuffers(int32_t width, int32_t height) = 0;

            /**************************************************************************************************/
            /**
            * \brief Deletes the buffers for the FrameBuffer.
            */
            virtual void DeleteBuffers(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Binds the FrameBuffer.
            */
            virtual void Bind(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Unbinds the FrameBuffer.
            */
            virtual void Unbind(void) = 0;

            /**************************************************************************************************/
            /**
            * \brief Gets the texture of the FrameBuffer.
            * 
            * \retval uint32_t The texture of the FrameBuffer.
            */
            virtual uint32_t GetTexture(void) = 0;

        protected:
            /*********************************/
            // Protected member variables
            /*********************************/

            uint32_t m_FBO;         // The FrameBuffer Object.
            uint32_t m_TextureID;   // The texture of the FrameBuffer.
            uint32_t m_DepthID;     // The depth of the FrameBuffer.
            int32_t m_Width;        // The width of the FrameBuffer.
            int32_t m_Height;       // The height of the FrameBuffer;
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
namespace GFX
{
    namespace Render
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline FrameBuffer::FrameBuffer() : m_FBO(0), m_TextureID(0), m_DepthID(0), m_Width(0), m_Height(0)
        {}
    }
}

/** @} */