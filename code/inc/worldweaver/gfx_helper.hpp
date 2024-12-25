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

#ifndef Module_Id_HPP
#define Module_Id_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <string>
#include <stdint.h>

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
    namespace GFX
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class GFXHelper
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
            * \brief The default constructor for the <ExampleClass>.
            */
            GFXHelper(void);

            /**************************************************************************************************/
            /**
            * \brief The defaiult destructor for the <ExampleClass>.
            */
            ~GFXHelper(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Initializes the GFX_Helper module.
            */
            void GFXHelperInit(void);

            /**************************************************************************************************/
            /**
            * \brief Sets up a shader program.
            * 
            * \param[in] shaderSource The shader source code.
            */
            void SetupShader(std::string shaderSource);

            /**************************************************************************************************/
            /**
            * \brief Compiles the shader program.
            */
            void CompileShaderProgram();

            /**************************************************************************************************/
            /**
            * \brief Gets the shader program object ID.
            * 
            * \retval uint32_t The shader program object ID.
            */
            uint32_t GetVertexShader() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the fragment shader object ID.
             * 
             * \retval uint32_t The fragment shader object ID.
             */
            uint32_t GetFragmentShader() const;

            /**************************************************************************************************/
            /**
             * \brief Gets the shader program object ID.
             * 
             * \retval uint32_t The shader program object ID.
             */
            uint32_t GetShaderProgram() const;

        private:
            /*********************************/
            // Private type definitions
            /*********************************/

            /*********************************/
            // Private member variables
            /*********************************/
            
            uint32_t m_VertexShader;   // Vertex shader object ID.
            uint32_t m_FragmentShader; // Fragment shader object ID.
            uint32_t m_ShaderProgram;  // Shader program object ID.

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
namespace WorldWeaver
{
    namespace GFX
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline GFXHelper::~GFXHelper(){}
    }
}

#endif
/** @} */