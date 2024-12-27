/**************************************************************************************************/
/**
* \addtogroup GFX_SHADER
* @{
* \details
* This file provides the public interface for the Shader Module.
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
    namespace Util
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Shader
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the Shader.
            */
            Shader(void) = default;

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Loads the vertex and fragment shaders from a file.
            * 
            * \param[in] vertexShaderFile   The file path of the vertex shader.
            * \param[in] fragmentShaderFile The file path of the fragment shader.
            * 
            * \retval True if the shaders were loaded successfully.
            * \retval False if the shaders were not loaded successfully.
            */
            bool Load(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

            /**************************************************************************************************/
            /**
            * \brief Uses the shader program.
            */
            void Use(void);

            /**************************************************************************************************/
            /**
            * \brief Unloads the shader program.
            */
            void Unload(void);

            /**************************************************************************************************/
            /**
            * \brief Gets the shader program ID.
            * 
            * \retval uint32_t The shader program ID.
            */
            uint32_t GetProgramID(void) const;

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL matrix 4.
            * 
            * \param[in] matrix The matrix to set.
            * \param[in] name   The name of the matrix variable in the shader program.
            */
            void SetMatrix4(const glm::mat4& matrix, const std::string& name);

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL integer 1.
            * 
            * \param[in] value The value to set.
            * \param[in] name  The name of the integer variable in the shader program.
            */
            void SetInt1(int32_t value, const std::string& name);

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL float32_t 1.
            * 
            * \param[in] value The value to set.
            * \param[in] name  The name of the float32_t variable in the shader program.
            */
            void SetFloat1(float32_t value, const std::string& name);

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL float32_t 3.
            * 
            * \param[in] a     The x value to set.
            * \param[in] b     The y value to set.
            * \param[in] c     The z value to set.
            * \param[in] name  The name of the float32_t variable in the shader program.
            */
            void SetFloat3(float32_t a, float32_t b, float32_t c, const std::string& name);

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL vector 3.
            * 
            * \param[in] vector The vector to set.
            * \param[in] name   The name of the vector variable in the shader program.
            */
            void SetVector3(const glm::vec3& vector, const std::string& name);

            /**************************************************************************************************/
            /**
            * \brief Sets a OpenGL vector 4.
            * 
            * \param[in] vector The vector to set.
            * \param[in] name   The name of the vector variable in the shader program.
            */
            void SetVector4(const glm::vec4& vector, const std::string& name);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            uint32_t m_ProgramID;   // The program ID of the shader.

            /*********************************/
            // Private functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Gets the compiled shader.
            * 
            * \param[in] type   The type of shader.
            * \param[in] source The source of the shader.
            * 
            * \retval uint32_t The compiled shader ID.
            */
            uint32_t GetCompiledShader(uint32_t type, std::string source);

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