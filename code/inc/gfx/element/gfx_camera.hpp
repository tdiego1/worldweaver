/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Camera Module.
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

#include "gfx/element/gfx_element.hpp"
#include "gfx/shader/gfx_shader.hpp"
#include "gfx/element/gfx_input.hpp"

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
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Camera : public Element
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
            * \brief The default constructor for the Camera.
            */
            Camera(const glm::vec3& position, float32_t fov, float32_t aspect, float32_t nearValue, float32_t farValue);

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
            void Update(GFX::Util::Shader* shader) override;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetAspect(float32_t aspect);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void SetDistance(float32_t offset);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            const glm::mat4& GetProjection(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::mat4 GetViewProjection(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::vec3 GetUp(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::vec3 GetRight(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::vec3 GetForward(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::quat GetDirection(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            glm::mat4 GetViewMatrix(void) const;

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void OnMouseWheel(float64_t delta);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void Reset(void);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void OnMouseMove(float64_t x, float64_t y, Input::EInputButton button);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void UpdateViewMatrix(void);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            glm::mat4 m_ViewMatrix;
            glm::mat4 m_Projection;
            glm::vec3 m_Position;

            glm::vec3 m_Focus;

            float32_t m_Distance;
            float32_t m_Aspect;
            float32_t m_FOV;
            float32_t m_Near;
            float32_t m_Far;

            float32_t m_Pitch;
            float32_t m_Yaw;

            glm::vec2 m_CurrentPos2D;

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