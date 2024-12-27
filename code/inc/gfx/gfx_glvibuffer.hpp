/**************************************************************************************************/
/**
* \addtogroup GFX_RENDER
* @{
* \details
* This file provides the public interface for the GLVertexBuffer Module.
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

#include "gfx/gfx_vibuffer.hpp"

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
        class GLVertexBuffer : public VertexIndexBuffer
        {

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
            * \brief The default constructor for the GLVertexBuffer.
            */
            GLVertexBuffer(void);

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
            void CreateBuffers(const std::vector<GFX::Element::Vertex>& vertices, const std::vector<uint32_t>& indices) override;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void DeleteBuffers(void) override;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void Bind(void) override;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void UnBind(void) override;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void Draw(int32_t indexCount) override;

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

/** @} */