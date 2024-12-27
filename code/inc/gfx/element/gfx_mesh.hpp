/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Mesh Module.
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

#ifndef GFX_ELEMENT_MESH_HPP
#define GFX_ELEMENT_MESH_HPP

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <memory>

#include "gfx/element/gfx_element.hpp"
#include "gfx/element/gfx_vertex.hpp"
#include "gfx/shader/gfx_shader.hpp"
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
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Mesh : public Element
        {

        public:
            /*********************************/
            // Public type definitions
            /*********************************/

            /*********************************/
            // Public member variables
            /*********************************/

            glm::vec3 m_Color;
            float m_Roughness;
            float m_Metallic;

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the Mesh.
            */
            Mesh(void) = default;

            /**************************************************************************************************/
            /**
            * \brief The default destructor for the Mesh.
            */
            virtual ~Mesh(void);

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
            bool Load(const std::string& path);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void AddVertex(const Vertex& vertex);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void AddIndex(uint32_t index);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            std::vector<uint32_t> GetIndices(void) const;

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
            void Initialize(void);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void CreateBuffers(void);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void DeleteBuffers(void);
            
            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void Render(void);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void Bind(void);

            /**************************************************************************************************/
            /**
            * \brief 
            * 
            * \param[in] 
            * 
            * \retval 
            */
            void UnBind(void);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            std::unique_ptr<GFX::Render::VertexIndexBuffer> m_RenderBufferManager;   // The Render Buffer Manager.
            std::vector<Vertex> m_Vertices;   // The vertices of the mesh.
            std::vector<uint32_t> m_Indices;  // The indices of the mesh.


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

#endif
/** @} */