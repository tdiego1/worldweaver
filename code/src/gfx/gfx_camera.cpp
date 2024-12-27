/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Input Module.
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

#include "gfx/element/gfx_camera.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

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
* \par Details: 
*/
GFX::Element::Camera::Camera(const glm::vec3& position, float32_t fov, float32_t aspect, float32_t near, float32_t far) : 
    m_Position(position),
    m_Distance(5.0f),
    m_FOV(fov), 
    m_Aspect(aspect), 
    m_Near(near), 
    m_Far(far),
    m_Pitch(0.0f),
    m_Yaw(0.0f)
{
    m_Projection = glm::mat4{ 1.0f };
    m_Focus = { 0.0f, 0.0f, 0.0f };
    m_CurrentPos2D = { 0.0f, 0.0f };

    SetAspect(m_Aspect);

    UpdateViewMatrix();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::Update(GFX::Util::Shader* shader)
{
    glm::mat4 model{ 1.0f };
    shader->SetMatrix4(model, "model");
    shader->SetMatrix4(m_ViewMatrix, "view");
    shader->SetMatrix4(GetProjection(), "projection");
    shader->SetVector3(m_Position, "camPos");
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::SetAspect(float32_t aspect)
{
    m_Projection = glm::perspective(m_FOV, aspect, m_Near, m_Far);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::SetDistance(float32_t offset)
{
    m_Distance += offset;
    UpdateViewMatrix();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
const glm::mat4& GFX::Element::Camera::GetProjection(void) const
{
    return m_Projection;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::mat4 GFX::Element::Camera::GetViewProjection(void) const
{
    return m_Projection * m_ViewMatrix;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::vec3 GFX::Element::Camera::GetUp(void) const
{
    const glm::vec3 c_up = { 0.0f, 1.0f, 0.0f };

    return glm::rotate(GetDirection(), c_up);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::vec3 GFX::Element::Camera::GetRight(void) const
{
    const glm::vec3 c_right = { 1.0f, 0.0f, 0.0f };

    return glm::rotate(GetDirection(), c_right);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::vec3 GFX::Element::Camera::GetForward(void) const
{
    const glm::vec3 c_forward = { 0.0f, 0.0f, -1.0f };

    return glm::rotate(GetDirection(), c_forward);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::quat GFX::Element::Camera::GetDirection(void) const
{
    return glm::quat(glm::vec3(-m_Pitch, -m_Yaw, 0.0f));
}

/**************************************************************************************************/
/**
* \par Details: 
*/
glm::mat4 GFX::Element::Camera::GetViewMatrix(void) const
{
    return m_ViewMatrix;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::OnMouseWheel(float64_t delta)
{
    SetDistance(delta * 0.5f);

    UpdateViewMatrix();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::Reset(void)
{
    m_Focus = { 0.0f, 0.0f, 0.0f };

    UpdateViewMatrix();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::OnMouseMove(float64_t x, float64_t y, Input::EInputButton button)
{
    const float32_t c_rotation_speed = 2.0f;
    glm::vec2 position_2D{ x, y };

    if (button == Input::EInputButton::RIGHT)
    {
        glm::vec2 delta = (position_2D - m_CurrentPos2D) * 0.004f;

        float32_t sign = GetUp().y < 0 ? -1.0f : 1.0f;
        m_Yaw += sign * delta.x * c_rotation_speed;
        m_Pitch += delta.y * c_rotation_speed;

        UpdateViewMatrix();
    }	
    else if (button == Input::EInputButton::MIDDLE)
    {
        // TODO: Adjust pan speed for distance
        glm::vec2 delta = (position_2D - m_CurrentPos2D) * 0.003f;

        m_Focus += -GetRight() * delta.x * m_Distance;
        m_Focus += GetUp() * delta.y * m_Distance;

        UpdateViewMatrix();
    }

    m_CurrentPos2D = position_2D;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Camera::UpdateViewMatrix(void)
{
    m_Position =  m_Focus - GetForward() * m_Distance;

    glm::quat orientation = GetDirection();
    m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
    m_ViewMatrix = glm::inverse(m_ViewMatrix);
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */