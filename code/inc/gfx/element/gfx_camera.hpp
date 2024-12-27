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
            * \brief Updates the camera.
            * 
            * \param[in] shader The shader to update.
            */
            void Update(GFX::Util::Shader* shader) override;

            /**************************************************************************************************/
            /**
            * \brief Sets the aspect ratio of the camera.
            * 
            * \param[in] aspect The aspect ratio.
            */
            void SetAspect(float32_t aspect);

            /**************************************************************************************************/
            /**
            * \brief Sets the distance of the camera.
            * 
            * \param[in] offset The distance offset.
            */
            void SetDistance(float32_t offset);

            /**************************************************************************************************/
            /**
            * \brief Gets the projection matrix of the camera.
            * 
            * \retval glm::mat4 The projection matrix.
            */
            const glm::mat4& GetProjection(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the view projection matrix of the camera.
            * 
            * \retval glm::mat4 The view projection matrix.
            */
            glm::mat4 GetViewProjection(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the Up vector of the camera.
            * 
            * \retval glm::vec3 The Up vector.
            */
            glm::vec3 GetUp(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the Right vector of the camera.
            * 
            * \retval glm::vec3 The Right vector.
            */
            glm::vec3 GetRight(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the Forward vector of the camera.
            * 
            * \retval glm::vec3 The Forward vector.
            */
            glm::vec3 GetForward(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the direction of the camera.
            * 
            * \retval glm::quat The direction.
            */
            glm::quat GetDirection(void) const;

            /**************************************************************************************************/
            /**
            * \brief Gets the view matrix of the camera.
            * 
            * \retval glm::mat4 The view matrix.
            */
            glm::mat4 GetViewMatrix(void) const;

            /**************************************************************************************************/
            /**
            * \brief Function called when the mouse wheel is scrolled.
            * 
            * \param[in] delta The scroll delta.
            */
            void OnMouseWheel(float64_t delta);

            /**************************************************************************************************/
            /**
            * \brief Resets the camera.
            */
            void Reset(void);

            /**************************************************************************************************/
            /**
            * \brief Function called when the mouse is moved.
            * 
            * \param[in] x      The x position of the mouse.
            * \param[in] y      The y position of the mouse.
            * \param[in] button The button pressed.
            */
            void OnMouseMove(float64_t x, float64_t y, Input::EInputButton button);

            /**************************************************************************************************/
            /**
            * \brief Updates the view matrix of the camera.
            */
            void UpdateViewMatrix(void);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            glm::mat4 m_ViewMatrix;     // The view matrix.
            glm::mat4 m_Projection;     // The projection matrix.
            glm::vec3 m_Position;       // The position of the camera.

            glm::vec3 m_Focus;          // The focus of the camera.

            float32_t m_Distance;       // The distance of the camera.
            float32_t m_Aspect;         // The aspect ratio of the camera.
            float32_t m_FOV;            // The field of view of the camera.
            float32_t m_Near;           // The near value of the camera.
            float32_t m_Far;            // The far value of the camera.

            float32_t m_Pitch;          // The pitch of the camera.
            float32_t m_Yaw;            // The yaw of the camera.

            glm::vec2 m_CurrentPos2D;   // The current 2D position of the camera.

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