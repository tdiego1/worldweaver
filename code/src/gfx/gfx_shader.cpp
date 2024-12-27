/**************************************************************************************************/
/**
* \addtogroup GFX_SHADER
* @{
* \details
* This file provides the public interface for the GFX_SHADER Module.
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

#include "gfx/shader/gfx_shader.hpp"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>

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
bool GFX::Util::Shader::Load(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
{
    std::ifstream is_vs(vertexShaderFile);
    const std::string f_vs((std::istreambuf_iterator<char>(is_vs)), std::istreambuf_iterator<char>());

    std::ifstream is_fs(fragmentShaderFile);
    const std::string f_fs((std::istreambuf_iterator<char>(is_fs)), std::istreambuf_iterator<char>());

    m_ProgramID = glCreateProgram();

    uint32_t vs = GetCompiledShader(GL_VERTEX_SHADER, f_vs);
    uint32_t fs = GetCompiledShader(GL_FRAGMENT_SHADER, f_fs);

    glAttachShader(m_ProgramID, vs);
    glAttachShader(m_ProgramID, fs);

    glLinkProgram(m_ProgramID);
    glValidateProgram(m_ProgramID);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return true;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::Use(void)
{
    glUseProgram(m_ProgramID);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::Unload(void)
{
    glDeleteProgram(m_ProgramID);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
uint32_t GFX::Util::Shader::GetProgramID(void) const
{
    return m_ProgramID;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetMatrix4(const glm::mat4& matrix, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glUniformMatrix4fv(my_location, 1, GL_FALSE, glm::value_ptr(matrix));
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetInt1(int32_t value, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glUniform1i(my_location, value);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetFloat1(float32_t value, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glUniform1f(my_location, value);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetFloat3(float32_t a, float32_t b, float32_t c, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glUniform3f(my_location, a, b, c);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetVector3(const glm::vec3& vector, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glProgramUniform3fv(GetProgramID(), my_location, 1, glm::value_ptr(vector));
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Util::Shader::SetVector4(const glm::vec4& vector, const std::string& name)
{
    GLint my_location = glGetUniformLocation(GetProgramID(), name.c_str());
    glProgramUniform4fv(GetProgramID(), my_location, 1, glm::value_ptr(vector));
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
uint32_t GFX::Util::Shader::GetCompiledShader(uint32_t type, std::string source)
{
    uint32_t shader_id = glCreateShader(type);

    const char* c_source = source.c_str();
    glShaderSource(shader_id, 1, &c_source, nullptr);
    glCompileShader(shader_id);

    GLint result;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);

        GLchar* strInfoLog = new GLchar[length + 1];
        glGetShaderInfoLog(shader_id, length, &length, strInfoLog);

        fprintf(stderr, "Compile error in shader: %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    return shader_id;
}

/** @} */