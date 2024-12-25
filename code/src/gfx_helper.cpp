/**************************************************************************************************/
/**
* \addtogroup GFX_HELPER
* @{
* \details
* This file provides the public interface for the GFX_Helper Module.
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

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <libassert/assert.hpp>

#include "worldweaver/gfx_helper.hpp"

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
WorldWeaver::GFX::GFXHelper::GFXHelper() :
    m_VertexShader(0),
    m_FragmentShader(0),
    m_ShaderProgram(0)
{
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::GFX::GFXHelper::GFXHelperInit()
{
    glfwInit(); // Initialize the GLFW window.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Set the OpenGL major version to 3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // Set the OpenGL minor version to 3.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // Get the OpenGL profile to core.
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::GFX::GFXHelper::SetupShader(const char* shaderSource, ShaderType shaderType)
{
    ASSERT(shaderSource != nullptr, "ERROR::SHADER::SOURCE::nullptr", NULL);

    int32_t success;
    char info_log[512];

    switch(shaderType)
    {
        case ShaderType::VERTEX:
            m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(m_VertexShader, 1, &shaderSource, NULL);
            glCompileShader(m_VertexShader);

            glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &success);
            glGetProgramInfoLog(m_VertexShader, 512, NULL, info_log);
            ASSERT(success, "ERROR::SHADER::VERTEX::COMPILATION_FAILED", info_log);
            break;

        case ShaderType::FRAGMENT:
            m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(m_FragmentShader, 1, &shaderSource, NULL);
            glCompileShader(m_FragmentShader);

            glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &success);
            glGetProgramInfoLog(m_FragmentShader, 512, NULL, info_log);
            ASSERT(success, "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED", info_log);

            break;
        default:
            break;
    }
    
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
void WorldWeaver::GFX::GFXHelper::CompileShaderProgram()
{
    int32_t success;

    m_ShaderProgram = glCreateProgram();

    glAttachShader(m_ShaderProgram, m_VertexShader);
    glAttachShader(m_ShaderProgram, m_FragmentShader);

    glLinkProgram(m_ShaderProgram);

    glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);

    if(!success)
    {
        char info_log[512];
        glGetProgramInfoLog(m_ShaderProgram, 512, NULL, info_log);
        ASSERT(success, "ERROR::SHADER::PROGRAM::LINKING_FAILED", info_log);
    }

    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);

    m_VertexShader = 0;
    m_FragmentShader = 0;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
uint32_t WorldWeaver::GFX::GFXHelper::GetVertexShader() const
{
    return m_VertexShader;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
uint32_t WorldWeaver::GFX::GFXHelper::GetFragmentShader() const
{
    return m_FragmentShader;
}

/**************************************************************************************************/
/**
 * \par Details: 
 */
uint32_t WorldWeaver::GFX::GFXHelper::GetShaderProgram() const
{
    return m_ShaderProgram;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */